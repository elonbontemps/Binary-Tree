/*************************************************************************
 *
 * Assignment: ReplaceItemStack
 *
 * File Name: ReplaceItemStack.cpp
 * Name:        Elon Bontemps
 * Course:      CPTR 242
 * Date:        May 4, 2020
 */
#include "StackType.h"
#include <iostream>
void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  if (this->IsEmpty()) {
    return;
  }
  ItemType temp[MAX_ITEMS];
  int tempTop = top;
