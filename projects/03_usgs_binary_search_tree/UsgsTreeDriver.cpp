/*************************************************************************
 *
 * Project: Test driver
 *
 * File Name: UsgsTreeDriver.cpp
 * Course:    CPTR 242
 */
#include "UsgsTreeTest.h"
#include <iostream>
#include <string>

int main() {
  std::string inFileName;  // input file external name
  std::string outFileName; // output file external name
  std::string outputLabel;

  // Prompt for file names, read file names, and prepare files
  std::cout << "Enter name of input command file; press return." << std::endl;
  std::cin >> inFileName;

  std::cout << "Enter name of output file; press return." << std::endl;
  std::cin >> outFileName;

  std::cout << "Enter name of test run; press return." << std::endl;
  std::cin >> outputLabel;

  UsgsTreeTest(inFileName, outFileName, outputLabel);
};
