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
//recursive function
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

void Sort(NodeType *list) {


}
