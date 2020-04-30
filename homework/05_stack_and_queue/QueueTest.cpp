/*************************************************************************
 *
 * Assignment: ReplaceItemQueue driver file
 *
 * File Name: DriverQueue.cpp
 * Course:    CPTR 242
 */
#include "QueueType.h"
#include "QueueTest.h"
#include <fstream>
#include <iostream>
#include <string>

void QueueTest(std::string inFileName, std::string outFileName,
               std::string outputLabel) {
  std::ifstream inFile;  // file containing operations
  std::ofstream outFile; // file containing output
  std::string command;   // operation to be executed

  ItemType item;
  ItemType itemNew;
  ItemType itemOld;
  QueueType queue(5);
  int numCommands;

  // Prompt for file names, read file names, and prepare files
  inFile.open(inFileName.c_str());
  if (!inFile) {
    std::cout << "File not found." << std::endl;
    return;
  }
  outFile.open(outFileName.c_str());

  outFile << outputLabel << std::endl;
  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    try {
      if (command == "Enqueue") {
        inFile >> item;
        queue.Enqueue(item);
        outFile << item << " is enqueued." << std::endl;
      } else if (command == "Dequeue") {
        queue.Dequeue(item);
        outFile << item << " is dequeued. " << std::endl;
      } else if (command == "IsEmpty")
        if (queue.IsEmpty()) {
          outFile << "Queue is empty." << std::endl;
        } else {
          outFile << "Queue is not empty." << std::endl;
        }
      else if (command == "IsFull")
        if (queue.IsFull()) {
          outFile << "Queue is full." << std::endl;
        } else {
          outFile << "Queue is not full." << std::endl;
        }
      else if (command == "ReplaceItem") {
        inFile >> itemNew;
        inFile >> itemOld;
        queue.ReplaceItem(itemNew, itemOld);
        std::string s1(1, itemNew);
        std::string s2(1, itemOld);
        outFile << s1 + " was replaced with " + s2 << std::endl;
      } else if (command == "Print") {
        PrintQueue(outFile, queue);
      } else {
        std::cout << "Command is not recognized." << std::endl;
      }
    } catch (FullQueue) {
      outFile << "FullQueue exception thrown." << std::endl;
    } catch (EmptyQueue) {
      outFile << "EmtpyQueue exception thrown." << std::endl;
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

void PrintQueue(std::ofstream &dataFile, QueueType &queue) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  QueueType tempQ;
  ItemType item;
  dataFile << "PrintQueue: ";

  if (queue.IsEmpty()) {
    dataFile << "List is empty.";
  }

  while (!queue.IsEmpty()) {
    queue.Dequeue(item);
    std::string s(1, item);
    dataFile << s + " ";
    tempQ.Enqueue(item);
  }
  // restore queue
  while (!tempQ.IsEmpty()) {
    tempQ.Dequeue(item);
    queue.Enqueue(item);
  }

  dataFile << std::endl;
}
