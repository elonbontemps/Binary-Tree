# CPTR 242: Searching Homework

## Problem Overview

Your task in this assignment is to implement a two sort functions with data stored in a vector.
Each search function will implement a different search algorithm: linear search and binary search.
To better understand how these algorithms compare, you will count the number of comparisons made by each algorithm.

## Object Comparison

The data will be stored in a vector of objects called `ItemType`.
In a system with real data, information may not be easily compared.
Consider sorting a list of students, do you sort by name, age, height, etc.
The object may include a function called `CompareTo` to define how to compare to objects.
For this assignment, the two objects will be compared with each other using this function.
The result will be one of these values from the `enum RelationType`:

```c++
enum RelationType { LESS, GREATER, EQUAL };
```

Consider this example for doing the comparison between `item1` and `item2`.
Notice how a switch is used to jump to the comparison result.

```c++
switch (item1.ComparedTo(item2)) {
case LESS:
    // Do something for less than
    break;
case GREATER:
    // Do something for greater than
    break;
case EQUAL:
    // Do something for equal
    break;
}
```

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement a __Linear Search__ over sorted data with the implementation in _LinearSearch.cpp_.
     * See the _LinearSearch.h for the function definition.
     * Include an early exit condition if you know the value will not be in the results.
2. Implement a __Binary Search__ over sorted data with the implementation in _BinarySearch.cpp_.
     * See the _BinarySearch.h for the function definition.
3. Pass all the tests in Submitty.

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
Please model the method we have used for homework 1 in creating your own test input for the driver.

## Compiling List Implementations

Each list implementation has a unique name: LinearSearch and BinarySearch.
A simple way to compile them is to list the cpp after the g++ compiler.

```sh
g++ -std=c++17 -o search.out SearchDriver.cpp LinearSearch.cpp BinarySearch.cpp
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

A main driver has been provided to allow a user to run test input.
The code can be compile by running the following command.

To test the code, run this command:

```sh
./search.out < input_driver.txt
```

Enter the __input_driver.txt__ file name as the test file and enter an output file name of your choice.

## Submission

Your submission must include a _LinearSearch.cpp_ and _BinarySearch.cpp_ files.
All other file _.h_ and _.cpp_ should remain unchanged.
