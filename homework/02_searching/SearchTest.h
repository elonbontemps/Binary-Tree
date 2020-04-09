/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchTest.h
 * Course:    CPTR 242
 */
#include "ItemType.h"
#include <iostream>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<ItemType> &input);

void searchDriver(std::string inFileName, std::string outFileName,
                  std::string outputLabel);
