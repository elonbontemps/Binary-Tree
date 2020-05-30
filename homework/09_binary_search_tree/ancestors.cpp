/****************************************************************************
 *
 * Homework: Implement a three functions for printing tree ancestors.
 *
 * File Name:  ancestors.cpp
 * Name:       Elon Bontemps
 * Course:     CPTR 242
 * Date:       June 1, 2020
 *
 */
#include "TreeType.h"

void TreeType::AncestorsIterative(ItemType value, std::ofstream &outFile) {
  // Iterative Ancestors
  TreeNode *tempTree = root;
  while (tempTree->info != value) {
    if (value < tempTree->info && tempTree->left != NULL) {
      outFile << tempTree->info;
      tempTree = tempTree->left;
    } else if (value > tempTree->info && tempTree->right != NULL) {
      outFile << tempTree->info;
      tempTree = tempTree->right;
    }
  }
}

void PrintAncestorsRecursive(TreeNode *tree, ItemType value,
                             std::ofstream &outFile) {
  // Recursive Ancestors
  if (tree->info == value) {
    return;
  }
  if (value < tree->info && tree->left != NULL) {
    outFile << tree->info;
    tree = tree->left;
    PrintAncestorsRecursive(tree, value, outFile);
  } else if (value > tree->info && tree->right != NULL) {
    outFile << tree->info;
    tree = tree->right;
    PrintAncestorsRecursive(tree, value, outFile);
  }
}

void PrintAncestorsReverse(TreeNode *tree, ItemType value,
                           std::ofstream &outFile) {
  // Recursive Ancestors
  if (tree->info == value) {
    return;
  }
  TreeNode *tempTree = tree;
  ItemType prevValue;
  while (tempTree->info != value) {
    if (value < tempTree->info && tempTree->left != NULL) {
      prevValue = tempTree->info;
      tempTree = tempTree->left;
    } else if (value > tempTree->info && tempTree->right != NULL) {
      prevValue = tempTree->info;
      tempTree = tempTree->right;
    }
  }
  outFile << prevValue;
  PrintAncestorsReverse(tree, prevValue, outFile);
}