/****************************************************************************
 *
 * File Name:  listDriver.cpp
 * Course:     CPTR 242
 * Source:     C++ Plus Data Structures 6th Edition
 *             by Nell Dale, Chip Weems, Tim Richards
 *
 */
// Test driver
#include "listTest.h"
#include "unsorted.h"
#include <fstream>
#include <iostream>
#include <string>

void listTest(string inFileName, string outFileName, string outputLabel) {
  ifstream inFile;  // file containing operations
  ofstream outFile; // file containing output
  string command;   // operation to be executed

  int number;
  ItemType item;
  UnsortedType list;
  bool found;
  int numCommands;

  // Prepare files
  inFile.open(inFileName);
  outFile.open(outFileName);

  outFile << outputLabel << std::endl;
  if (!inFile) {
    std::cout << "File not found." << std::endl;
    return;
  }

  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Sort") {
      list.SortItems();
      outFile << "Sorted list." << std::endl;
    } else if (command == "MinItem") {
      item = list.MinItem();
      item.Print(outFile);
      outFile << " is the minimum value." << std::endl;
    } else if (command == "PutItem") {
      inFile >> number;
      item.Initialize(number);
      list.PutItem(item);
      item.Print(outFile);
      outFile << " was added to the list." << std::endl;
    } else if (command == "DeleteItem") {
      inFile >> number;
      item.Initialize(number);
      list.DeleteItem(item);
      item.Print(outFile);
      outFile << " was deleted." << std::endl;
    } else if (command == "GetItem") {
      inFile >> number;
      item.Initialize(number);
      item = list.GetItem(item, found);
      item.Print(outFile);
      if (found) {
        outFile << number << " found in list." << std::endl;
      } else {
        outFile << number << " not in list." << std::endl;
      }
    } else if (command == "GetLength") {
      outFile << "Length is " << list.GetLength() << std::endl;
    } else if (command == "IsFull") {
      if (list.IsFull()) {
        outFile << "List is full." << std::endl;
      } else {
        outFile << "List is not full." << std::endl;
      }
    } else if (command == "MakeEmpty") {
      list.MakeEmpty();
    } else if (command == "PrintList") {
      PrintList(outFile, list);
    } else {
      outFile << command << " is not a valid command." << std::endl;
    }
    numCommands++;
    std::cout << " -- Command number " << numCommands << " completed."
              << std::endl;
    inFile >> command;
  };

  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
};

void PrintList(ofstream &dataFile, UnsortedType &list) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  int length;
  ItemType item;
  dataFile << "PrintList: ";
  list.ResetList();
  length = list.GetLength();
  if (length == 0) {
    dataFile << "List is empty.";
  } else {
    for (int counter = 1; counter <= length; counter++) {
      item = list.GetNextItem();
      item.Print(dataFile);
    }
  }
  dataFile << std::endl;
}
