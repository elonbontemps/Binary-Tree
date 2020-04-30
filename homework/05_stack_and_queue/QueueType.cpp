/*************************************************************************
 *
 * Assignment: QueueType implementation file
 *
 * File Name: QueueType.cpp
 * Course:    CPTR 242
 */

#include "QueueType.h"

// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
QueueType::QueueType(int max) {
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}

// Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
QueueType::QueueType() {
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}

// Class destructor
QueueType::~QueueType() { delete[] items; }

// Post: front and rear have been reset to the empty state.
void QueueType::MakeEmpty() {
  front = maxQue - 1;
  rear = maxQue - 1;
}

// Returns true if the queue is empty; false otherwise.
bool QueueType::IsEmpty() const { return (rear == front); }

// Returns true if the queue is full; false otherwise.
bool QueueType::IsFull() const { return ((rear + 1) % maxQue == front); }

// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
void QueueType::Enqueue(ItemType newItem) {
  if (IsFull()) {
    throw FullQueue();
  } else {
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
  }
}

// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
void QueueType::Dequeue(ItemType &item) {
  if (IsEmpty())
    throw EmptyQueue();
  else {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}
