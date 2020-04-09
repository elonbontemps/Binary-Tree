/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchDriver.cpp
 * Course:    CPTR 242
 */
#include <string>

#include "SearchTest.h"

using namespace std;

int main() {
  string inFileName;  // input file external name
  string outFileName; // output file external name
  string outputLabel;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin >> inFileName;

  cout << "Enter name of output file; press return." << endl;
  cin >> outFileName;

  cout << "Enter name of test run; press return." << endl;
  cin >> outputLabel;

  searchDriver(inFileName, outFileName, outputLabel);
};
