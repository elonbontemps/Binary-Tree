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


void BinarySearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
    // locates the size of list and splits it in half
    int a = list.size() - 1;
    int b = 0;
    int c = 0;
    initLocation = -1;
    initcompare = 0;

    while (a >= c) {
        ++comparisons;
        b = (a + 1) / 2;
        switch (key.ComparedTo(list.at(b))) {
            case LESS:
                a = b - 1;
                break;
            case GREATER:
                c = b + 1;
                break;
            case EQUAL:
                initLocation = b;
                return;
        }
    }
}
