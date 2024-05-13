# [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)


Skewed BST vs. Balanced BST
---
| Feature | Skewed (unbalanced) BST | [Balanced BST](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) |
|---------|------------|--------------|
| **Illustration** | ![Skewed BST](https://upload.wikimedia.org/wikipedia/commons/a/a9/Unbalanced_binary_tree.svg) | ![Balanced BST](https://upload.wikimedia.org/wikipedia/commons/0/06/AVLtreef.svg) |
| **Definition** | A BST where most of the nodes are on one side of the tree (left or right), causing an imbalance. | A BST that is balanced, meaning the height of the two subtrees of any node differ by no more than one. |
| **Height** | Can be as high as **O(n)**, where `n` is the number of nodes. | Typically **O(log n)**, which is the ideal height for a BST. |
| **Search Time Complexity** | Worst-case: **O(n)**, similar to a linked list. | Average-case: **O(log n)**, since the tree is well-balanced. |
| **Insert Time Complexity** | Worst-case: **O(n)**, as new nodes are often inserted as leaf nodes at the bottom. | Average-case: **O(log n)**, due to the tree's balanced nature. |
| **Delete Time Complexity** | Worst-case: **O(n)**, especially if the node to be deleted is near the bottom. | Average-case: **O(log n)**, since rebalancing may be required but is limited. |
| **Identification** | Identified by checking if there are significantly more nodes on one side of the tree than the other. | Identified by ensuring that for every node, the heights of the left and right subtrees differ by no more than one. |
| **Balancing Required** | Yes, balancing operations like rotations are needed to improve efficiency. | No, if the tree is already balanced; otherwise, yes after insertions or deletions. |
| **Use Case** | Not ideal for operations due to poor performance. Often occurs due to unbalanced insertions. | Ideal for operations that require frequent searches, insertions, and deletions. |