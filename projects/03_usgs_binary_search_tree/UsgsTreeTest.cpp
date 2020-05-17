/*************************************************************************
 *
 * Project: UsgsTree Driver
 *
 * File Name: UsgsTreeDriver.cpp
 * Course:    CPTR 242
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "BSTElement.h"
#include "Bridges.h"
#include "BridgesUser.h"
#include "DataSource.h"
#include "UsgsTree.h"
#include "bst.h"
#include "data_src/EarthquakeUSGS.h"

using namespace bridges;

void UsgsTreeTest(std::string inFileName, std::string outFileName,
                  std::string outputLabel) {
  // Used for test driver functionality.
  ifstream inFile;
  std::ofstream outFile;
  string option;

  // Used to interact with BST.
  string color;
  string color2;
  string location;
  EarthquakeUSGS usgsRecord;
  float min;
  float max;
  int count;

  // Prepare files
  inFile.open(inFileName.c_str());
  outFile.open(outFileName.c_str());
  outFile << outputLabel << std::endl;
  if (!inFile) {
    std::cout << "File not found." << std::endl;
    return;
  }

  inFile >> option;

  // create the Bridges object, set credentials
  BridgesUser bUser;
  Bridges bridges(bUser.getBridgesNumber(), bUser.getBridgesUserID(),
                  bUser.getBridgesAPIKey());

  // read the earth quake  data and build the BST
  bridges.setTitle("Recent Earthquakes (USGIS Data)");
  bridges.setDescription("The tree created from earthquake magnitudes.");

  UsgsTree tree;

  DataSource ds(&bridges);
  BST<float, EarthquakeUSGS> bst;

  // Test driver menu and options
  int numOptions = 0;
  while (option != "Quit") {
    std::cout << option;
    if (option == "Menu") {
      outFile << "Select options" << std::endl;
      outFile << "BuildTree. Adds all earthquakes to the tree." << std::endl;
      outFile << "SmallestQuake. Finds the smallest quake in the tree." << std::endl;
      outFile << "LargestQuake. Finds the largest quake in the tree." << std::endl;
      outFile
          << "CountRange. Finds the all quakes in a given range in the tree."
          << std::endl;
      outFile << "CountByLocation. Finds the all quakes for this location in "
                 "the tree."
              << std::endl;
      outFile << "CountTreeInStyle. Style the tree and count all quakes in the "
                 "tree."
              << std::endl;
      outFile
          << "Visualize. Builds the bridges visualization and prints the URL."
          << std::endl;
      outFile << "ResetVisualization. Reset the visualization of all tree "
                 "nodes and edges."
              << std::endl;
      outFile << "ResetTree. Remove all items from the tree." << std::endl;
      outFile << "Quit. Quit application." << std::endl;
      outFile << "Menu. Display menu." << std::endl;
    } else if (option == "SmallestQuake") {
      inFile >> color;
      usgsRecord = tree.getSmallestQuake(bst.getRoot(), color);
      outFile << "The smallest quake was a " << usgsRecord.getMagnitude()
              << " in " << usgsRecord.getLocation() << "." << std::endl;
    } else if (option == "LargestQuake") {
      inFile >> color;
      usgsRecord = tree.getLargestQuake(bst.getRoot(), color);
      outFile << "The largest quake was a " << usgsRecord.getMagnitude()
              << " in " << usgsRecord.getLocation() << "." << std::endl;
    } else if (option == "CountRange") {
      inFile >> min;
      inFile >> max;
      inFile >> color;
      count = tree.countRange(min, max, bst.getRoot(), color);
      outFile << "The tree has " << count << " quakes between " << min
              << " and " << max << "." << std::endl;
    } else if (option == "CountByLocation") {
      inFile >> location;
      inFile >> color;
      count = tree.countByLocation(location, bst.getRoot(), color);
      outFile << "The " << location << " has " << count << " quakes." << std::endl;
    } else if (option == "CountTreeInStyle") {
      inFile >> color;
      inFile >> color2;
      count = tree.countWithStyle(bst.getRoot(), color, color2);
      outFile << "The tree has " << count << " quakes." << std::endl;
    } else if (option == "ResetVisualization") {
      tree.resetVisualization(bst.getRoot());
    } else if (option == "Visualize") {
      bridges.setDataStructure(bst.getRoot());
      bridges.visualize();
      outFile << "Tree was visualized." << std::endl;
    } else if (option == "BuildTree") {
      inFile >> count;
      vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(count);
      for (int k = 0; k < count; k++) {
        EarthquakeUSGS eq = eq_list[k];
        bst.insert(eq.getMagnitude(), eq);
      }
      outFile << count << " quakes have been added." << std::endl;
    } else if (option == "ResetTree") {
      bst.clear();
      outFile << "Tree has been reset." << std::endl;
    } else {
      std::cout << option << " is not a valid command." << std::endl;
    }
    numOptions++;
    std::cout << " Command number " << numOptions << " completed." << std::endl;
    inFile >> option;
  };

  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
  inFile.close();
  outFile.close();
}
