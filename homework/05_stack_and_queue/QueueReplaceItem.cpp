/*************************************************************************
 *
 * Assignment: ReplaceItemQueue
 *
 * File Name: ReplaceItemQueue.cpp
 * Name:        Elon Bontemps
 * Course:      CPTR 242
 * Date:        May the 4th be with you
 */
#include "QueueType.h"
#include <cmath>
#include <iostream>

void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  if (this->IsEmpty()) {
    return;
  }

  void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    QueueType tempQ;
    while (!this->IsEmpty()) {
      ItemType item;
      this->Dequeue(item);
      if (item == oldItem) {
        item = newItem;
      }
      tempQ.Enqueue(item);
      void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
        QueueType tempQ;
        while (!this->IsEmpty()) {
          ItemType item;
          this->Dequeue(item);
          if (item == oldItem) {
            item = newItem;
          }
          tempQ.Enqueue(item);
        }

        while (!tempQ.IsEmpty()) {
          ItemType item;
          tempQ.Dequeue(item);
          this->Enqueue(item);
        }
      }
