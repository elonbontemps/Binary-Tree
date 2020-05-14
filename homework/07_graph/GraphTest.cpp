/*************************************************************************
 *
 * Assignment 5: Delete edge, vertices driver file
 *
 * File Name: GraphDriver.cpp
 * Course:    CPTR 242
 * Date:      April 29, 2019
 */

#include "GraphTest.h"
#include "GraphType.h"
#include <iostream>
#include <string>


void GraphTest(std::string inFileName, std::string outFileName,
               std::string outputLabel) {
  std::ifstream inFile;  // file containing operations
  std::ofstream outFile; // file containing output
  std::string command;   // operation to be executed

  GraphType<int> graph;
  int numCommands;
  int vertex1;
  int vertex2;
  int weight;

  // Prepare files
  inFile.open(inFileName);
  outFile.open(outFileName);
  outFile << outputLabel << std::endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    try {
      if (command == "AddVertex") {
        inFile >> vertex1;
        graph.AddVertex(vertex1);
        outFile << "Vertex " << vertex1 << " was added." << std::endl;
      } else if (command == "AddEdge") {
        inFile >> vertex1;
        inFile >> vertex2;
        inFile >> weight;
        outFile << "Edge (" << vertex1 << ", " << vertex2 << ") with weight "
                << weight << " has been created." << std::endl;
        graph.AddEdge(vertex1, vertex2, weight);
      } else if (command == "WeightIs") {
        inFile >> vertex1;
        inFile >> vertex2;
        outFile << "Edge (" << vertex1 << ", " << vertex2 << ") has weight "
                << weight << "." << std::endl;
      } else if (command == "GetToVertices") {
        outFile << "GetToVertices is not yet implemented." << std::endl;
      } else if (command == "DeleteEdge") {
        inFile >> vertex1;
        inFile >> vertex2;
        graph.DeleteEdge(vertex1, vertex2);
        outFile << "Edge (" << vertex1 << ", " << vertex2 << ") was deleted."
                << std::endl;
      } else if (command == "DeleteVertex") {
        inFile >> vertex1;
        graph.DeleteVertex(vertex1);
        outFile << "Vertex " << vertex1 << " was deleted." << std::endl;
      } else if (command == "Print") {
        graph.Print(outFile);
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