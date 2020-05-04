/*************************************************************************
 *
 * Assignment: ReplaceItemStack driver file
 *
 * File Name: StackTest.cpp
 * Course:    CPTR 242
 */
#include "StackTest.h"
#include "StackType.h"
#include <fstream>
#include <iostream>


void StackTest(std::string inFileName, std::string outFileName,
               std::string outputLabel) {
  std::ifstream inFile;  // file containing operations
  std::ofstream outFile; // file containing output
  std::string command;   // operation to be executed

  ItemType item;
  ItemType itemNew;
  ItemType itemOld;
  StackType stack;
  int numCommands;

  // Prompt for file names, read file names, and prepare files
  inFile.open(inFileName.c_str());
  outFile.open(outFileName.c_str());
  outFile << outputLabel << std::endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    try {
      if (command == "Push") {
        inFile >> item;
        outFile << "Push " << item << std::endl;
        stack.Push(item);
      } else if (command == "Pop") {
        item = stack.Top();
        stack.Pop();
        outFile << "Pop " << item << std::endl;
      } else if (command == "Top") {
        item = stack.Top();
        outFile << "Top element is " << item << std::endl;
      } else if (command == "IsEmpty") {
        if (stack.IsEmpty()) {
          outFile << "Stack is empty." << std::endl;
        } else {
          outFile << "Stack is not empty." << std::endl;
        }
      } else if (command == "IsFull") {
        if (stack.IsFull()) {
          outFile << "Stack is full." << std::endl;
        } else {
          outFile << "Stack is not full." << std::endl;
        }
      } else if (command == "ReplaceItem") {
        inFile >> itemNew;
        inFile >> itemOld;
        stack.ReplaceItem(itemNew, itemOld);
        std::string s1(1, itemNew);
        std::string s2(1, itemOld);
        outFile << s1 + " was replaced with " + s2 << std::endl;
      } else if (command == "Print") {
        PrintStack(outFile, stack);
      } else
        outFile << command << " not found" << std::endl;
    } catch (FullStack) {
      outFile << "FullStack exception thrown." << std::endl;
    } catch (EmptyStack) {
      outFile << "EmptyStack exception thrown." << std::endl;
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inFile >> command;
  };

  std::cout << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
}

void PrintStack(std::ofstream &dataFile, StackType &stack) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  StackType tempStack;
  ItemType item;

  dataFile << "PrintStack: ";

  if (stack.IsEmpty()) {
    dataFile << "List is empty.";
  }

  while (!stack.IsEmpty()) {
    item = stack.Top();
    stack.Pop();
    std::string s(1, item);
    dataFile << s + " ";
    tempStack.Push(item);
  }

  // restore stack
  while (!tempStack.IsEmpty()) {
    item = tempStack.Top();
    tempStack.Pop();
    stack.Push(item);
    // copy.Push(tempItem)
  }

  dataFile << std::endl;
}
