# CPTR 242: Homework Linked List

## Problem Overview

Your task in this assignment is to implement __MinLoc__ and __Sort__ for an Unsorted List.
The function __MinLoc__ recursively searches for a smallest item in the list and returns its location.
The __Sort__ function uses __MinLoc__ to build a recursive sort function.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __MinLoc__ for the linked implementation in _minSort.cpp_.
   A stub of the function has been given to you.
2. Implement __Sort__ for the linked implementation in _minSort.cpp_.
   A stub of the function has been given to you.
   The sort must use __MinLoc__ to perform the sort operation.
   _TIP:_ It is easier to move the value in info instead of re-ordering the list.
3. Pass all the tests in Submitty.

## Test Driver

The assignment builds on the previous methods of testing.
The Submitty tests are based on this test driver provided.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

Each list implementation has a unique name: SortedArray and SortedList.
A simple way to compile them is to list the cpp after the g++ compiler.

```sh
g++ listTest.cpp minSort.cpp ItemType.cpp unsorted.cpp listDriver.cpp
```

You can run the test by executing the following:

```sh
./a.out < list_driver.txt
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are included in the _#include_ statement.

## Submission

Your submission must include a _minSort_.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
