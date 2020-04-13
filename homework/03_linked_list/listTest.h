/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchTest.h
 * Course:    CPTR 242
 */
#include "unsorted.h"
#include <fstream>
#include <string>

void PrintList(ofstream &outFile, UnsortedType &list);

void listTest(std::string inFileName, std::string outFileName,
                std::string outputLabel);
