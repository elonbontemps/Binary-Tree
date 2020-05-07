/****************************************************************************
 *
 * File Name:  PriorityQueueType.h
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
#ifndef PRIORITY_QUEUE_TYPE_H
#define PRIORITY_QUEUE_TYPE_H

// Definition of class PriorityQueueType, which represents the Priority Queue
// ADT
class FullPriorityQueue {};
class EmptyPriorityQueue {};
#include "Heap.h"

template <class ItemType> class PriorityQueueType {
public:
  PriorityQueueType(int); // parameterized class constructor
  ~PriorityQueueType();   // class destructor

  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.

  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)

  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)

  void EnqueueIterative(ItemType newItem);
  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPriorityQueue is
  // thrown;
  //       else newItem is in the queue.

  void DequeueIterative(ItemType &item);
  void Dequeue(ItemType &item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPriorityQueue is
  // thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
private:
  int length;
  HeapType<ItemType> items;
  int maxItems;
};

template <class ItemType>
PriorityQueueType<ItemType>::PriorityQueueType(int max) {
  maxItems = max;
  items.elements = new ItemType[max];
  length = 0;
}

template <class ItemType> void PriorityQueueType<ItemType>::MakeEmpty() {
  length = 0;
}

template <class ItemType> PriorityQueueType<ItemType>::~PriorityQueueType() {
  delete[] items.elements;
}

template <class ItemType>
void PriorityQueueType<ItemType>::DequeueIterative(ItemType &item) {
  // Post: element with highest priority has been removed
  //       from the queue; a copy is returned in item.
  if (length == 0)
    throw EmptyPriorityQueue();
  else {
    item = items.elements[0];
    items.elements[0] = items.elements[length - 1];
    length--;
    items.ReheapDownIterative(0, length - 1);
  }
}
template <class ItemType>
void PriorityQueueType<ItemType>::Dequeue(ItemType &item) {
  // Post: element with highest priority has been removed
  //       from the queue; a copy is returned in item.
  if (length == 0)
    throw EmptyPriorityQueue();
  else {
    item = items.elements[0];
    items.elements[0] = items.elements[length - 1];
    length--;
    items.ReheapDown(0, length - 1);
  }
}

template <class ItemType>
void PriorityQueueType<ItemType>::EnqueueIterative(ItemType newItem) {
  // Post: newItem is in the queue.
  if (length == maxItems)
    throw FullPriorityQueue();
  else {
    length++;
    items.elements[length - 1] = newItem;
    items.ReheapUpIterative(0, length - 1);
  }
}

template <class ItemType>
void PriorityQueueType<ItemType>::Enqueue(ItemType newItem) {
  // Post: newItem is in the queue.
  if (length == maxItems)
    throw FullPriorityQueue();
  else {
    length++;
    items.elements[length - 1] = newItem;
    items.ReheapUp(0, length - 1);
  }
}
template <class ItemType> bool PriorityQueueType<ItemType>::IsFull() const {
  // Post: Returns true if the queue is full; false, otherwise.
  return length == maxItems;
}

template <class ItemType> bool PriorityQueueType<ItemType>::IsEmpty() const {
  // Post: Returns true if the queue is empty; false, otherwise.
  return length == 0;
}

#endif // PRIORITY_QUEUE_TYPE_H