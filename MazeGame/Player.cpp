#include <iostream>

#include "Player.h"
#include "Maze.h"
#include "Score.h"
#include "Keys.h"
#include "FrontEndHelpers.h"

using namespace std;

int playerCol, playerRow;
int lastPlayerCol, lastPlayerRow;
int playerMoves;

// initializes a player
void initPlayer() {
	playerCol = 0;
	playerRow = 0;
	playerMoves = 0;
	lastPlayerCol = 0;
	lastPlayerRow = 0;
}

// draws the player in the console
void drawPlayer() {
	gotoxy(1 + lastPlayerCol * 5, 2 + lastPlayerRow * 2); cout << "    ";
	gotoxy(1 + playerCol * 5, 2 + playerRow * 2); setColor(6); cout << "<==>";
}

// moves the player in a direction according to which key the player pressed
void movePlayer(int direction) {
	lastPlayerRow = playerRow;
	lastPlayerCol = playerCol;
	switch (direction) {
		case (PLAYER_MOVE_DIRECTION_UP):
			if (!mazeCellHasTopWall(playerRow, playerCol)) {
				playerRow -= 1;
				setScore();
			} else {
				if ((getPlayerRow() != 0) && (getPlayerKeys() > 0)) {
					useKey();

					removeWallBetween(getPlayerRow(), getPlayerCol(), getPlayerRow() - 1, getPlayerCol());

					playerRow -= 1;
					setScore();
				}
			}
			break;
		case (PLAYER_MOVE_DIRECTION_DOWN):
			if (!mazeCellHasBottomWall(playerRow, playerCol)) {
				playerRow += 1;
				setScore();
			} else {
				if ((getPlayerRow() != getMazeSize() - 1) && (getPlayerKeys() > 0)) {
					useKey();

					removeWallBetween(getPlayerRow(), getPlayerCol(), getPlayerRow() + 1, getPlayerCol());

					playerRow += 1;
					setScore();
				}
			}
			break;
		case (PLAYER_MOVE_DIRECTION_LEFT):
			if (!mazeCellHasLeftWall(playerRow, playerCol)) {
				playerCol -= 1;
				setScore();
			} else {
				if ((getPlayerCol() != 0) && (getPlayerKeys() > 0)) {
					useKey();

					removeWallBetween(getPlayerRow(), getPlayerCol(), getPlayerRow(), getPlayerCol() - 1);

					playerCol -= 1;
					setScore();
				}
			}
			break;
		case (PLAYER_MOVE_DIRECTION_RIGHT):
			if (!mazeCellHasRightWall(playerRow, playerCol)) {
				playerCol += 1;
				setScore();
			} else {
				if ((getPlayerCol() != getMazeSize() - 1) && (getPlayerKeys() > 0)) {
					useKey();

					removeWallBetween(getPlayerRow(), getPlayerCol(), getPlayerRow(), getPlayerCol() + 1);

					playerCol += 1;
					setScore();
				}
			}
			break;
		default:
			break;
	}
}

// takes the colomn the player is at 
int getPlayerCol() {
	return playerCol;
}

// takes the row the player is at
int getPlayerRow() {
	return playerRow;
}

// checks if the player has reached the end of the maze
bool checkFinalCondition() {
	return ((playerCol == getMazeSize()) && (playerRow == getMazeSize() - 1));
}

//This function is part of our future ideas and will destroy the player when written with dynamic memory
void destroyPlayer() {
	// TODO
}