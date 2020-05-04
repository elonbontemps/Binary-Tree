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
  ItemType temp[MAX_ITEMS];
  int tempTop = top;
