/*************************************************************************
 *
 * Project: UsgsTree header
 *
 * File Name: UsgsTree.h
 * Course:    CPTR 242
 */

#include "BSTElement.h"
#include "Bridges.h"
#include "DataSource.h"
#include "bst.h"
#include "data_src/EarthquakeUSGS.h"

using namespace bridges;

#ifndef USGS_TREE_H
#define USGS_TREE_H

class UsgsTree {
public:
  EarthquakeUSGS getSmallestQuake(BSTElement<float, EarthquakeUSGS> *root,
                                  string color);
  // Function: Finds the smallest quake magnitude in a BST.
  // Pre:  BST has been initialized and populated.
  // Post: The smallest quake will be visualized and returned.

  EarthquakeUSGS getLargestQuake(BSTElement<float, EarthquakeUSGS> *root,
                                 string color);
  // Function: Finds the largest quake magnitude in a BST.
  // Pre:  BST has been initialized and populated.
  // Post: The largest quake will be visualized and returned.

  int countRange(float min, float max, BSTElement<float, EarthquakeUSGS> *root,
                 string color);
  // Function: Finds all nodes in the BST that are between the min and max
  // parameters. Pre:  BST has been initialized and populated. Post: Returns the
  // number of quakes in this range and visualizes them.

  int countByLocation(string location, BSTElement<float, EarthquakeUSGS> *root,
                      string color);
  // Function:  Finds all nodes in the BST that in the specified location.
  // Pre:  BST has been initialized and populated.
  // Post: Returns the number of quakes in this location and visualizes them.

  int countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                     string colorVertex, string colorEdge);
  // Function: Updates all nodes and edges with a visualization.
  // Pre:  BST has been initialized and populated.
  // Post: Returns the number of quakes in the BST and visualizes them.

  void resetVisualization(BSTElement<float, EarthquakeUSGS> *root);
  // Function: Resets the BST visualization back to the defaults.
  // Pre:  BST has been initialized and populated.
  // Post: The BST has no visualizations.
};

#endif // USGS_TREE_H
