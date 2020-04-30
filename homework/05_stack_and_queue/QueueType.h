/*************************************************************************
 *
 * Assignment: QueueType header file
 *
 * File Name: QueueType.h
 * Course:    CPTR 242
 */
#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

class FullQueue {};

class EmptyQueue {};
typedef char ItemType;
class QueueType {
public:
  QueueType();
  // Class constructor.
  // Because there is a default constructor, the precondition
  // that the queue has been initialized is omitted.
  QueueType(int max);
  // Parameterized class constructor.
  ~QueueType();
  // Class destructor.
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: If (queue is full) FullQueue exception is thrown
  //       else newItem is at rear of queue.
  void Dequeue(ItemType &item);
  // Function: Removes front item from the queue and returns it in item.
  // Post: If (queue is empty) EmptyQueue exception is thrown
  //       and item is undefined
  //       else front element has been removed from queue and
  //       item is a copy of removed element.
  void ReplaceItem(ItemType oldItem, ItemType newItem);
  // Function: Replaces item in
private:
  int front;
  int rear;
  ItemType *items;
  int maxQue;
};

#endif
