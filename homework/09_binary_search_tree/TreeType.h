/****************************************************************************
 *
 * File Name:  TreeType.h
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
#ifndef TREE_TYPE_H
#define TREE_TYPE_H

#include "QueueType.h"
#include <fstream>
#include <string>

typedef char ItemType;

struct TreeNode {
  ItemType info;
  TreeNode *left;
  TreeNode *right;
};

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };
class TreeType {
public:
  TreeType();  // constructor
  ~TreeType(); // destructor
  TreeType(const TreeType &originalTree);
  void operator=(const TreeType &originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const;
  ItemType GetItem(ItemType item, bool &found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  ItemType GetNextItem(OrderType order, bool &finished);
  void Print(std::ofstream &outFile) const;

  void AncestorsIterative(ItemType value, std::ofstream &outFile);
  // Post: The ancestors of the node whose info member is value have been
  // printed.
  void AncestorsRecursive(ItemType value, std::ofstream &outFile);
  void AncestorsReverse(ItemType value, std::ofstream &outFile);

private:
  TreeNode *root;
  QueueType preQue;
  QueueType inQue;
  QueueType postQue;
};

#endif // TREE_TYPE_H