# CPTR 242: Homework -- Binary Search Trees

## Problem Overview

Your task in this assignment is to implement __ancestors__ for a Binary Search Tree.
The function __ancestors__ prints the ancestors for a given node whose _info_ member contains _value_.
Do not print value.
The __ancestors__ function must be implemented in three ways: iterative, recursive and reverse.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement the three versions of _ancestors_ for a linked implementation in `ancestors.cpp`.
   A stub of the function has been given to you.

```cpp
void TreeType::AncestorsIterative(ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors iterative print
}

void PrintAncestorsRecursive(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors recursive print
}

void PrintAncestorsReverse(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors reverse print
}
```

1. Pass all the tests in Submitty.

## Test Driver

The book describes the operations of binary search trees.
The submitty tests are based on previous test drivers.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

A simple way to compile them is to list the cpp files after the g++ compiler.
You can run the test by executing the following:

```
g++ -std=c++17 *.cpp & ./a.out
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

## Submission

Your submission must include a _ancestors.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
