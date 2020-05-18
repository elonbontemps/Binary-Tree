# CPTR 242: Project -- Binary Tree

## Problem Overview

This project will use the BRIDGES API with the earthquake dataset build from USGS site (tweets).
You be building a binary search tree using BRIDGES elements, which will enable you to visualize the tree of earthquakes keyed off their magnitude.
Note that the BRIDGES visualization will also be a means to debug your program, as it will let you view your data structure and its contents after each operation.
The earthquake dataset has been collected from USGS site with the following information: magnitude, longitude, latitude, location, title, url and time.

The driver will be managing the binary search tree details so you can focus on search and traversal operations related to the tree.

The primary functions you will be writing are to determine the smallest earthquake, largest earthquake, highlight earthquakes in a location, and a range of earthquakes.

## Resources

* USGS: <https://www.usgs.gov/natural-hazards/earthquake-hazards>
* Bridges Site: <http://bridgesuncc.github.io/>
  * Getting Started: <http://bridgesuncc.github.io/bridges_setup.html>
  * API Documentation: <http://bridgesuncc.github.io/doc/cxx-api/current/html/index.html>
  * Earthquake Data: <http://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1_earthquake_u_s_g_s.html>

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __getSmallestQuake__, __getLargestQuake__, __countRange__, __countByLocation__, __countWithStyle__, and __resetVisualization__ that work on a Binary Search Tree implementation in _UsgsTree.cpp_.
    A class header and function stubs has been given to you with detailed descriptions.
    Please read the header file for detailed description of the functions.
2. Submitty will be used grade through automated all tests.

## Test Driver

The project continues to follow the testing structure from prior homework.
The Submitty tests are based on this test driver.
A sample __example_input.txt__ file has been given to help you get started.


* Create alternate tests to cover all the test functions
* Create an user input test file to allow for consistent and repeatable testing

## Sign Up For BRIDGES

**Note -- you only need todo this once. If you completed this step on the last project, you do not need to do it again.**

Please sign up for a BRIDGES account at [Bridges Sign Up](http://bridges-cs.herokuapp.com/signup).
Once you have an account, put your username and the API Sha1 key in the `BridgesUser.h` file.

1. Sign up for (bridges](http://bridges-cs.herokuapp.com/signup)
1. Navigate to your profile.
1. Put your __User Name__ in `BridgesUser.h` file
1. Put your __API Sha1 Key__ in `BridgesUser.h` file

These steps are need to make sure you have access to the IMDB data and visualization for the project.

## Setup Local IDE

**Note -- you only need todo this once. If you completed this step on the last project, you do not need to do it again.**

Follow the [Bridges Setup Directions](http://bridgesuncc.github.io/bridges_setup.html) to configure your system.
Please install the libraries in your _student242/include_ folder for the `make` file to work properly.
(If you install in another directory, the make file will need to be altered.)

A script has been created for Code.CS.
If you are using a different IDE, take a look at the website for set up details.
You can also look at supplied set up script to see the exact commands which are being used by Code.CS. 

If you are using Code.CS, do the following:

```sh
cd student242
./setup_bridges_on_linux.sh
```

## Compiling BST Implementations

A _make_ file has been provided to help with compiling your code.
Simply run ```make``` to compile your code after the set up has been completed.
Then execute ```./UsgsTree.out```.
These commands have been tested on c9.io and the lab computers.

```sh
make
./UsgsTree.out
```

The build files can be cleaned up by running ```make clean```.

## Tips

1. In this project, you will get familiar with reading library documentation.
   Bridges has fairly good documentation and you will need it to figure out the available options for completing this assignment.
2. Your IDE may show red marks due to the fact that it does not know about the BRIDGES library.
   You will still be able to build and run the software, even with these marks.
   Try compiling to see if there is really an issue.
