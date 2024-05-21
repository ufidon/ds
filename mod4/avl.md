# [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

💡 Intuition
---
- Insertions or deletions in a BST of $n$ nodes may lead to degeneration
  - the worst degenerated BST is similar to linked list with height $n$
- The complexities of BST SID (search, insertion and delete) operations can be bounded by $O(\log n)$ through `height self-balancing` during insertions and deletions.


🏃 Create a [worst BST](https://csvistool.com/BST) with
- insertion
- deletion


Skewed BST vs. Balanced BST
---
| Feature | Skewed (unbalanced) BST | [Balanced BST](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) |
|---------|------------|--------------|
| **Illustration** | ![Skewed BST](https://upload.wikimedia.org/wikipedia/commons/a/a9/Unbalanced_binary_tree.svg) | ![Balanced BST](https://upload.wikimedia.org/wikipedia/commons/0/06/AVLtreef.svg) |
| **Definition** | A BST where most of the nodes are on one side of the tree (left or right), causing an imbalance. | A BST that is balanced, meaning the height of the two subtrees of any node differ by no more than one. |
| **Height** | Can be as high as **O(n)**, where `n` is the number of nodes. | Typically **O(log n)**, which is the ideal height for a BST. |
| **Search Time Complexity** | Worst-case: **O(n)**, similar to a `linked list`. | Average-case: **O(log n)**, since the tree is well-balanced. |
| **Insert Time Complexity** | Worst-case: **O(n)**, as new nodes are often inserted as leaf nodes at the bottom. | Average-case: **O(log n)**, due to the tree's balanced nature. |
| **Delete Time Complexity** | Worst-case: **O(n)**, especially if the node to be deleted is near the bottom. | Average-case: **O(log n)**, since rebalancing may be required but is limited. |
| **Identification** | Identified by checking if there are significantly more nodes on one side of the tree than the other. | Identified by ensuring that for every node, the heights of the left and right subtrees differ by no more than one. |
| **Balancing Required** | Yes, balancing operations like rotations are needed to improve efficiency. | No, if the tree is already balanced; otherwise, yes after insertions or deletions. |
| **Use Case** | Not ideal for operations due to poor performance. Often occurs due to unbalanced insertions. | Ideal for operations that require frequent searches, insertions, and deletions. |


Comparison of Common Balanced Trees
---
| Feature | AVL Tree | Red-Black Tree | B-Tree | Splay Tree |
|---------|----------|----------------|--------|------------|
| **Balance Criteria** | Heights of any two sibling subtrees differ by at most 1. | Red nodes cannot have red children, and every path from root to leaf has the same number of black nodes. | All leaf nodes are at the same level, and non-leaf nodes have between t-1 and 2t-1 keys. | Recently accessed elements move closer to the root through rotations. |
| **Search Time** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | Amortized $O(\log n)$ |
| **Insert Time** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | Amortized $O(\log n)$ |
| **Delete Time** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | Amortized $O(\log n)$ |
| **Worst-case Space** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Self-balancing** | Yes | Yes | Yes | Yes |
- $n$ is the number of nodes; $t$ is the minimum degree of the B-tree
- Each tree has its own unique characteristics and balancing strategies to maintain the $O(\log n)$ complexity for SID operations.