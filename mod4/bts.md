# [Trees](https://en.wikipedia.org/wiki/Tree_(data_structure))

💡 Intuition
---
<img src="./images/tree.svg">


- A tree consists of `nodes` and `edges`
- Unlike a natural tree, it is depicted `upside down` 
  - the `root` at the `top`
    - can have only child nodes but `no parent`
  - the `leaves` (terminal nodes) at the `bottom`
    - have no children
    - or their children are `EMPTY structures`
- The edges have arrows or not does not matter


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
| `Balanced` Binary Tree | A binary tree in which `the height of the left subtree and the right subtree differ by at most 1` | ▶️ Left and right subtrees have approximately equal height |  ▶️ Search, insert, and delete operations are efficient $𝚯(\log n)$ |
| `Degenerate` Binary Tree | ▶️ A binary tree in which each node has `zero or one` child node<br>▶️ or a binary tree with `a large difference in height` between the left and right subtrees | ▶️  the worst case becomes a `linked list` <br>▶️ or has a very large difference in height between the left and right subtrees | ▶️ Search, insert, and delete operations are inefficient $𝚯(n)$ |


# [Binary tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)

| Criteria | Depth-First Traversal (DFT) | Breadth-First Traversal (BFT) |
| --- | --- | --- |
| **Traversal Strategy** | Explores as far as possible along each branch before backtracking. | Explores all the nodes at the present depth before moving to the next level. |
| **Data Structure** | Uses a stack, which can be implemented using recursion or iteration. | Uses a queue to visit nodes in the order they were discovered. |
| **Node Visit Order** | Visits nodes vertically down the tree paths before visiting sibling nodes. | Visits nodes horizontally across the tree levels. |
| **Implementation** | Can be implemented recursively, making it more succinct and easier to understand. | Typically implemented iteratively, requiring an explicit data structure to hold all the nodes at the current level. |
| **Space Complexity** | 𝐎(h), where h is the height of the tree. | 𝐎(w), where w is the maximum width of the tree. |
| **Time Complexity** | 𝐎(n), where n is the number of nodes in the tree. | 𝐎(n), where n is the number of nodes in the tree. |
| **Applications** | Useful for tasks that need to visit nodes in a path, like checking if a path exists between two nodes. | Useful for finding the shortest path or for level-order traversal. |


Pre, in, post and level -order traversal
---
- DFT includes in-order traversal, pre-order traversal and post-order traversal
  - the three traversals are abbreviated as IPP
- BFT is also called level-order traversal

| Traversal Method | Definition | Complexity | Data Structures | Applications |
|---|---|---|---|---|
| **In-order traversal** | Visits the left subtree, then the root node, and then the right subtree. | 𝐎(n) time, 𝐎(n) space | Stack | Printing a tree in sorted order, traversing an expression tree |
| **Pre-order traversal** | Visits the root node, then the left subtree, and then the right subtree. | 𝐎(n) time, 𝐎(n) space | Stack | Copying a tree, creating a prefix expression |
| **Post-order traversal** | Visits the left subtree, then the right subtree, and then the root node. | 𝐎(n) time, 𝐎(n) space | Stack | Destroying a tree, creating a postfix expression |
| **Level-order traversal** | Visits all nodes at the same level from left to right, before moving to the next level. | 𝐎(n) time, 𝐎(n) space | Queue | Checking if a tree is balanced, printing nodes at each level |


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


💡 Intuition
---
- [BST simulation](https://csvistool.com/BST)


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
#include <string>

template <typename T>
class Node
{
public:
  T data; // many literatures use key for data
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

  void draw(std::string indent, Node<T> *tree, int what = 0)
  {
    if (tree)
    {
      char sign = ' ';
      if (what == 1) // left
        sign = '`';
      else if (what == 2) // right
        sign = ',';
      else
        sign = ' '; // root

      draw(indent + "   ", tree->right, 2);
      std::cout << indent + sign + "--" << tree->data << std::endl;
      draw(indent + "   ", tree->left, 1);
    }
  }

  void draw()
  {
    draw("", root);
    std::cout << std::endl;
  }
};

int main()
{
  BinaryTree<char> tree;

  tree.root = new Node<char>('A');
  tree.draw();
  tree.root->left = new Node<char>('B');
  tree.draw();
  tree.root->right = new Node<char>('C');
  tree.draw();
  tree.root->left->left = new Node<char>('D');
  tree.draw();
  tree.root->left->right = new Node<char>('E');
  tree.draw();
  tree.root->right->right = new Node<char>('F');
  tree.draw();

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
- [BST simulation](https://csvistool.com/BST)
- other simulators
  - [fast simulation](https://www.cs.usfca.edu/~galles/visualization/BST.html)
  - [slow simulation](https://liveexample.pearsoncmg.com/dsanimation13ejava/BSTeBook.html)
  - [adjustable simulation](https://web.eecs.utk.edu/~czheng4/viz/animations/tree_structures/binary_search_tree/bst.html)


BST traversal
---
- In-order traversal prints BST elements in `non-decreasing` order

```c++
#include <iostream>
using namespace std;

template <typename T>
class BST
{
private:
  struct Node
  {
    T data;
    Node *left;
    Node *right;
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
  };

  Node *root;

  void inorder(Node *node)
  {
    if (node != nullptr)
    {
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }
  }

  void preorder(Node *node)
  {
    if (node != nullptr)
    {
      cout << node->data << " ";
      preorder(node->left);
      preorder(node->right);
    }
  }

  void postorder(Node *node)
  {
    if (node != nullptr)
    {
      postorder(node->left);
      postorder(node->right);
      cout << node->data << " ";
    }
  }

public:
  BST() : root(nullptr) {}

  void insert(T data)
  {
    root = insert(data, root);
  }

  Node *insert(T data, Node *node)
  {
    if (node == nullptr)
    {
      return new Node(data);
    }
    if (data < node->data)
    {
      node->left = insert(data, node->left);
    }
    else if (data > node->data)
    {
      node->right = insert(data, node->right);
    }
    return node;
  }

  void displayInorder()
  {
    inorder(root);
    cout << endl;
  }

  void displayPreorder()
  {
    preorder(root);
    cout << endl;
  }

  void displayPostorder()
  {
    postorder(root);
    cout << endl;
  }
};

int main()
{
  BST<int> tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(10);
  tree.insert(1);
  tree.insert(6);
  tree.insert(14);
  tree.insert(4);
  tree.insert(7);
  tree.insert(13);

  cout << "Inorder traversal: ";
  tree.displayInorder();

  cout << "Preorder traversal: ";
  tree.displayPreorder();

  cout << "Postorder traversal: ";
  tree.displayPostorder();

  return 0;
}
```


The insert, delete, and search operations in a BST
---
| Operation | Description | Time Complexity | Notes |
|-----------|-------------|-----------------|-------|
| **Search** | Looks for a node with a specific value. | Average: $𝐎(\log n)$<br>Worst: $𝐎(n)$ | Starts from the root and traverses left or right depending on whether the value is smaller or larger than the current node. |
| **Insert** | Inserts a new node with a specific value. The new node is always inserted at a leaf. | Average: $𝐎(\log n)$<br>Worst: $𝐎(n)$ | The tree starts from the root and the new node is inserted on the left if it's smaller than the current node, or on the right if it's larger. |
| **Delete** | Removes a node with a specific value. This can involve replacing the node with its `in-order successor or predecessor` if it has two children. | Average: $𝐎(\log n)$<br>Worst: $𝐎(n)$ | After deletion, the properties of the BST must be maintained. |


Search in BST t for a node n with a specific value d
---
- Pseudo-code of `recursive` search
```c++
Recursive-Tree-Search(t, d)
    if t = NIL or d = t.data then
        return t
    if d < t.data then
        return Recursive-Tree-Search(t.left, d)
    else
        return Recursive-Tree-Search(t.right, d)
    end if
```
- Pseudo-code of `iterative` search
```c++
Iterative-Tree-Search(t, d)
    while t ≠ NIL and d ≠ t.data do
        if d < t.data then
            t ← t.left
        else
            t ← t.right
        end if
    repeat
    return t
```

Maximum and Minimum of BST t
---
```c++
BST-Maximum(t)
     while t.right ≠ NIL do
         t ← t.right
     repeat
     return t

BST-Minimum(t)
     while t.left ≠ NIL do
         t ← t.left
     repeat
     return t     
```     

Successor and predecessor of node n
---
In a BST,
- The `successor` of node n is the node with data `next to` n's data in ascending order
- The `predecessor` of node n is the node with data `previous to` n's data in ascending order

- Pseudo-code for successor
```c++
 BST-Successor(n)
     if n.right ≠ NIL then
         return BST-Minimum(n.right)
     end if
     s ← n.parent
     while s ≠ NIL and n = s.right do
         n ← s
         s ← s.parent
     repeat
     return s
```     


Insert into BST t a node n with a specific value d
---
- Pseudo-code of `recursive` insert
```c++
Recursive-Insert(t, d)
    if t = NIL then
        create a new node n
        n.data ← d; n.left ← NIL; n.right ← NIL
        return n
    end if
    if d < t.data then
        return Recursive-Insert(t.left, d)
    else
        return Recursive-Insert(t.right, d)
    end if
```
- Pseudo-code of `iterative` insert
  - The procedure maintains a `trailing pointer` `parent` as the parent of `current`

```c++
BST-Insert(t, n)
  parent ← NIL
  current ← t
  while current ≠ NIL do
    parent ← current
    if n.data < current.data then
      current ← current.left
    else
      current ← current.right
    end if
  repeat
  n.parent ← parent
  if parent = NIL then
    t ← n
  else if n.data < parent.data then
    parent.left ← n
  else
    parent.right ← n
  end if
```  


Delete node n with specific value d from BST t
---
- Idea
  1. if n is a leaf node, delete it
  2. if n is a non-leaf node with only one child
     - replace it with the child
  3. if n has two children, replace it with 
     - its `successor`: the minimum node of its right child
     - or its `predecessor`: the maximum node of its left child
- Pseudo-code of `recursive` delete
```c++
BST-Delete(t, d)
  if t = NIL then
    return NIL
  end if

  if d < t.data then
    t.left ← BST-Delete(t.left, d)
  else if d > t.data then
    t.right ← BST-Delete(t.right, d)
  else
    if t.left = NIL then
      return t.right
    else if t.right = NIL then
      return t.left
    end if
    t.data ← t.successor.data
    t.right ← BST-Delete(t.right, t.successor.data)
  end if
  return t
```
- Pseudo-code of `iterative` delete
```c++
BST-Delete(t, n)
  if n.left = NIL then
    Replace(t, n, n.right)
  else if n.right = NIL then
    Replace(t, n, n.left)
  else
    E ← BST-Successor(n)
    if E.parent ≠ n then
      Replace(t, E, E.right)
      E.right ← n.right
      E.right.parent ← E
    end if
    Replace(t, n, E)
    E.left ← n.left
    E.left.parent ← E
  end if
  
// replace node u with v in BST t 
Replace(t, u, v)
  if u.parent = NIL then
    t.root ← v
  else if u = u.parent.left then
    u.parent.left ← v
  else
    u.parent.right ← v
  end if
  if v ≠ NIL then
    v.parent ← u.parent
  end if
```


🍎 Implementation: recursive delete
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
    if (node == nullptr)
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
    if (node == nullptr)
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

  // Helper function for deleting a node with a specific value
  Node *deleteHelper(Node *node, const T &val)
  {
    if (node == nullptr)
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
      if (node->left == nullptr)
      {
        Node *temp = node->right;
        delete node;
        return temp;
      }
      else if (node->right == nullptr)
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

  void inorder(Node *node)
  {
    if (node != nullptr)
    {
      inorder(node->left);
      std::cout << node->data << " ";
      inorder(node->right);
    }
  }

  void displayInorder()
  {
    inorder(root);
    std::cout << std::endl;
  }
};

int main()
{
  BST<int> bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);
  bst.insert(3);
  bst.insert(2);
  bst.insert(9);
  bst.insert(1);
  bst.insert(8);
  bst.insert(6);
  bst.insert(20);
  bst.insert(14);

  bst.displayInorder();

  std::cout << "Search 10: " << (bst.search(10) ? "Found" : "Not found") << std::endl;
  std::cout << "Search 7: " << (bst.search(7) ? "Found" : "Not found") << std::endl;

  bst.remove(10);
  bst.displayInorder();
  std::cout << "Search 10 after deletion: " << (bst.search(10) ? "Found" : "Not found") << std::endl;

  bst.remove(5);
  bst.displayInorder();

  bst.remove(1);
  bst.displayInorder();

  bst.remove(9);
  bst.displayInorder();
  return 0;
}
```


🍎 Implementation: iterative delete
---
```c++
#include <iostream>
using namespace std;

template <typename T>
class BST
{
public:
  struct Node
  {
    T data;
    Node *left;
    Node *right;
    Node(const T &val) : data(val), left(nullptr), right(nullptr) {}
  };

  Node *root;

  Node *findMin(Node *node)
  {
    while (node->left != nullptr)
    {
      node = node->left;
    }
    return node;
  }

  BST() : root(nullptr) {}

  // Helper function for inserting a new node
  Node *insertHelper(Node *node, const T &val)
  {
    if (node == nullptr)
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

  void insert(const T &val)
  {
    root = insertHelper(root, val);
  }

  void deleteNode(T data)
  {
    Node *current = root;
    Node *parent = nullptr;
    bool isleft = true;

    // Find the node with the given data
    while (current != nullptr && current->data != data)
    {
      parent = current;
      if (data < current->data)
      {
        current = current->left;
        isleft = true;
      }
      else
      {
        current = current->right;
        isleft = false;
      }
    }

    if (current == nullptr)
      return; // Data not found

    // data in a leaf node
    if (current->left == nullptr && current->right == nullptr)
    {
      delete current;
      current = nullptr;
      if (parent != nullptr)
      {
        if (isleft)
          parent->left = nullptr;
        else
          parent->right = nullptr;
      }
      return;
    }

    // data in a node with only one child
    if (current->left == nullptr && current->right != nullptr)
    {
      *current = *current->right;
      return;
    }
    if (current->left != nullptr && current->right == nullptr)
    {
      *current = *current->left;
      return;
    }

    // Node with two children: Get the inorder successor
    Node *succ = findMin(current->right);

    // Copy the inorder successor's data to this node
    current->data = succ->data;

    // Delete the inorder successor
    Node *successorParent = current;
    Node *successor = current->right;
    while (successor->left != nullptr)
    {
      successorParent = successor;
      successor = successor->left;
    }

    if (successorParent != current)
    {
      successorParent->left = successor->right;
    }
    else
    {
      successorParent->right = successor->right;
    }

    delete successor;
  }

  void displayInorder(Node *node)
  {
    if (node != nullptr)
    {
      displayInorder(node->left);
      cout << node->data << " ";
      displayInorder(node->right);
    }
  }

  void display()
  {
    displayInorder(root);
    cout << endl;
  }
};

int main()
{
  BST<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(10);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(11);
  tree.insert(1);
  tree.insert(9);
  tree.insert(15);
  tree.insert(8);

  cout << "Inorder traversal before deletion: ";
  tree.display();

  tree.deleteNode(20);
  cout << "Inorder traversal after deleting 20: ";
  tree.display();

  tree.deleteNode(6);
  cout << "Inorder traversal after deleting 6: ";
  tree.display();

  tree.deleteNode(4);
  cout << "Inorder traversal after deleting 4: ";
  tree.display();

  tree.deleteNode(5);
  cout << "Inorder traversal after deleting 5: ";
  tree.display();

  tree.deleteNode(1);
  cout << "Inorder traversal after deleting 1: ";
  tree.display();

  tree.deleteNode(15);
  cout << "Inorder traversal after deleting 15: ";
  tree.display();

  tree.deleteNode(3);
  cout << "Inorder traversal after deleting 3: ";
  tree.display();  

  return 0;
}
```


# References
- [Depth First Traversal: Inorder, Preorder and Postorder tree traversals - Animated guide](https://csanim.com/tutorials/inorder-preorder-and-postorder-tree-traversals-animated-guide)
- [Breadth-first search (BFS) of BST in Python - Visualization and Code](https://csanim.com/tutorials/breadth-first-search-python-visualization-and-code)

