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
  TreeNode *actTree = root;
  while (actTree->info != value) {
    if (value < actTree->info && actTree->left != NULL) {
      outFile << actTree->info;
      actTree = actTree->left;
    } else if (value > actTree->info && actTree->right != NULL) {
      outFile << actTree->info;
      actTree = actTree->right;
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
  TreeNode *actTree = tree;
  ItemType befValue;
  while (actTree->info != value) {
    if (value < actTree->info && actTree->left != NULL) {
      befValue = actTree->info;
      actTree = actTree->left;
    } else if (value > actTree->info && actTree->right != NULL) {
      befValue = actTree->info;
      actTree = actTree->right;
    }
  }
  outFile << befValue;
  PrintAncestorsReverse(tree, befValue, outFile);
}