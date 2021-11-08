#include <iostream>

#include "Keys.h"
#include "Maze.h"
#include "Game.h"
#include "Player.h"
#include "FrontEndHelpers.h"

using namespace std;

int currentKeysCount;
int key[20][2];
int maxKeysCount[] = { 2, 4, 8 };
int playerKeys;

//This function generates the coordinates of the keys
void generateKeys() {
	playerKeys = 0;
	currentKeysCount = 0;

	for (int row = 0; row < getMazeSize(); row++) {
		for (int col = 0; col < getMazeSize(); col++) {
			if ((isMazeCellTucked(row, col)) && ((row + col) > 0) && (rand() % 2 == 1)) {
				key[currentKeysCount][0] = row;
				key[currentKeysCount][1] = col;
				currentKeysCount++;

				if (maxKeysCount[getCurrentDifficulty()] == currentKeysCount) {
					return;
				}
			}
		}
	}
}

//This function draws the keys on the coordinates generated in the previous function
void drawKeys() {
	for (int k = 0; k < currentKeysCount; k++) {
		gotoxy(1 + key[k][1] * 5, 2 + key[k][0] * 2); setColor(14); cout << "0==+";
	}
}

//This function erases the key from the console
void eraseKey(int index) {
	gotoxy(1 + key[index][1] * 5, 2 + key[index][0] * 2); cout << "    ";
}

//This function checks if the player is at the same coordinates as a key
bool checkIfPlayerIsOnKey() {
	for (int i = 0; i < currentKeysCount; i++) {
		if ((key[i][0] == getPlayerRow()) && (key[i][1] == getPlayerCol())) {
			return true;
		}
	}

	return false;
}

//This function adds 1 to the sum of the keys the player got and erases the key from the console
void takeKey() {
	playerKeys++;

	for (int i = 0; i < currentKeysCount; i++) {
		if ((key[i][0] == getPlayerRow()) && (key[i][1] == getPlayerCol())) {
			eraseKey(i);
			currentKeysCount--;
			key[i][0] = key[currentKeysCount][0];
			key[i][1] = key[currentKeysCount][1];
		}
	}
}

//This function subtracts 1 from the sum of the keys the player got 
void useKey() {
	playerKeys--;
}

//This function returns the sum of the keys the player got
int getPlayerKeys() {
	return playerKeys;
}

//This function is part of our future ideas and will destroy the keys when written with dynamic memory
void destroyKey() {
	// TODO
}