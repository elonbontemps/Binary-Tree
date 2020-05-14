# CPTR 242: Homework Assignment -- Graphs

## Problem Overview

Your task in this assignment is to implement two new functions for a graph.
The function __DeleteEdge__ deletes the edge specified by the two vertex parameters.
The function __DeleteVertex__ deletes the vertex specified by the input parameter, deletes all edges associated with the deleted vertex, and adds the deleted vertex to the queue of unused vertices.
The function should be implemented using only the standard functions on a graph.

NOTE: Because __DeleteVertex__ also deletes any edges associated with the vertex, it may be easier to implement __DeleteEdge__ first and use that within the __DeleteVertex__ function.

NOTE #2: To add a deleted vertex to the queue of unused vertices, use ```AddUnusedVertex(index);``` where ```index``` is the integer index of the deleted vertex (unusedVertices is a member variable to GraphType).

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __DeleteEdge__ for the graph implementation in _DeleteEdge.cpp_.
    A file has been provided for you and function header.
2. Implement __DeleteVertex__ for the graph implementation in _DeleteVertex.cpp_.
    A file has been provided for you and function header.
3. Pass all the tests in Submitty.

## Test Driver

The book outlines a method of testing graphs.
The submitty tests are based on this test driver.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

The graph implementation is called __GraphType__.
A simple way to compile it is to list the cpp after the g++ compiler.

```sh
g++ -std=c++17 -o delete_graph.out DeleteEdge.cpp DeleteVertex.cpp GraphDriver.cpp GraphType.cpp
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

To test the code, run this command:

```sh
./delete_graph.out
```

Enter the __graph_user_input.txt__ file name as the test file and enter an output file name of your choice.

## Submission

Your submission must include a _DeleteEdge.cpp_ and _DeleteVertex.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
