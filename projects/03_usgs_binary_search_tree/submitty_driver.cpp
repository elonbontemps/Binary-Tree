/*************************************************************************
 *
 * Project: Submitty Grading
 *
 * File Name:   submitty_driver.cpp
 * Course:      CPTR 242
 *
 */
#include "UsgsTreeTest.h"
#include <iostream>

inline bool fileExists(const std::string &name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

int main(int argc, char *argv[]) {

  if (argc > 1 && *argv[1] == '1') {

    std::string input = "example_input.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test example search
    UsgsTreeTest(input, "solutions.txt", "ProvidedTests");

  } else if (argc > 1 && *argv[1] == '2') {

    std::string input = "submitty_input.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test example search
    UsgsTreeTest(input, "solutions.txt", "ProvidedTests");

  } else {
    std::cout << "Invalid test selected" << std::endl;
  }

  return 0;
}
