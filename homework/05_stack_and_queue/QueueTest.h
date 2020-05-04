/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchTest.h
 * Course:    CPTR 242
 */
#include "QueueType.h"
#include <fstream>
#include <string>

void PrintQueue(std::ofstream &dataFile, QueueType &queue);

void QueueTest(std::string inFileName, std::string outFileName,
                std::string outputLabel);
