#include <iostream>
#include <queue>

template <typename T>
class RedBlackTree
{
  enum Color
  {
    RED,
    BLACK
  };

  struct Node
  {
    T data;
    Color color;
    Node *left, *right, *parent;

    Node(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node *root;

  void rotateLeft(Node *&root, Node *&pt)
  {
    Node *pt_right = pt->right;
    pt->right = pt_right->left;

    if (pt->right != nullptr)
      pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
      root = pt_right;
    else if (pt == pt->parent->left)
      pt->parent->left = pt_right;
    else
      pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
  }

  void rotateRight(Node *&root, Node *&pt)
  {
    Node *pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != nullptr)
      pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
      root = pt_left;
    else if (pt == pt->parent->left)
      pt->parent->left = pt_left;
    else
      pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
  }

  void fixInsert(Node *&root, Node *&pt)
  {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
    {
      parent_pt = pt->parent;
      grand_parent_pt = pt->parent->parent;

      if (parent_pt == grand_parent_pt->left)
      {
        Node *uncle_pt = grand_parent_pt->right;

        if (uncle_pt != nullptr && uncle_pt->color == RED)
        {
          grand_parent_pt->color = RED;
          parent_pt->color = BLACK;
          uncle_pt->color = BLACK;
          pt = grand_parent_pt;
        }
        else
        {
          if (pt == parent_pt->right)
          {
            rotateLeft(root, parent_pt);
            pt = parent_pt;
            parent_pt = pt->parent;
          }
          rotateRight(root, grand_parent_pt);
          std::swap(parent_pt->color, grand_parent_pt->color);
          pt = parent_pt;
        }
      }
      else
      {
        Node *uncle_pt = grand_parent_pt->left;

        if (uncle_pt != nullptr && uncle_pt->color == RED)
        {
          grand_parent_pt->color = RED;
          parent_pt->color = BLACK;
          uncle_pt->color = BLACK;
          pt = grand_parent_pt;
        }
        else
        {
          if (pt == parent_pt->left)
          {
            rotateRight(root, parent_pt);
            pt = parent_pt;
            parent_pt = pt->parent;
          }
          rotateLeft(root, grand_parent_pt);
          std::swap(parent_pt->color, grand_parent_pt->color);
          pt = parent_pt;
        }
      }
    }

    root->color = BLACK;
  }

  void fixDelete(Node *&root, Node *&pt)
  {
    if (pt == nullptr)
      return;

    if (pt == root)
    {
      root = nullptr;
      return;
    }

    if (pt->color == RED || (pt->left != nullptr && pt->left->color == RED) || (pt->right != nullptr && pt->right->color == RED))
    {
      Node *child = pt->left != nullptr ? pt->left : pt->right;

      if (pt == pt->parent->left)
      {
        pt->parent->left = child;
        if (child != nullptr)
          child->parent = pt->parent;
        child->color = BLACK;
        delete pt;
      }
      else
      {
        pt->parent->right = child;
        if (child != nullptr)
          child->parent = pt->parent;
        child->color = BLACK;
        delete pt;
      }
    }
    else
    {
      Node *sibling = nullptr;
      Node *parent = nullptr;
      Node *ptr = pt;
      ptr->color = BLACK;

      while (ptr != root && ptr->color == BLACK)
      {
        parent = ptr->parent;
        if (ptr == parent->left)
        {
          sibling = parent->right;

          if (sibling->color == RED)
          {
            sibling->color = BLACK;
            parent->color = RED;
            rotateLeft(root, parent);
          }
          else
          {
            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK))
            {
              sibling->color = RED;
              if (parent->color == RED)
                parent->color = BLACK;
              else
                parent->color = BLACK;
              ptr = parent;
            }
            else
            {
              if (sibling->right == nullptr || sibling->right->color == BLACK)
              {
                sibling->left->color = BLACK;
                sibling->color = RED;
                rotateRight(root, sibling);
                sibling = parent->right;
              }

              sibling->color = parent->color;
              parent->color = BLACK;
              if (sibling->right != nullptr)
                sibling->right->color = BLACK;
              rotateLeft(root, parent);
              break;
            }
          }
        }
        else
        {
          sibling = parent->left;

          if (sibling->color == RED)
          {
            sibling->color = BLACK;
            parent->color = RED;
            rotateRight(root, parent);
          }
          else
          {
            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK))
            {
              sibling->color = RED;
              if (parent->color == RED)
                parent->color = BLACK;
              else
                parent->color = BLACK;
              ptr = parent;
            }
            else
            {
              if (sibling->left == nullptr || sibling->left->color == BLACK)
              {
                sibling->right->color = BLACK;
                sibling->color = RED;
                rotateLeft(root, sibling);
                sibling = parent->left;
              }

              sibling->color = parent->color;
              parent->color = BLACK;
              if (sibling->left != nullptr)
                sibling->left->color = BLACK;
              rotateRight(root, parent);
              break;
            }
          }
        }
      }

      if (pt == pt->parent->left)
        pt->parent->left = nullptr;
      else
        pt->parent->right = nullptr;
      delete pt;
      root->color = BLACK;
    }
  }

  void inorderHelper(Node *root) const
  {
    if (root == nullptr)
      return;

    inorderHelper(root->left);
    std::cout << root->data << "(" << root->color << ")" << " ";
    inorderHelper(root->right);
  }

  void preorderHelper(Node *root) const
  {
    if (root == nullptr)
      return;

    std::cout << root->data << "(" << root->color << ")" << " ";
    preorderHelper(root->left);
    preorderHelper(root->right);
  }

  void postorderHelper(Node *root) const
  {
    if (root == nullptr)
      return;

    postorderHelper(root->left);
    postorderHelper(root->right);
    std::cout << root->data << "(" << root->color << ")" << " ";
  }

  void levelOrderHelper(Node *root) const
  {
    if (root == nullptr)
      return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      Node *temp = q.front();
      std::cout << temp->data << "(" << temp->color << ")" << " ";
      q.pop();

      if (temp->left != nullptr)
        q.push(temp->left);

      if (temp->right != nullptr)
        q.push(temp->right);
    }
  }

public:
  RedBlackTree() : root(nullptr) {}

  void insert(const T &data)
  {
    Node *node = new Node(data);
    root = bstInsert(root, node);
    fixInsert(root, node);
  }

  void remove(const T &data)
  {
    Node *node = bstSearch(root, data);
    if (node != nullptr)
    {
      fixDelete(root, node);
    }
  }

  Node *bstInsert(Node *root, Node *pt)
  {
    if (root == nullptr)
      return pt;

    if (pt->data < root->data)
    {
      root->left = bstInsert(root->left, pt);
      root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
      root->right = bstInsert(root->right, pt);
      root->right->parent = root;
    }

    return root;
  }

  Node *bstSearch(Node *root, const T &data) const
  {
    if (root == nullptr || root->data == data)
      return root;

    if (data < root->data)
      return bstSearch(root->left, data);

    return bstSearch(root->right, data);
  }

  bool search(const T &data) const
  {
    return bstSearch(root, data) != nullptr;
  }

  void inorder() const
  {
    inorderHelper(root);
    std::cout << std::endl;
  }

  void preorder() const
  {
    preorderHelper(root);
    std::cout << std::endl;
  }

  void postorder() const
  {
    postorderHelper(root);
    std::cout << std::endl;
  }

  void levelOrder() const
  {
    levelOrderHelper(root);
    std::cout << std::endl;
  }
};

int main()
{
  RedBlackTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  std::cout << "In-order traversal: ";
  tree.inorder();

  std::cout << "Pre-order traversal: ";
  tree.preorder();

  std::cout << "Post-order traversal: ";
  tree.postorder();

  std::cout << "Level-order traversal: ";
  tree.levelOrder();

  tree.remove(40);
  std::cout << "In-order traversal after deleting 40: ";
  tree.inorder();

  return 0;
}
