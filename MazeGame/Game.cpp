#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Maze.h"
#include "Player.h"
#include "Score.h"
#include "FrontEndHelpers.h"

using namespace std;

bool inGame;
char gameKeyPressed;
int mazeSizes[] = { 10, 15, 20 };
int currentDifficulty;

int getCurrentDifficulty() {
	return currentDifficulty;
}

void processPlayerInput() {
    switch (gameKeyPressed) {
		case(KEY_UP):
			movePlayer(PLAYER_MOVE_DIRECTION_UP);
			break;
		case(KEY_DOWN):
			movePlayer(PLAYER_MOVE_DIRECTION_DOWN);
			break;
		case(KEY_LEFT):
			movePlayer(PLAYER_MOVE_DIRECTION_LEFT);
			break;
		case(KEY_RIGHT):
			movePlayer(PLAYER_MOVE_DIRECTION_RIGHT);
			break;
		case(KEY_ESC):
			inGame = false;
			break;
		default:
			break;
    }
}

void playGame(int difficulty) {
	system("CLS");

	currentDifficulty = difficulty;

	buildMaze(mazeSizes[difficulty]);
	initPlayer();
	initPlayerScore();

	inGame = true;
	drawMaze();
	while (inGame) {
		drawPlayer();
		drawScore();

		gameKeyPressed = _getch();

		processPlayerInput();

		if (checkFinalCondition()) {
			setFinalScore();
			inGame = false;
		}
	}

	destroyMaze();
	destroyPlayer();
	destroyScore();

	system("CLS");
}