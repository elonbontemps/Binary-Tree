/****************************************************************************
 *
 * Homework 09: Implement ReheapDown and ReheapUp functions using iteration.
 *
 * File Name:  reheap.tpp
 * Name:       Elon Bontemps
 * Course:     CPTR 242
 * Date:       May 11, 2020
 * Time Taken: ?
 */
#include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
  int maxChild;
  int rightChild = root * 2 + 2;
  int leftChild = root * 2 + 1;
  for (int i = 0; i < numElements; i++) {
    if (leftChild <= bottom) {
      if (leftChild == bottom) {
        maxChild = leftChild;
      } else {
        if (elements[leftChild] <= elements[rightChild]) {
          maxChild = rightChild;
        } else {
          maxChild = leftChild;
        }
      }
      if (elements[root] < elements[maxChild]) {
        Swap(elements[root], elements[maxChild]);
        root = maxChild;
        rightChild = root * 2 + 2;
        leftChild = root * 2 + 1;
      }
    }
  }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
  int parent;

  for (int i = 0; i < numElements; i++) {
    if (bottom > root) {
      parent = (bottom - 1) / 2;
      if (elements[parent] < elements[bottom]) {
        Swap(elements[parent], elements[bottom]);
        bottom = parent;
      }
    }
  }
}

