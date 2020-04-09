/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name: LinearSearch.h
 * Course:    CPTR 242
 */
#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "vector"

#include "ItemType.h"
// File ItemType.h must be provided by the user of this class.
//  ItemType.h must contain the following definitions:
//  MAX_ITEMS:     the maximum number of items on the list
//  ItemType:      the definition of the objects on the list
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns
//       LESS, if self "comes before" item
//       GREATER, if self "comes after" item
//       EQUAL, if self and item are the same

class LinearSearch {
public:
  static void Search(std::vector<ItemType> list, ItemType key, int &location,
                     int &comparisons);
  // Function: Linear search a vector for key and count the number of
  // comparisons.
  // Pre:     List has been initialized.
  // Post:    Function location is non negative if the key exists and
  // comparisons has the number comparisons made during the search.
};
#endif // LINEAR_SEARCH_H
