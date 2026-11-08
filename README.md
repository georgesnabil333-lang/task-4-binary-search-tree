# Task 4: Binary Search Tree

*Module:* KH5002CMD Advanced Algorithms
*Language:* C++ (C++17)

## Description
This project implements a binary search tree (BST) of integers in C++. The Tree class supports insertion, search, deletion (leaf, one-child and two-child nodes), in-order and pre-order traversal, height, and level-order traversal. A destructor frees every node.

## Files
| File | Purpose |
|---|---|
| Tree.h | Node and Tree classes |
| main.cpp | Test driver |

## Operations
| Operation | Description | Time complexity |
|---|---|---|
| insert(n, v) | Inserts a value (duplicates are ignored) | O(h) |
| search(n, v) | Returns true if the value is in the tree | O(h) |
| findMin(n) | Returns the smallest node of a subtree | O(h) |
| deleteNode(n, v) | Deletes a value (leaf, one child or two children) | O(h) |
| inOrder(n), preOrder(n) | Depth-first traversals | O(n) |
| height(n) | Height in edges (empty tree = -1, leaf = 0) | O(n) |
| levelOrder() | Breadth-first traversal using a queue | O(n) |
| printTree(n) | Sideways ASCII print (extra) | O(n) |

Here h is the height of the tree: O(log n) for a balanced tree and O(n) in the worst case, when values are inserted in sorted order. Deleting a node with two children replaces it with the smallest value of its right subtree (its in-order successor).

## Build and run

g++ -std=c++17 main.cpp -o tree
./tree

On Windows, run tree.exe instead of ./tree.

## Expected output
The driver inserts 50, 30, 70, 20, 40, 60, 80, 10, 35, then deletes 10, 20 and 30:

InOrder: 10 20 30 35 40 50 60 70 80
PreOrder: 50 30 20 10 40 35 70 60 80
Height: 3
Search 35: 1
Search 99: 0
After del 10: 20 30 35 40 50 60 70 80
After del 20: 30 35 40 50 60 70 80
After del 30: 35 40 50 60 70 80
LevelOrder: 50 40 70 35 60 80

Note: the lab sheet's expected output leaves out the value 30 in the InOrder, "After del 10" and "After del 20" lines. 30 is still in the tree at that point, so the output above is correct.
