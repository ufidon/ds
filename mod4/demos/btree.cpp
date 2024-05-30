#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

template <typename T, int t>
class BTree
{
  struct Node
  {
    bool leaf;
    std::vector<T> keys;
    std::vector<Node *> children;

    Node(bool isLeaf) : leaf(isLeaf) {}

    bool isFull() const
    {
      return keys.size() == 2 * t - 1;
    }

    bool isUnderflow() const
    {
      return keys.size() < t - 1;
    }

    void insertKey(const T &key)
    {
      keys.insert(std::upper_bound(keys.begin(), keys.end(), key), key);
    }

    void removeKey(const T &key)
    {
      auto it = std::find(keys.begin(), keys.end(), key);
      if (it != keys.end())
      {
        keys.erase(it);
      }
    }
  };

  Node *root;

  void splitChild(Node *parent, int i)
  {
    Node *fullChild = parent->children[i];
    Node *newChild = new Node(fullChild->leaf);
    newChild->keys.assign(fullChild->keys.begin() + t, fullChild->keys.end());
    fullChild->keys.resize(t - 1);

    if (!fullChild->leaf)
    {
      newChild->children.assign(fullChild->children.begin() + t, fullChild->children.end());
      fullChild->children.resize(t);
    }

    parent->children.insert(parent->children.begin() + i + 1, newChild);
    parent->keys.insert(parent->keys.begin() + i, fullChild->keys[t - 1]);
  }

  void insertNonFull(Node *node, const T &key)
  {
    if (node->leaf)
    {
      node->insertKey(key);
    }
    else
    {
      int i = node->keys.size() - 1;
      while (i >= 0 && key < node->keys[i])
      {
        i--;
      }
      i++;
      if (node->children[i]->isFull())
      {
        splitChild(node, i);
        if (key > node->keys[i])
        {
          i++;
        }
      }
      insertNonFull(node->children[i], key);
    }
  }

  Node *findMin(Node *node)
  {
    while (!node->leaf)
    {
      node = node->children.front();
    }
    return node;
  }

  void merge(Node *parent, int idx)
  {
    Node *child = parent->children[idx];
    Node *sibling = parent->children[idx + 1];

    child->keys.push_back(parent->keys[idx]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());

    if (!child->leaf)
    {
      child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
    }

    parent->keys.erase(parent->keys.begin() + idx);
    parent->children.erase(parent->children.begin() + idx + 1);

    delete sibling;
  }

  void fill(Node *node, int idx)
  {
    if (idx != 0 && node->children[idx - 1]->keys.size() >= t)
    {
      borrowFromPrev(node, idx);
    }
    else if (idx != node->keys.size() && node->children[idx + 1]->keys.size() >= t)
    {
      borrowFromNext(node, idx);
    }
    else
    {
      if (idx != node->keys.size())
      {
        merge(node, idx);
      }
      else
      {
        merge(node, idx - 1);
      }
    }
  }

  void borrowFromPrev(Node *node, int idx)
  {
    Node *child = node->children[idx];
    Node *sibling = node->children[idx - 1];

    child->keys.insert(child->keys.begin(), node->keys[idx - 1]);
    if (!child->leaf)
    {
      child->children.insert(child->children.begin(), sibling->children.back());
      sibling->children.pop_back();
    }
    node->keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();
  }

  void borrowFromNext(Node *node, int idx)
  {
    Node *child = node->children[idx];
    Node *sibling = node->children[idx + 1];

    child->keys.push_back(node->keys[idx]);
    if (!child->leaf)
    {
      child->children.push_back(sibling->children.front());
      sibling->children.erase(sibling->children.begin());
    }
    node->keys[idx] = sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());
  }

  void removeFromLeaf(Node *node, int idx)
  {
    node->keys.erase(node->keys.begin() + idx);
  }

  void removeFromNonLeaf(Node *node, int idx)
  {
    T key = node->keys[idx];

    if (node->children[idx]->keys.size() >= t)
    {
      Node *predNode = node->children[idx];
      while (!predNode->leaf)
      {
        predNode = predNode->children.back();
      }
      T pred = predNode->keys.back();
      node->keys[idx] = pred;
      remove(node->children[idx], pred);
    }
    else if (node->children[idx + 1]->keys.size() >= t)
    {
      Node *succNode = node->children[idx + 1];
      while (!succNode->leaf)
      {
        succNode = succNode->children.front();
      }
      T succ = succNode->keys.front();
      node->keys[idx] = succ;
      remove(node->children[idx + 1], succ);
    }
    else
    {
      merge(node, idx);
      remove(node->children[idx], key);
    }
  }

  void remove(Node *node, const T &key)
  {
    int idx = std::lower_bound(node->keys.begin(), node->keys.end(), key) - node->keys.begin();

    if (idx < node->keys.size() && node->keys[idx] == key)
    {
      if (node->leaf)
      {
        removeFromLeaf(node, idx);
      }
      else
      {
        removeFromNonLeaf(node, idx);
      }
    }
    else
    {
      if (node->leaf)
      {
        return;
      }

      bool flag = (idx == node->keys.size());

      if (node->children[idx]->keys.size() < t)
      {
        fill(node, idx);
      }

      if (flag && idx > node->keys.size())
      {
        remove(node->children[idx - 1], key);
      }
      else
      {
        remove(node->children[idx], key);
      }
    }
  }

  void inOrderTraversal(Node *node) const
  {
    if (node == nullptr)
      return;
    for (size_t i = 0; i < node->keys.size(); ++i)
    {
      if (!node->leaf)
      {
        inOrderTraversal(node->children[i]);
      }
      std::cout << node->keys[i] << " ";
    }
    if (!node->leaf)
    {
      inOrderTraversal(node->children[node->keys.size()]);
    }
  }

  void preOrderTraversal(Node *node) const
  {
    if (node == nullptr)
      return;
    for (const auto &key : node->keys)
    {
      std::cout << key << " ";
    }
    for (auto *child : node->children)
    {
      preOrderTraversal(child);
    }
  }

  void postOrderTraversal(Node *node) const
  {
    if (node == nullptr)
      return;
    for (auto *child : node->children)
    {
      postOrderTraversal(child);
    }
    for (const auto &key : node->keys)
    {
      std::cout << key << " ";
    }
  }


public:
  BTree() : root(new Node(true)) {}

  void insert(const T &key)
  {
    if (root->isFull())
    {
      Node *newRoot = new Node(false);
      newRoot->children.push_back(root);
      splitChild(newRoot, 0);
      root = newRoot;
    }
    insertNonFull(root, key);
  }

  void remove(const T &key)
  {
    remove(root, key);

    if (root->keys.empty())
    {
      Node *temp = root;
      if (!root->leaf)
      {
        root = root->children[0];
      }
      else
      {
        root = nullptr;
      }
      delete temp;
    }
  }

  bool search(Node *node, const T &key) const
  {
    if (node == nullptr)
      return false;
    auto it = std::lower_bound(node->keys.begin(), node->keys.end(), key);
    if (it != node->keys.end() && *it == key)
    {
      return true;
    }
    if (node->leaf)
    {
      return false;
    }
    return search(node->children[it - node->keys.begin()], key);
  }

  bool search(const T &key) const
  {
    return search(root, key);
  }

  void inOrderTraversal() const
  {
    inOrderTraversal(root);
    std::cout << std::endl;
  }

  void preOrderTraversal() const
  {
    preOrderTraversal(root);
    std::cout << std::endl;
  }

  void postOrderTraversal() const
  {
    postOrderTraversal(root);
    std::cout << std::endl;
  }

  void levelOrderTraversal() const
  {
    if (root == nullptr)
      return;
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      Node *node = q.front();
      q.pop();
      for (const auto &key : node->keys)
      {
        std::cout << key << " ";
      }
      for (auto *child : node->children)
      {
        q.push(child);
      }
    }
    std::cout << std::endl;
  }
};

int main()
{
  BTree<int, 3> btree;

  btree.insert(10);
  btree.insert(20);
  btree.insert(5);
  btree.insert(6);
  btree.insert(12);
  btree.insert(30);
  btree.insert(7);
  btree.insert(17);

  std::cout << "In-order traversal: ";
  btree.inOrderTraversal();

  std::cout << "Pre-order traversal: ";
  btree.preOrderTraversal();

  std::cout << "Post-order traversal: ";
  btree.postOrderTraversal();

  std::cout << "Level-order traversal: ";
  btree.levelOrderTraversal();

  btree.remove(6);
  std::cout << "In-order traversal after removing 6: ";
  btree.inOrderTraversal();

  btree.remove(13);
  std::cout << "In-order traversal after removing 13: ";
  btree.inOrderTraversal();

  btree.remove(7);
  std::cout << "In-order traversal after removing 7: ";
  btree.inOrderTraversal();

  btree.remove(4);
  std::cout << "In-order traversal after removing 4: ";
  btree.inOrderTraversal();

  btree.remove(2);
  std::cout << "In-order traversal after removing 2: ";
  btree.inOrderTraversal();

  btree.remove(16);
  std::cout << "In-order traversal after removing 16: ";
  btree.inOrderTraversal();

  return 0;
}
