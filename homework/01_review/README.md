# CPTR 242: Homework Assignment #1

## Problem Overview

Write a program that manages a list of up to 10 players and their high scores in the computer’s memory.

## Description

A class named _Player_ has been given to you with the player’s name and score.
Use a dynamic array of the _Player_ class to store the players.
Start with a dynamic array that stores no players.
To add a player, create a new dynamic array that is one larger than the current size and copy the existing and the new player into it.
To remove a player, create a new dynamic array that is one smaller than the current size and copy all players into it except the player to remove.
Use the index of the arrays to correlate the name with the score.

## Solution Specification

Your program should support the following features:

1. Add a new player and score (up to 10 players).
    After ten, replace the lowest score.
2. Allow the user to enter a player name return player’s score or a -1  if the player’s name has not been entered.
3. Allow the user to enter a player name and remove the player from the list.

A main driver has been provided to allow a user to run test input.
The code can be compile by running the following command.

```sh
clang++ -Wall -o highscore.out -- main.cpp manager.cpp player.cpp
```

or

```sh
g++ -o highscore.out main.cpp manager.cpp player.cpp
```

To test the code, run this command:

```sh
./highscore.out < test.txt
```

## Submission

Your submission must include a _manager.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
