/*************************************************************************
 *
 * Project: UsgsTree implementation
 *
 * File Name: UsgsTree.cpp
 * Name:      Elon Bontemps
 * Course:    CPTR 242
 * Date:      June 7, 2020
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

EarthquakeUSGS
UsgsTree::getLargestQuake(BSTElement<float, EarthquakeUSGS> *root,
                          string color) {
  while (root->getRight() != NULL) {
    root = root->getRight();
  }
  root->setColor(Color(color));
  return root->getValue();
}

EarthquakeUSGS
UsgsTree::getSmallestQuake(BSTElement<float, EarthquakeUSGS> *root,
                           string color) {
  while (root->getLeft() != NULL) {
    root = root->getLeft();
  }
  root->setColor(Color(color));
  return root->getValue();
}

int UsgsTree::countRange(float min, float max,
                         BSTElement<float, EarthquakeUSGS> *root,
                         string color) {
  if (root == NULL) {
    return 0;
  }

  int count = countRange(min, max, root->getLeft(), color);
  if (min <= root->getKey() && root->getKey() <= max) {
    root->getVisualizer()->setColor(Color(color));
    root->getVisualizer()->setSize(30);
    count += 1;
  }
  count += countRange(min, max, root->getRight(), color);

  return count;
}

int UsgsTree::countByLocation(string location,
                              BSTElement<float, EarthquakeUSGS> *root,
                              string color) {
  if (root == NULL) {
    return 0;
  }

  int count = countByLocation(location, root->getLeft(), color);
  if (root->getValue().getLocation().find(location) != -1) {
    root->getVisualizer()->setColor(Color(color));
    root->getVisualizer()->setSize(30);
    count += 1;
  }
  count += countByLocation(location, root->getRight(), color);

  return count;
}

int UsgsTree::countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                             string colorVertex, string colorEdge) {
  if (root == NULL) {
    return 0;
  }

  int count = countWithStyle(root->getLeft(), colorVertex, colorEdge);
  root->getVisualizer()->setColor(Color(colorVertex));
  vector<datastructure::TreeElement<dataset::EarthquakeUSGS> *,
         allocator<datastructure::TreeElement<dataset::EarthquakeUSGS> *>>
      &children = root->getChildren();
  for (auto child : children) {
    if (child != NULL) {
      root->getLinkVisualizer(child)->setColor(Color(colorEdge));
    }
  }
  count += 1;
  count += countWithStyle(root->getRight(), colorVertex, colorEdge);

  return count;
}

void UsgsTree::resetVisualization(BSTElement<float, EarthquakeUSGS> *root) {
  if (root == NULL) {
    return;
  }

  resetVisualization(root->getLeft());
  root->getVisualizer()->setColor(Color("green"));
  root->getVisualizer()->setSize(5);
  vector<datastructure::TreeElement<dataset::EarthquakeUSGS> *,
         allocator<datastructure::TreeElement<dataset::EarthquakeUSGS> *>>
      &children = root->getChildren();
  for (auto child : children) {
    if (child != NULL) {
      root->getLinkVisualizer(child)->setColor(Color("green"));
      root->getLinkVisualizer(child)->setThickness(1.);
    }
  }
  resetVisualization(root->getRight());
}
