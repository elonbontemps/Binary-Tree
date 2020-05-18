/*************************************************************************
 *
 * Project: UsgsTree implementation
 *
 * File Name: UsgsTree.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include "UsgsTree.h"
#include "BSTElement.h"
#include "Bridges.h"
#include "DataSource.h"
#include "bst.h"
#include "data_src/EarthquakeUSGS.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace bridges;

// Function: Finds the smallest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The smallest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getLargestQuake(BSTElement<float, EarthquakeUSGS> *root,
                          string color) {
  return nullptr;
}

// Function: Finds the largest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The largest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getSmallestQuake(BSTElement<float, EarthquakeUSGS> *root,
                           string color) {
  return nullptr;
}

// Function: Finds all nodes in the BST that are between the min and max
// parameters. Pre:  BST has been initialized and populated. Post: Returns the
// number of quakes in this range and visualizes them.
int UsgsTree::countRange(float min, float max,
                         BSTElement<float, EarthquakeUSGS> *root,
                         string color) {
  return 0;
}

// Function:  Finds all nodes in the BST that in the specified location.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in this location and visualizes them.
int UsgsTree::countByLocation(string location,
                              BSTElement<float, EarthquakeUSGS> *root,
                              string color) {
  return 0;
}

// Function: Updates all nodes and edges with a visualization.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in the BST and visualizes them.
int UsgsTree::countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                             string colorVertex, string colorEdge) {
  return 0;
}

// Function: Resets the BST visualization back to the defaults.
// Pre:  BST has been initialized and populated.
// Post: The BST has no visualizations.
void UsgsTree::resetVisualization(BSTElement<float, EarthquakeUSGS> *root) {}
