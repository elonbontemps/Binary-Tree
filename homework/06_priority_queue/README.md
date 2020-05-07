# CPTR 242: Homework Assignment -- Heaps

## Problem Overview

Your task in this assignment is to implement __reheap__ for a Priority Queue based on a heap.
The function __reheap__ functions have been implemented as a recursive function and you task is to write the equivalent function as an iterative function.
The __reheap__ iterative function must be implemented in two ways: up, and down.

Note the file you are using has the extension __tpp__.
This is because you are using a template and it must be include in the header file.
To help designate they difference between implementation and template, the extension has been changed to `tpp`.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement the two versions of _reheap_ for a linked implementation in _reheap.tpp_.
    A stub of the function has been given to you.

    ```{c++}
    template <class ItemType>
    void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
        // TODO Implement a Iterative ReheapDown Function.
    }

    template <class ItemType>
    void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
        // TODO Implement a Iterative ReheapUp Function.
    }
    ```

2. Pass all the tests in Submitty.

## Test Driver

The book describes the operations of priority queues and heaps.
The submitty tests are based on previous test drivers.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

A simple way to compile them is to list the cpp files after the g++ compiler.
You can run the test by executing the following:

```{sh}
g++ *.cpp & ./a.out
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

## Submission

Your submission must include a _reheap.tpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
