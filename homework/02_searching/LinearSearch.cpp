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


void LinearSearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
    initcomparisons = 0;
    initlocation = -1;

    for (int i = 0; i < list.size(); ++i) {
        ++initcomparisons;
        switch (key.ComparedTo(list.at(i))) {
            case LESS:
                return;
            case GREATER:
                break;
            case EQUAL:
                location = i;
                return;
        }
    }
}






