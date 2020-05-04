/*************************************************************************
 *
 * Assignment: Test driver for Stack
 *
 * File Name: StackTest.h
 * Course:    CPTR 242
 */
#include "StackType.h"
#include <fstream>
#include <string>

void PrintStack(std::ofstream &dataFile, StackType &queue);

void StackTest(std::string inFileName, std::string outFileName,
                std::string outputLabel);
