# [Trees](https://en.wikipedia.org/wiki/Tree_(data_structure))

💡 Intuition
---
<img src="./images/tree.svg">


Terms about trees
---
<table border="1">
  <tr>
    <th>Concept</th>
    <th>Description</th>
    <th>Example</th>
  </tr>
  <tr>
    <td>Root</td>
    <td>The topmost node in a tree, without parents.</td>
    <td>In a family tree, the earliest ancestor.</td>
  </tr>
  <tr>
    <td>Leaf</td>
    <td>A node with no children.</td>
    <td>In a file system, a file without subdirectories.</td>
  </tr>
  <tr>
    <td>Non-leaf</td>
    <td>A node with at least one children.</td>
    <td>In a file system, a file without subdirectories.</td>
  </tr>  
  <tr>
    <td>Edge</td>
    <td>The connection between one node and another.</td>
    <td>The link from a parent node to a child node.</td>
  </tr>
  <tr>
    <td>Child</td>
    <td>A node directly connected to another node when moving away from the Root.</td>
    <td>In a company hierarchy, an employee directly under a manager.</td>
  </tr>
  <tr>
    <td>Parent</td>
    <td>A node directly connected to another node when moving towards the Root.</td>
    <td>In a company hierarchy, the manager of an employee.</td>
  </tr>
  <tr>
    <td>Sibling</td>
    <td>Nodes that share the same Parent.</td>
    <td>In a family tree, brothers and sisters.</td>
  </tr>
    <tr>
    <td>Neighbor</td>
    <td>Adjacent nodes connected directly by an edge.</td>
    <td>In a network topology, two nodes connected by a single network cable.</td>
  </tr>
  <tr>
    <td>Ancestor</td>
    <td>Any predecessor node on the path from the node to the root.</td>
    <td>In a family tree, all the forefathers of a person.</td>
  </tr>
  <tr>
    <td>Descendant</td>
    <td>Any successor node on the path from the node to any leaf.</td>
    <td>In a family tree, all the offspring of a person.</td>
  </tr>
  <tr>
    <td>Subtree</td>
    <td>A tree entirely contained within another tree.</td>
    <td>A department within a larger company's organizational chart.</td>
  </tr>
  <td>Degree of Node</td>
    <td>The number of children of a node.</td>
    <td>In a binary tree, each node has a degree of at most 2.</td>
  </tr>
  <tr>
    <td>Degree of Tree</td>
    <td>The maximum degree of any node in the tree.</td>
    <td>In a binary tree, the degree of the tree is 2.</td>
  </tr>
  <tr>
    <td>Width</td>
    <td>The maximum number of nodes at any level in the tree.</td>
    <td>The number of departments on a particular floor of a company.</td>
  </tr>
  <tr>
    <td>Breadth</td>
    <td>The total number of leaf nodes in the tree.</td>
    <td>The total number of end-points in a network topology.</td>
  </tr>
  <tr>
    <td>Size</td>
    <td>The total number of nodes in the tree.</td>
    <td>The total number of employees in a company.</td>
  </tr>  
  <tr>
    <td>Path</td>
    <td>A sequence of nodes and edges connecting a node with a descendant, where each adjacent pair of nodes is connected by an edge.</td>
    <td>For example, in a binary tree, the path from the root node to a leaf node might be Root -> A -> B -> Leaf.</td>
  </tr>
  <tr>
    <td>Path Length</td>
    <td>The number of edges in a path.</td>
    <td>If the path is Root -> A -> B -> Leaf, the path length is 3.</td>
  </tr>  
  <tr>
    <td>Depth</td>
    <td>The number of edges from the Root to the node.</td>
    <td>The number of generations from the earliest ancestor to a descendant in a family tree.</td>
  </tr>
  <tr>
    <td>Height</td>
    <td>The number of edges on the longest path from the node to a leaf.</td>
    <td>The number of levels of management from a manager down to the lowest employee.</td>
  </tr>
  <tr>
  <tr>
    <td>Distance</td>
    <td>The number of edges in the shortest path between two nodes.</td>
    <td>The distance between two cousins in a family tree.</td>
  </tr>
  <tr>
    <td>Level</td>
    <td>The number of edges from the root to the node.</td>
    <td>The level of a manager in a company's organizational structure.</td>
  </tr>
</table>





# [Binary Trees (BTs)](https://en.wikipedia.org/wiki/Binary_tree)

| Type | Definition | Properties | Remarks |
|---|---|---|---|
| Binary Tree | A tree data structure in which `each node can have at most two child nodes` | ▶️ Each node can have `at most two child nodes` (`left` child and `right` child) | ▶️ The `most basic` tree structure |
| `Full` Binary Tree | A binary tree in which `every node has exactly zero or two child nodes` | ▶️ All non-leaf nodes have two child nodes  | ▶️ Often used to implement heap data structures |
| `Complete` Binary Tree | A binary tree in which <br>▶️every level is `completely filled` except possibly the last level<br>▶️ the last level must be filled from left to right | ▶️ All levels except the last one should be completely filled <br>▶️ Leaf nodes in the last level should be as leftmost as possible |  ▶️ Often used in some searching algorithms |
| `Perfect` Binary Tree | A binary tree that is both a `full` binary tree and a `complete` binary tree | ▶️ All non-leaf nodes have two child nodes <br>▶️ All leaf nodes are on the same level | ▶️ A special type of full binary tree |
| `Balanced` Binary Tree | A binary tree in which `the height of the left subtree and the right subtree differ by at most 1` | ▶️ Left and right subtrees have approximately equal height |  ▶️ Search, insert, and delete operations are efficient $Θ(\log n)$ |
| `Degenerate` Binary Tree | ▶️ A binary tree in which each node has `zero or one` child node<br>▶️ or a binary tree with `a large difference in height` between the left and right subtrees | ▶️  the worst case becomes a `linked list` <br>▶️ or has a very large difference in height between the left and right subtrees | ▶️ Search, insert, and delete operations are inefficient $Θ(n)$ |


# [Binary tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)

| Traversal Method | Definition | Complexity | Data Structures | Applications |
|---|---|---|---|---|
| **In-order traversal** | Visits the left subtree, then the root node, and then the right subtree. | O(n) time, O(n) space | Stack | Printing a tree in sorted order, traversing an expression tree |
| **Pre-order traversal** | Visits the root node, then the left subtree, and then the right subtree. | O(n) time, O(n) space | Stack | Copying a tree, creating a prefix expression |
| **Post-order traversal** | Visits the left subtree, then the right subtree, and then the root node. | O(n) time, O(n) space | Stack | Destroying a tree, creating a postfix expression |
| **Level-order traversal** | Visits all nodes at the same level from left to right, before moving to the next level. | O(n) time, O(n) space | Queue | Checking if a tree is balanced, printing nodes at each level |


💡 Example
---
Traverse the binary tree below:

```
    A
   / \
  B   C
 / \   \
D   E   F
```
* **In-order traversal:** D B E A C F
* **Pre-order traversal:** A B D E C F
* **Post-order traversal:** D E B F C A
* **Level-order traversal:** A B C D E F

🏃 Recursive implementation of IPP
---
- Pseudo code

```c++
procedure inorder(node)
    if node = null
        return
    inorder(node.left)
    visit(node)
    inorder(node.right)

procedure preorder(node)
    if node = null
        return
    visit(node)
    preorder(node.left)
    preorder(node.right)

procedure postorder(node)
    if node = null
        return
    postorder(node.left)
    postorder(node.right)
    visit(node)    
```

- Implementation in C++

```c++
#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
  T data;
  Node<T> *left;
  Node<T> *right;

  Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
public:
  Node<T> *root;

  BinaryTree() : root(nullptr) {}

  // In-order traversal
  void inOrder(Node<T> *tree)
  {
    if (tree == nullptr)
    {
      return;
    }

    inOrder(tree->left);
    std::cout << tree->data << " ";
    inOrder(tree->right);
  }

  // Pre-order traversal
  void preOrder(Node<T> *tree)
  {
    if (tree == nullptr)
    {
      return;
    }

    std::cout << tree->data << " ";
    preOrder(tree->left);
    preOrder(tree->right);
  }

  // Post-order traversal
  void postOrder(Node<T> *tree)
  {
    if (tree == nullptr)
    {
      return;
    }

    postOrder(tree->left);
    postOrder(tree->right);
    std::cout << tree->data << " ";
  }

  // Level-order traversal
  void levelOrder(Node<T> *tree)
  {
    std::queue<Node<T> *> queue;
    queue.push(tree);

    while (!queue.empty())
    {
      Node<T> *current = queue.front();
      queue.pop();

      if (current != nullptr)
      {
        std::cout << current->data << " ";
        queue.push(current->left);
        queue.push(current->right);
      }
    }
  }
};

int main()
{
  BinaryTree<char> tree;

  tree.root = new Node<char>('A');
  tree.root->left = new Node<char>('B');
  tree.root->right = new Node<char>('C');
  tree.root->left->left = new Node<char>('D');
  tree.root->left->right = new Node<char>('E');
  tree.root->right->right = new Node<char>('F');

  std::cout << "In-order traversal: ";
  tree.inOrder(tree.root);
  std::cout << std::endl;

  std::cout << "Pre-order traversal: ";
  tree.preOrder(tree.root);
  std::cout << std::endl;

  std::cout << "Post-order traversal: ";
  tree.postOrder(tree.root);
  std::cout << std::endl;

  std::cout << "Level-order traversal: ";
  tree.levelOrder(tree.root);
  std::cout << std::endl;

  return 0;
}
```

🏃 Stack-based implementation of IPP
---
- Pseudo code

```c++
procedure iterativeInorder(node)
    stack ← empty stack
    while not stack.isEmpty() or node ≠ null
        if node ≠ null
            stack.push(node)
            node ← node.left
        else
            node ← stack.pop()
            visit(node)
            node ← node.right

procedure iterativePreorder(node)
    if node = null
        return
    stack ← empty stack
    stack.push(node)
    while not stack.isEmpty()
        node ← stack.pop()
        visit(node)
        // right child is pushed first so that left is processed first
        if node.right ≠ null
            stack.push(node.right)
        if node.left ≠ null
            stack.push(node.left)

procedure iterativePostorder(node)
    stack ← empty stack
    lastNodeVisited ← null
    while not stack.isEmpty() or node ≠ null
        if node ≠ null
            stack.push(node)
            node ← node.left
        else
            peekNode ← stack.peek()
            // if right child exists and traversing node
            // from left child, then move right
            if peekNode.right ≠ null and lastNodeVisited ≠ peekNode.right
                node ← peekNode.right
            else
                visit(peekNode)
                lastNodeVisited ← stack.pop()                       
```

- Implementation in C++

```c++
#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
template <typename T>
class Node
{
public:
  T val;
  Node *left;
  Node *right;
  Node(T x) : val(x), left(nullptr), right(nullptr) {}
};

// Binary Tree class that encapsulates traversal methods
template <typename T>
class BinaryTree
{
public:
  Node<T> *root;

  BinaryTree() : root(nullptr) {}
  // Function to visit a node (print its value here)
  void visit(Node<T> *node)
  {
    cout << node->val << " ";
  }

  // Iterative Inorder Traversal
  void iterativeInorder(Node<T> *root)
  {
    stack<Node<T> *> stack;
    Node<T> *node = root;

    while (!stack.empty() || node != nullptr)
    {
      if (node != nullptr)
      {
        stack.push(node);
        node = node->left;
      }
      else
      {
        node = stack.top();
        stack.pop();
        visit(node);
        node = node->right;
      }
    }
  }

  // Iterative Preorder Traversal
  void iterativePreorder(Node<T> *root)
  {
    if (root == nullptr)
      return;
    stack<Node<T> *> stack;
    stack.push(root);

    while (!stack.empty())
    {
      Node<T> *node = stack.top();
      stack.pop();
      visit(node);

      if (node->right != nullptr)
        stack.push(node->right);
      if (node->left != nullptr)
        stack.push(node->left);
    }
  }

  // Iterative Postorder Traversal
  void iterativePostorder(Node<T> *root)
  {
    stack<Node<T> *> stack;
    Node<T> *lastNodeVisited = nullptr;
    Node<T> *node = root;

    while (!stack.empty() || node != nullptr)
    {
      if (node != nullptr)
      {
        stack.push(node);
        node = node->left;
      }
      else
      {
        Node<T> *peekNode = stack.top();
        if (peekNode->right != nullptr && lastNodeVisited != peekNode->right)
        {
          node = peekNode->right;
        }
        else
        {
          visit(peekNode);
          lastNodeVisited = stack.top();
          stack.pop();
        }
      }
    }
  }
};

int main()
{
  BinaryTree<char> tree;

  tree.root = new Node<char>('A');
  tree.root->left = new Node<char>('B');
  tree.root->right = new Node<char>('C');
  tree.root->left->left = new Node<char>('D');
  tree.root->left->right = new Node<char>('E');
  tree.root->right->right = new Node<char>('F');

  std::cout << "In-order traversal: ";
  tree.iterativeInorder(tree.root);
  std::cout << std::endl;

  std::cout << "Pre-order traversal: ";
  tree.iterativePreorder(tree.root);
  std::cout << std::endl;

  std::cout << "Post-order traversal: ";
  tree.iterativePostorder(tree.root);
  std::cout << std::endl;

  return 0;
}
```

# [Binary Search Trees (BSTs)](https://en.wikipedia.org/wiki/Binary_search_tree)
- A binary tree in which for each node
  - all elements in its `left subtree` are `less` than the node
  - and all elements in its `right subtree` are `greater than` the node

<img src="./images/bst.svg" width="400" hspace="10"/> 

💡 Intuition
---
- [BST slow simulation](https://liveexample.pearsoncmg.com/dsanimation13ejava/BSTeBook.html)
- [BST fast simulation](https://cmps-people.ok.ubc.ca/ylucet/DS/BST.html)
- [BST speed-adjustable simulation](https://web.eecs.utk.edu/~czheng4/viz/animations/tree_structures/binary_search_tree/bst.html)


The insert, delete, and search operations in a BST
---
| Operation | Description | Time Complexity | Notes |
|-----------|-------------|-----------------|-------|
| **Search** | Looks for a node with a specific value. | Average: $O(\log n)$<br>Worst: $O(n)$ | Starts from the root and traverses left or right depending on whether the value is smaller or larger than the current node. |
| **Insert** | Inserts a new node with a specific value. The new node is always inserted at a leaf. | Average: $O(\log n)$<br>Worst: $O(n)$ | The tree starts from the root and the new node is inserted on the left if it's smaller than the current node, or on the right if it's larger. |
| **Delete** | Removes a node with a specific value. This can involve replacing the node with its `in-order successor or predecessor` if it has two children. | Average: $O(\log n)$<br>Worst: $O(n)$ | After deletion, the properties of the BST must be maintained. |



🍎 Implementation
---
```c++
#include <iostream>

// Define a Binary Search Tree (BST) class
template <typename T>
class BST
{
private:
  struct Node
  {
    T data;
    Node *left;
    Node *right;
    Node(const T &val) : data(val), left(nullptr), right(nullptr) {}
  };

  Node *root;

  // Helper function for inserting a new node
  Node *insertHelper(Node *node, const T &val)
  {
    if (!node)
    {
      return new Node(val);
    }
    if (val < node->data)
    {
      node->left = insertHelper(node->left, val);
    }
    else if (val > node->data)
    {
      node->right = insertHelper(node->right, val);
    }
    return node;
  }

  // Helper function for searching a value
  bool searchHelper(Node *node, const T &val) const
  {
    if (!node)
    {
      return false;
    }
    if (val == node->data)
    {
      return true;
    }
    else if (val < node->data)
    {
      return searchHelper(node->left, val);
    }
    else
    {
      return searchHelper(node->right, val);
    }
  }

  // Helper function to find the minimum value node
  Node *findMin(Node *node)
  {
    while (node->left)
    {
      node = node->left;
    }
    return node;
  }

  // Helper function for deleting a node
  Node *deleteHelper(Node *node, const T &val)
  {
    if (!node)
    {
      return nullptr;
    }
    if (val < node->data)
    {
      node->left = deleteHelper(node->left, val);
    }
    else if (val > node->data)
    {
      node->right = deleteHelper(node->right, val);
    }
    else
    {
      if (!node->left)
      {
        Node *temp = node->right;
        delete node;
        return temp;
      }
      else if (!node->right)
      {
        Node *temp = node->left;
        delete node;
        return temp;
      }
      Node *temp = findMin(node->right);
      node->data = temp->data;
      node->right = deleteHelper(node->right, temp->data);
    }
    return node;
  }

public:
  BST() : root(nullptr) {}

  // Public method to insert a value into the BST
  void insert(const T &val)
  {
    root = insertHelper(root, val);
  }

  // Public method to search for a value in the BST
  bool search(const T &val) const
  {
    return searchHelper(root, val);
  }

  // Public method to delete a value from the BST
  void remove(const T &val)
  {
    root = deleteHelper(root, val);
  }
};

int main()
{
  BST<int> bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);

  std::cout << "Search 10: " << (bst.search(10) ? "Found" : "Not found") << std::endl;
  std::cout << "Search 7: " << (bst.search(7) ? "Found" : "Not found") << std::endl;

  bst.remove(10);
  std::cout << "Search 10 after deletion: " << (bst.search(10) ? "Found" : "Not found") << std::endl;

  return 0;
}
```


# Tree traversal
| Criteria | Depth-First Traversal (DFT) | Breadth-First Traversal (BFT) |
| --- | --- | --- |
| **Traversal Strategy** | Explores as far as possible along each branch before backtracking. | Explores all the nodes at the present depth before moving to the next level. |
| **Data Structure** | Uses a stack, which can be implemented using recursion or iteration. | Uses a queue to visit nodes in the order they were discovered. |
| **Node Visit Order** | Visits nodes vertically down the tree paths before visiting sibling nodes. | Visits nodes horizontally across the tree levels. |
| **Implementation** | Can be implemented recursively, making it more succinct and easier to understand. | Typically implemented iteratively, requiring an explicit data structure to hold all the nodes at the current level. |
| **Space Complexity** | O(h), where h is the height of the tree. | O(w), where w is the maximum width of the tree. |
| **Time Complexity** | O(n), where n is the number of nodes in the tree. | O(n), where n is the number of nodes in the tree. |
| **Applications** | Useful for tasks that need to visit nodes in a path, like checking if a path exists between two nodes. | Useful for finding the shortest path or for level-order traversal. |


# References
- [Depth First Traversal: Inorder, Preorder and Postorder tree traversals - Animated guide](https://csanim.com/tutorials/inorder-preorder-and-postorder-tree-traversals-animated-guide)
- [Breadth-first search (BFS) of BST in Python - Visualization and Code](https://csanim.com/tutorials/breadth-first-search-python-visualization-and-code)

