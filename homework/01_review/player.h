/*************************************************************************
 *
 * Assignment 1: high score manager
 *
 * File Name: player.h
 * Course:    CPTR 242
 * Date:      April 2, 2019
 */

#include <iostream>
#include <string>
using namespace std;

class Player {
  private:
    string name;
    int score;

  public:
    Player();
    Player(int newScore, string newname);
    void setName(string newName);
    void setScore(int newScore);
    string getName();
    int getScore();
};
