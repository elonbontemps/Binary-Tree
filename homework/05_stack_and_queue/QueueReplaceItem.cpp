/*************************************************************************
 *
 * Assignment: ReplaceItemQueue
 *
 * File Name: ReplaceItemQueue.cpp
 * Name:        Elon Bontemps
 * Course:      CPTR 242
 * Date:        May 4th be with you
 */
#include "QueueType.h"
#include <cmath>
#include <iostream>

void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  if (this->IsEmpty()) {
    return;
  }

