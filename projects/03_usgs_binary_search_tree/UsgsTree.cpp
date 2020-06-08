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
  BSTElement<float, EarthquakeUSGS> *temp;
  std::queue<BSTElement<float, EarthquakeUSGS> *> rootQueue;
  std::set<BSTElement<float, EarthquakeUSGS> *> discoveredSet;
  rootQueue.push(root);
  discoveredSet.emplace(root);

  while (!rootQueue.empty()) {
    root = rootQueue.front();
    rootQueue.pop();
    temp = root;
    while (temp->getLeft() != NULL) {
      temp = temp->getLeft();
      if (temp->getRight() != NULL) {
        rootQueue.push(temp);
      }
      if (discoveredSet.find(temp) == discoveredSet.end()) {
        discoveredSet.emplace(temp);
      }
    }
    temp = root;
    while (temp->getRight() != NULL) {
      temp = temp->getRight();
      if (temp->getLeft() != NULL) {
        rootQueue.push(temp);
      }
      if (discoveredSet.find(temp) == discoveredSet.end()) {
        discoveredSet.emplace(temp);
      }
    }
  }

  int count = 0;
  for (BSTElement<float, EarthquakeUSGS> *node : discoveredSet) {
    if (node->getValue().getMagnitude() >= min &&
        node->getValue().getMagnitude() <= max) {
      count++;
      node->setColor(Color(color));
    }
  }
  return count;
}

int UsgsTree::countByLocation(string location,
                              BSTElement<float, EarthquakeUSGS> *root,
                              string color) {
  return 0;
}

int UsgsTree::countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                             string colorVertex, string colorEdge) {
  int count = 0;
  stack<BSTElement<float, EarthquakeUSGS> *> stack;
  BSTElement<float, EarthquakeUSGS> *curNode = root;

  while (!stack.empty() || curNode != nullptr) {
    if (curNode != nullptr) {
      stack.push(curNode);
      curNode = curNode->getLeft();
    } else {
      curNode = stack.top();
      stack.pop();
      curNode->getVisualizer()->setColor(colorVertex);
      if (curNode->getLeft() != NULL) {
        curNode->getLinkVisualizer(curNode->getLeft())->setColor(colorEdge);
      }
      if (curNode->getRight() != NULL) {
        curNode->getLinkVisualizer(curNode->getRight())->setColor(colorEdge);
      }
      ++count;
      curNode = curNode->getRight();
    }
  }
  return count;
}

void UsgsTree::resetVisualization(BSTElement<float, EarthquakeUSGS> *root) {
  BSTElement<float, EarthquakeUSGS> *temp;
  std::queue<BSTElement<float, EarthquakeUSGS> *> rootQueue;
  std::set<BSTElement<float, EarthquakeUSGS> *> discoveredSet;
  rootQueue.push(root);

  while (!rootQueue.empty()) {
    root = rootQueue.front();
    rootQueue.pop();
    temp = root;
    while (temp->getLeft() != NULL) {
      temp->setColor(Color("green"));
      temp->getLinkVisualizer(temp->getLeft())->setColor(Color("green"));
      temp = temp->getLeft();
      if (temp->getRight() != NULL) {
        rootQueue.push(temp);
      }
    }
    temp->setColor(Color("green"));
    temp = root;
    while (temp->getRight() != NULL) {
      temp->setColor(Color("green"));
      temp->getLinkVisualizer(temp->getRight())->setColor(Color("green"));
      temp = temp->getRight();
      if (temp->getLeft() != NULL) {
        rootQueue.push(temp);
      }
    }
    temp->setColor(Color("green"));
  }
}
