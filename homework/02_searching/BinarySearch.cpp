/*************************************************************************
 *
 * Assignment: Binary Search
 *
 * File Name:   BinarySearch.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "BinarySearch.h"
#include "ItemType.h"

//Function
void BinarySearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
  // locates the size of list and splits it in half
  int a = list.size() - 1;
  int b = 0;
  int c = 0;
  initLocation = -1;
  initcompare = 0;

  while (a >= c) {
    ++comparisons;
    b = (a + 1) / 2;
    switch (key.ComparedTo(list.at(b))) {
    case LESS:
      a = b - 1;
      break;
    case GREATER:
      c = b + 1;
      break;
    case EQUAL:
      initLocation = b;
      return;
    }
  }
}

