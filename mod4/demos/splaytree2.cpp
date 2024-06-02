#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class SplayTree
{
private:
  struct Node
  {
    T key;
    Node *left;
    Node *right;

    Node(T k) : key(k), left(nullptr), right(nullptr) {}
  };

  Node *root;

  void rightRotate(Node *&x)
  {
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    x = y;
  }

  void leftRotate(Node *&x)
  {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x = y;
  }

  void splay(Node *&root, T key)
  {
    if (!root || root->key == key)
      return;

    if (root->key > key)
    {
      if (!root->left)
        return;

      if (root->left->key > key)
      {
        splay(root->left->left, key);
        rightRotate(root);
      }
      else if (root->left->key < key)
      {
        splay(root->left->right, key);
        if (root->left->right)
          leftRotate(root->left);
      }

      root->left ? rightRotate(root) : void();
    }
    else
    {
      if (!root->right)
        return;

      if (root->right->key > key)
      {
        splay(root->right->left, key);
        if (root->right->left)
          rightRotate(root->right);
      }
      else if (root->right->key < key)
      {
        splay(root->right->right, key);
        leftRotate(root);
      }

      root->right ? leftRotate(root) : void();
    }
  }

  void insert(Node *&node, T key)
  {
    if (!node)
    {
      node = new Node(key);
      return;
    }

    splay(node, key);

    if (node->key == key)
      return;

    Node *newNode = new Node(key);
    if (node->key > key)
    {
      newNode->right = node;
      newNode->left = node->left;
      node->left = nullptr;
    }
    else
    {
      newNode->left = node;
      newNode->right = node->right;
      node->right = nullptr;
    }

    node = newNode;
  }

  void deleteNode(Node *&node, T key)
  {
    if (!node)
      return;

    splay(node, key);

    if (node->key != key)
      return;

    if (!node->left)
    {
      Node *temp = node;
      node = node->right;
      delete temp;
    }
    else
    {
      Node *temp = node;
      splay(node->left, key);
      node->left->right = node->right;
      node = node->left;
      delete temp;
    }
  }

  Node *search(Node *node, T key)
  {
    splay(node, key);
    return (node && node->key == key) ? node : nullptr;
  }

  void inorder(Node *node) const
  {
    if (!node)
      return;
    inorder(node->left);
    std::cout << node->key << " ";
    inorder(node->right);
  }

  void preorder(Node *node) const
  {
    if (!node)
      return;
    std::cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
  }

  void postorder(Node *node) const
  {
    if (!node)
      return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->key << " ";
  }

  void levelOrder(Node *node) const
  {
    if (!node)
      return;
    std::queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
      Node *current = q.front();
      q.pop();
      std::cout << current->key << " ";
      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }
  }

public:
  SplayTree() : root(nullptr) {}

  void insert(T key)
  {
    insert(root, key);
  }

  void remove(T key)
  {
    deleteNode(root, key);
  }

  bool search(T key)
  {
    root = search(root, key);
    return root != nullptr && root->key == key;
  }

  void inorder() const
  {
    inorder(root);
    std::cout << std::endl;
  }

  void preorder() const
  {
    preorder(root);
    std::cout << std::endl;
  }

  void postorder() const
  {
    postorder(root);
    std::cout << std::endl;
  }

  void levelOrder() const
  {
    levelOrder(root);
    std::cout << std::endl;
  }
};

int main()
{
  SplayTree<int> tree;

  // Insert elements
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  // Traversals
  std::cout << "In-order traversal: ";
  tree.inorder();

  std::cout << "Pre-order traversal: ";
  tree.preorder();

  std::cout << "Post-order traversal: ";
  tree.postorder();

  std::cout << "Level-order traversal: ";
  tree.levelOrder();

  // Search
  std::cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << std::endl;

  // Delete
  tree.remove(20);
  std::cout << "After deleting 20, In-order traversal: ";
  tree.inorder();

  return 0;
}
