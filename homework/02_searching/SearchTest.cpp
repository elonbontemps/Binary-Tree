/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchTest.cpp
 * Course:    CPTR 242
 */
#include "BinarySearch.h"
#include "ItemType.h"
#include "LinearSearch.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const std::vector<ItemType> &input) {
  os << "[";
  bool first = true;
  for (auto const &i : input) {
    if (first) {
      first = false;
    } else {
      os << ", ";
    }
    i.Print(os);
  }
  os << "]";
  return os;
}

void searchDriver(std::string inFileName, std::string outFileName,
                  std::string outputLabel) {
  std::ifstream inFile;     // file containing operations
  std::ofstream outFile;    // file containing output
  std::string command;      // operation to be executed
  std::ifstream listInFile; // file list data
  std::string data;         // data to be loaded

  int number;
  ItemType item;
  std::vector<ItemType> list;
  int location;
  int comparisons;
  int numCommands;

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
    if (command == "LinearSearch") {
      inFile >> number;
      item.Initialize(number);
      LinearSearch::Search(list, item, location, comparisons);
      item.Print(outFile);
      if (location > 0) {
        outFile << " was found at " << location << " in list." << std::endl;
      } else {
        outFile << " is not in list." << std::endl;
      }
      outFile << "Linear search performed " << comparisons << " comparisons."
              << std::endl;
    } else if (command == "BinarySearch") {
      inFile >> number;
      item.Initialize(number);
      BinarySearch::Search(list, item, location, comparisons);
      item.Print(outFile);
      if (location > 0) {
        outFile << " was found at " << location << " in list." << std::endl;
      } else {
        outFile << " is not in list." << std::endl;
      }
      outFile << "Binary search performed " << comparisons << " comparisons."
              << std::endl;
    } else if (command == "LoadListFromFile") {
      inFile >> data;
      listInFile.close();
      listInFile.clear();
      listInFile.open(data);
      if (!listInFile) {
        std::cout << "Data file not found." << std::endl;
        return;
      }
      listInFile >> number;
      while (number > 0) {
        item.Initialize(number);
        list.push_back(item);
        listInFile >> number;
      }
      outFile << data << " has loaded " << list.size() << " items."
              << std::endl;
    } else if (command == "GetLength") {
      outFile << "Length is " << list.size() << std::endl;
    } else if (command == "MakeEmpty") {
      list.clear();
    } else if (command == "PrintList") {
      outFile << list << std::endl;
    } else {
      std::cout << " is not a valid command --";
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inFile >> command;
  };

  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
}
