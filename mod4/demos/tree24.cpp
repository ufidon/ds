#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

template <typename T>
class TwoFourTree
{
  struct Node
  {
    std::vector<T> keys;
    std::vector<Node *> children;
    Node *parent;

    Node() : parent(nullptr) {}

    bool isLeaf() const
    {
      return children.empty();
    }

    bool isFull() const
    {
      return keys.size() == 3;
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

  void split(Node *node)
  {
    if (!node->isFull())
      return;

    T middleKey = node->keys[1];
    Node *newLeft = new Node();
    Node *newRight = new Node();

    newLeft->keys.push_back(node->keys[0]);
    newRight->keys.push_back(node->keys[2]);

    if (!node->isLeaf())
    {
      newLeft->children.push_back(node->children[0]);
      newLeft->children.push_back(node->children[1]);
      newRight->children.push_back(node->children[2]);
      newRight->children.push_back(node->children[3]);
      for (auto *child : newLeft->children)
      {
        child->parent = newLeft;
      }
      for (auto *child : newRight->children)
      {
        child->parent = newRight;
      }
    }

    if (node == root)
    {
      root = new Node();
      root->keys.push_back(middleKey);
      root->children.push_back(newLeft);
      root->children.push_back(newRight);
      newLeft->parent = root;
      newRight->parent = root;
    }
    else
    {
      Node *parent = node->parent;
      parent->insertKey(middleKey);
      parent->children.erase(std::find(parent->children.begin(), parent->children.end(), node));
      parent->children.push_back(newLeft);
      parent->children.push_back(newRight);
      std::sort(parent->children.begin(), parent->children.end(), [&](Node *a, Node *b)
                { return a->keys[0] < b->keys[0]; });
      newLeft->parent = parent;
      newRight->parent = parent;
    }
    delete node;
  }

  void insert(Node *node, const T &key)
  {
    if (node->isLeaf())
    {
      node->insertKey(key);
      split(node);
    }
    else
    {
      auto it = std::upper_bound(node->keys.begin(), node->keys.end(), key);
      insert(node->children[it - node->keys.begin()], key);
    }
  }


  void removeLeaf(Node *node, const T &key)
  {
    node->removeKey(key);
  }

  void removeInternal(Node *node, const T &key)
  {
    auto it = std::find(node->keys.begin(), node->keys.end(), key);
    Node *child = node->children[it - node->keys.begin()];
    if (child->keys.size() >= 2)
    {
      T predecessor = child->keys.back();
      remove(child, predecessor);
      node->keys[it - node->keys.begin()] = predecessor;
    }
    else
    {
      child = node->children[it - node->keys.begin() + 1];
      T successor = child->keys.front();
      remove(child, successor);
      node->keys[it - node->keys.begin()] = successor;
    }
  }

  void remove(Node *node, const T &key)
  {
    if (node->isLeaf())
    {
      removeLeaf(node, key);
    }
    else
    {
      removeInternal(node, key);
    }

    if (node == root && node->keys.empty())
    {
      if (node->children.size() > 0)
      {
        root = node->children[0];
        root->parent = nullptr;
        delete node;
      }
    }
  }

  void inOrderTraversal(Node *node) const
  {
    if (node == nullptr)
      return;
    for (size_t i = 0; i < node->keys.size(); ++i)
    {
      if (!node->isLeaf())
      {
        inOrderTraversal(node->children[i]);
      }
      std::cout << node->keys[i] << " ";
    }
    if (!node->isLeaf())
    {
      inOrderTraversal(node->children[node->keys.size()]);
    }
  }

public:
  TwoFourTree() : root(new Node()) {}

  void insert(const T &key)
  {
    insert(root, key);
  }

  void remove(const T &key)
  {
    remove(root, key);
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
    if (node->isLeaf())
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
  TwoFourTree<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  tree.insert(15);
  tree.insert(25);
  tree.insert(30);
  tree.insert(3);
  tree.insert(8);
  tree.insert(22);
  tree.insert(27);

  std::cout << "In-order Traversal: ";
  tree.inOrderTraversal();

  std::cout << "Level-order Traversal: ";
  tree.levelOrderTraversal();

  std::cout << "Searching for 22, found = " << tree.search(22) << std::endl;
  std::cout << "Searching for 23, found = " << tree.search(23) << std::endl;

  std::cout << "After deleting 20:" << std::endl;
  tree.remove(20);

  std::cout << "In-order Traversal: ";
  tree.inOrderTraversal();

  std::cout << "Level-order Traversal: ";
  tree.levelOrderTraversal();

  return 0;
}
