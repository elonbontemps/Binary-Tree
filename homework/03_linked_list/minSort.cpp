/****************************************************************************
 *
 * Homework: Implement a two recursive functions on a linked unsorted list.
 *
 * File Name:  minSort.cpp
 * Name:       Elon Bontemps
 * Course:     CPTR 242
 * Date:       April 20, 2020
 *
 */
#include "ItemType.h"
#include "unsorted.h"

using namespace std;
// recursive function
NodeType *MinLoc(NodeType *list, NodeType *&minPtr) {
  if (list->info.ComparedTo(minPtr->info) == LESS) {
    minPtr = list;
  }
  if (list->next == NULL) {
    return minPtr;
  } else {
    return MinLoc(list->next, minPtr);
  }
}
// second recursive
void Sort(NodeType *list) {
  ItemType item;
  item.Initialize(9);
  NodeType *minPtr = new NodeType;
  minPtr->next = NULL;
  minPtr->info = item;
  ItemType min = MinLoc(list, minPtr)->info;

  if (min.ComparedTo(list->info) == LESS) {
    ItemType temp = list->info;
    list->info = minPtr->info;
    minPtr->info = temp;
  }
  // removes mini pointer
  if (list->next == NULL) {
    return;
  } else {
    Sort(list->next);
  }
}
