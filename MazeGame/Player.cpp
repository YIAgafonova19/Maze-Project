#include <iostream>

#include "Player.h"
#include "Maze.h"
#include "Score.h"
#include "FrontEndHelpers.h"

using namespace std;

int playerCol, playerRow;
int lastPlayerCol, lastPlayerRow;
int playerMoves;

void drawPlayer();
void initPlayer();
bool checkFinalCondition();

void initPlayer() {
	playerCol = 0;
	playerRow = 0;
	playerMoves = 0;
	lastPlayerCol = 0;
	lastPlayerRow = 0;
}

void drawPlayer() {
	gotoxy(1 + lastPlayerCol * 5, 2 + lastPlayerRow * 2); cout << "    ";
	gotoxy(1 + playerCol * 5, 2 + playerRow * 2); setColor(6); cout << "<==>";
}

void movePlayer(int direction) {
	lastPlayerRow = playerRow;
	lastPlayerCol = playerCol;
	switch (direction) {
		case (0):
			if (!mazeCellHasTopWall(playerRow, playerCol)) {
				playerRow -= 1;
				setScore();
			}
			break;
		case (1):
			if (!mazeCellHasBottomWall(playerRow, playerCol)) {
				playerRow += 1;
				setScore();
			}
			break;
		case (2):
			if (!mazeCellHasLeftWall(playerRow, playerCol)) {
				playerCol -= 1;
				setScore();
			}
			break;
		case (3):
			if (!mazeCellHasRightWall(playerRow, playerCol)) {
				playerCol += 1;
				setScore();
			}
			break;
		default:
			break;
	}
}

bool checkFinalCondition() {
	return ((playerCol == getMazeSize() - 1) && (playerRow == getMazeSize() - 1));
}

void destroyPlayer() {
	// TODO
}