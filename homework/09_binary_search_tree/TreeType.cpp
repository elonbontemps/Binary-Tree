/****************************************************************************
 *
 * File Name:  TreeType.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
#include "TreeType.h"
#include "ancestors.h"

// Returns true if there is no room for another item
//  on the free store; false otherwise.
bool TreeType::IsFull() const {
  TreeNode *location;
  try {
    location = new TreeNode;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

// Returns true if the tree is empty; false otherwise.
bool TreeType::IsEmpty() const { return root == NULL; }

int CountNodes(TreeNode *tree);

// Calls recursive function CountNodes to count the
// nodes in the tree.
int TreeType::GetLength() const { return CountNodes(root); }

// Post: returns the number of nodes in the tree.
int CountNodes(TreeNode *tree) {
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode *tree, ItemType &item, bool &found);

// Calls recursive function Retrieve to search the tree for item.
ItemType TreeType::GetItem(ItemType item, bool &found) {
  Retrieve(root, item, found);
  return item;
}

// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise found is false and item is unchanged.
void Retrieve(TreeNode *tree, ItemType &item, bool &found) {
  if (tree == NULL)
    found = false; // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found); // Search right subtree.
  else {
    item = tree->info; // item is found.
    found = true;
  }
}

void Insert(TreeNode *&tree, ItemType item);

// Calls recursive function Insert to insert item into tree.
void TreeType::PutItem(ItemType item) { Insert(root, item); }

// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
void Insert(TreeNode *&tree, ItemType item) {
  if (tree == NULL) { // Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  } else if (item < tree->info)
    Insert(tree->left, item); // Insert in left subtree.
  else
    Insert(tree->right, item); // Insert in right subtree.
}
void DeleteNode(TreeNode *&tree);

void Delete(TreeNode *&tree, ItemType item);

// Calls recursive function Delete to delete item from tree.
void TreeType::DeleteItem(ItemType item) { Delete(root, item); }

// Deletes item from tree.
// Post:  item is not in tree.
void Delete(TreeNode *&tree, ItemType item) {
  if (item < tree->info)
    Delete(tree->left, item); // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item); // Look in right subtree.
  else
    DeleteNode(tree); // Node found; call DeleteNode.
}

void GetPredecessor(TreeNode *tree, ItemType &data);

// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
void DeleteNode(TreeNode *&tree) {
  ItemType data;
  TreeNode *tempPtr;

  tempPtr = tree;
  if (tree->left == NULL) {
    tree = tree->right;
    delete tempPtr;
  } else if (tree->right == NULL) {
    tree = tree->left;
    delete tempPtr;
  } else {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data); // Delete predecessor node.
  }
}

// Sets data to the info member of the right-most node in tree.
void GetPredecessor(TreeNode *tree, ItemType &data) {
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

// Prints info member of items in tree in sorted order on outFile.
void PrintTree(TreeNode *tree, std::ofstream &outFile) {
  if (tree != NULL) {
    PrintTree(tree->left, outFile); // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile); // Print right subtree.
  }
}

// Calls recursive function Print to print items in the tree.
void TreeType::Print(std::ofstream &outFile) const { PrintTree(root, outFile); }

TreeType::TreeType() { root = NULL; }

void Destroy(TreeNode *&tree);

// Calls recursive function Destroy to destroy the tree.
TreeType::~TreeType() { Destroy(root); }

// Post: tree is empty; nodes have been deallocated.
void Destroy(TreeNode *&tree) {
  if (tree != NULL) {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty() {
  Destroy(root);
  root = NULL;
}

void CopyTree(TreeNode *&copy, const TreeNode *originalTree);

// Calls recursive function CopyTree to copy originalTree into root.
TreeType::TreeType(const TreeType &originalTree) {
  CopyTree(root, originalTree.root);
}

// Calls recursive function CopyTree to copy originalTree into root.
void TreeType::operator=(const TreeType &originalTree) {
  {
    if (&originalTree == this)
      return;      // Ignore assigning self to self
    Destroy(root); // Deallocate existing tree nodes
    CopyTree(root, originalTree.root);
  }
}

// Post: copy is the root of a tree that is a duplicate of originalTree.
void CopyTree(TreeNode *&copy, const TreeNode *originalTree) {
  if (originalTree == NULL)
    copy = NULL;
  else {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode *, QueueType &);
// Enqueues tree items in preorder.

void InOrder(TreeNode *, QueueType &);
// Enqueues tree items in inorder.

void PostOrder(TreeNode *, QueueType &);
// Enqueues tree items in postorder.

// Calls function to create a queue of the tree elements in
// the desired order.
void TreeType::ResetTree(OrderType order) {
  switch (order) {
  case PRE_ORDER:
    PreOrder(root, preQue);
    break;
  case IN_ORDER:
    InOrder(root, inQue);
    break;
  case POST_ORDER:
    PostOrder(root, postQue);
    break;
  }
}

// Post: preQue contains the tree items in preorder.
void PreOrder(TreeNode *tree, QueueType &preQue) {
  if (tree != NULL) {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}

// Post: inQue contains the tree items in inorder.
void InOrder(TreeNode *tree, QueueType &inQue) {
  if (tree != NULL) {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}

// Post: postQue contains the tree items in postorder.
void PostOrder(TreeNode *tree, QueueType &postQue) {
  if (tree != NULL) {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}

// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true;
//       otherwise finished is false.
ItemType TreeType::GetNextItem(OrderType order, bool &finished) {
  finished = false;
  ItemType item;
  switch (order) {
  case PRE_ORDER:
    preQue.Dequeue(item);
    if (preQue.IsEmpty())
      finished = true;
    break;
  case IN_ORDER:
    inQue.Dequeue(item);
    if (inQue.IsEmpty())
      finished = true;
    break;
  case POST_ORDER:
    postQue.Dequeue(item);
    if (postQue.IsEmpty())
      finished = true;
    break;
  }
  return item;
}

// Calls recursive function PrintAncestors to print the ancestors.
void TreeType::AncestorsRecursive(ItemType value, std::ofstream &outFile) {
  PrintAncestorsRecursive(root, value, outFile);
}

// Calls recursive function PrintAncestors to print the ancestors.
void TreeType::AncestorsReverse(ItemType value, std::ofstream &outFile) {
  PrintAncestorsReverse(root, value, outFile);
}
