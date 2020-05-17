/****************************************************************************
 *
 * File Name:  TreeTest.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
// Test driver
#include "TreeType.h"
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void TreeTest(std::string inFileName, std::string outFileName,
              std::string outputLabel) {
  ifstream inFile;  // file containing operations
  ofstream outFile; // file containing output
  string command;   // operation to be executed

  char item;
  string orderItem;
  TreeType tree;
  OrderType order;
  bool found;
  bool finished;
  int numCommands;

  // Prepare files
  inFile.open(inFileName.c_str());
  outFile.open(outFileName.c_str());
  outFile << outputLabel << std::endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "AncestorsIterative") {
      inFile >> item;
      ItemType itemType = ItemType(item);
      tree.AncestorsIterative(itemType, outFile);
      outFile << " are the ancestors of " << item << std::endl;
    } else if (command == "AncestorsRecursive") {
      inFile >> item;
      ItemType itemType = ItemType(item);
      tree.AncestorsRecursive(itemType, outFile);
      outFile << " are the ancestors of " << item << std::endl;
    } else if (command == "AncestorsReverse") {
      inFile >> item;
      ItemType itemType = ItemType(item);
      tree.AncestorsReverse(itemType, outFile);
      outFile << " are the ancestors of " << item << " in reverse" << std::endl;
    } else if (command == "PutItem") {
      inFile >> item;
      tree.PutItem(item);
      outFile << item;
      outFile << " is inserted" << std::endl;
    } else if (command == "DeleteItem") {
      inFile >> item;
      tree.DeleteItem(item);
      outFile << item;
      outFile << " is deleted" << std::endl;
    } else if (command == "GetItem") {
      inFile >> item;
      item = tree.GetItem(item, found);
      if (found) {
        outFile << item << " found in list." << std::endl;
      } else {
        outFile << item << " not in list." << std::endl;
      }
    } else if (command == "GetLength") {
      outFile << "Number of nodes is " << tree.GetLength() << std::endl;
    } else if (command == "IsEmpty") {
      if (tree.IsEmpty()) {
        outFile << "Tree is empty." << std::endl;
      } else {
        outFile << "Tree is not empty." << std::endl;
      }
    } else if (command == "PrintTree") {
      tree.Print(outFile);
      outFile << std::endl;
    } else if (command == "ResetTree") {
      inFile >> orderItem;
      if (orderItem == "PRE_ORDER") {
        order = PRE_ORDER;
      } else if (orderItem == "IN_ORDER") {
        order = IN_ORDER;
      } else {
        order = POST_ORDER;
      }
      tree.ResetTree(order);
    } else if (command == "GetNextItem") {
      inFile >> orderItem;
      if (orderItem == "PRE_ORDER") {
        order = PRE_ORDER;
      } else if (orderItem == "IN_ORDER") {
        order = IN_ORDER;
      } else {
        order = POST_ORDER;
      }
      item = tree.GetNextItem(order, finished);
      outFile << "Next item is: " << item << std::endl;
      if (finished) {
        outFile << orderItem << " traversal is complete." << std::endl;
      }
    } else if (command == "IsFull") {
      if (tree.IsFull()) {
        outFile << "Tree is full." << std::endl;
      } else {
        outFile << "Tree is not full." << std::endl;
      }
    } else if (command == "MakeEmpty") {
      tree.MakeEmpty();
      outFile << "Tree has been made empty." << std::endl;
    } else {
      std::cout << " (Command not recognized)";
    }
    numCommands++;
    std::cout << " Command is completed." << std::endl;
    inFile >> command;
  }

  std::cout << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
}
