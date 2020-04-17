/*************************************************************************
 *
 * Project 1: BridgesUser header file
 *
 * File Name: BridgesUser.h
 * Course:    CPTR 242
 * Date:      April 17, 2019
 */
#include <string>

using namespace bridges;

#ifndef BRIDGES_USER_H
#define BRIDGES_USER_H

class BridgesUser {
private:
  unsigned int BridgesNumber;
  string BridgesUserID;
  string BridgesAPIKey;

public:
  BridgesUser() {
    BridgesNumber = 2421;
    BridgesUserID = "";
    BridgesAPIKey = "";
  }
  unsigned int getBridgesNumber() const { return BridgesNumber; }
  string getBridgesUserID() const { return BridgesUserID; }
  string getBridgesAPIKey() const { return BridgesAPIKey; }
};

#endif // BRIDGES_USER_H
