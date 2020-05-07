/****************************************************************************
 *
 * File Name:  PriorityQueueDriver.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
// Test driver
#include <fstream>
#include <iostream>
typedef int ItemType;
#include "PriorityQueueType.h"

void PriorityQueueTest(std::string inFileName, std::string outFileName,
                       std::string outputLabel) {
  std::ifstream inFile;  // file containing operations
  std::ofstream outFile; // file containing output
  std::string command;   // operation to be executed

  ItemType item;
  PriorityQueueType<int> queue(5);
  int numCommands;

  // Prepare files
  inFile.open(inFileName.c_str());
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
        outFile << item << " is dequeued." << std::endl;
      } else if (command == "EnqueueIterative") {
        inFile >> item;
        queue.EnqueueIterative(item);
        outFile << item << " is enqueued (iterative)." << std::endl;
      } else if (command == "DequeueIterative") {
        queue.DequeueIterative(item);
        outFile << item << " is dequeued (iterative)." << std::endl;
      } else if (command == "IsEmpty") {
        if (queue.IsEmpty()) {
          outFile << "Queue is empty." << std::endl;
        } else {
          outFile << "Queue is not empty." << std::endl;
        }
      } else if (command == "IsFull") {
        if (queue.IsFull()) {
          outFile << "Queue is full." << std::endl;
        } else {
          outFile << "Queue is not full." << std::endl;
        }
      } else if (command == "MakeEmpty") {
        queue.MakeEmpty();
      }
    } catch (FullPriorityQueue) {
      outFile << "FullQueue exception thrown." << std::endl;
    } catch (EmptyPriorityQueue) {
      outFile << "EmtpyQueue exception thrown." << std::endl;
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed." << std::endl;
    inFile >> command;
  };

  std::cout << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
}
