/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   LinearSearch.cpp
 * Name:        Elon Bontemps
 * Course:      CPTR 242
 * Date:        April 13, 2020
 */
#include "ItemType.h"
#include "LinearSearch.h"

// Functions
void BinarySearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
    // locates the size of list and splits it in half
    int a = list.size() - 1;
    int b = 0;
    int c = 0;
    comparisons = 0;
    location = -1;


