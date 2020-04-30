# CPTR 242: Homework Assignment - Stack and Queues

## Problem Overview

Your task in this assignment is to implement a new function for a stack and a queue.
The function __ReplaceItem__ takes an new item, finds the old item(s) in the _queue_, and replaces the old item with the new item in the _queue_.
The function __ReplaceItem__ takes an new item, finds the old item(s) in the _stack_, and replaces the old item with the new item in the _stack_.
The function should be implemented using only the standard functions on a stack and queue (i.e. push and pop or enqueue and dequeue) for each respective data structure.

In both cases, ALL instances of the old item in the queue/stack should be replaced with the new item.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __ReplaceItem__ for the queue implementation in _QueueReplaceItem.cpp_.
    A cpp file has been provided for you with a function header.
2. Implement __ReplaceItem__ for the stack implementation in _StackReplaceItem.cpp_.
    A cpp file has been provided for you with a function header.
3. Pass all the tests in Submitty.

## Test Driver

The book describes the operations of queues and stacks.
The submitty tests are based on previous test drivers.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

Each list implementation has a unique name: QueueType and StackType.
A simple way to compile them is to list the cpp after the g++ compiler.

```sh
g++ -std=c++17 -o queue.out QueueReplaceItem.cpp QueueType.cpp QueueDriver.cpp
g++ -std=c++17 -o stack.out StackReplaceItem.cpp StackType.cpp StackDriver.cpp
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

To test the code, run this command:

```sh
./queue.out
./stack.out
```

Enter the __queue_user_input.txt__ file name as the test file and enter an output file name of your choice.

## Submission

Your submission must include a _QueueReplaceItem.cpp_ and _StackReplaceItem.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
