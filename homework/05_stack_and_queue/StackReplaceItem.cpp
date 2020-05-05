/*************************************************************************
 *
 * Assignment: ReplaceItemStack
 *
 * File Name: ReplaceItemStack.cpp
 * Name:        Elon Bontemps
 * Course:      CPTR 242
 * Date:        May the 4th be with you
 */
#include "StackType.h"
#include <iostream>
void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  if (this->IsEmpty()) {
    return;
  }

  StackType tempStack;
  while (!this->IsEmpty()) {
    ItemType item = this->Top();
    this->Pop();
    if (item == oldItem) {
      item = newItem;
    }
    tempStack.Push(item);
  }

  while (!tempStack.IsEmpty()) {
    ItemType item = tempStack.Top();
    tempStack.Pop();
    this->Push(item);
  }
}
