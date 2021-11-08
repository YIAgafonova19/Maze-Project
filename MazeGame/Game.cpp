#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Maze.h"
#include "Player.h"
#include "Score.h"
#include "Keys.h"
#include "FrontEndHelpers.h"

using namespace std;

bool inGame;
bool isWin;
char gameKeyPressed;
int mazeSizes[] = { 10, 15, 20 };
int currentDifficulty;

//This function takes the current difficulty according to the level the player chose
int getCurrentDifficulty() {
	return currentDifficulty;
}

//This function checks if the player pressed a key and takes action accordingly
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
			isWin = false;
			break;
		default:
			break;
    }
}

//This function draws the Win screen
void drawGameEnd(bool isWin) {
	system("CLS");
	if (isWin) {
		setColor(11);
		cout << "          _______                           _________ _       \n";
		cout << "|\\     /|(  ___  )|\\     /|        |\\     /|\\__   __/( (    /|\n";
		cout << "( \\   / )| (   ) || )   ( |        | )   ( |   ) (   |  \\  ( |\n";
		cout << " \\ (_) / | |   | || |   | |        | | _ | |   | |   |   \\ | |\n";
		cout << "  \\   /  | |   | || |   | |        | |( )| |   | |   | (\\ \\) |\n";
		cout << "   ) (   | |   | || |   | |        | || || |   | |   | | \\   |\n";
		cout << "   | |   | (___) || (___) |        | () () |___) (___| )  \\  |\n";
		cout << "   \\_/   (_______)(_______)        (_______)\\_______/|/    )_)\n";
		cout << "\n\n";

		system("PAUSE");
		system("CLS");
	}
}

//This is the main function of the game
void playGame(int difficulty) {
	system("CLS");

	currentDifficulty = difficulty;

	buildMaze(mazeSizes[difficulty]);
	generateKeys();
	initPlayer();
	initPlayerScore();

	inGame = true;
	drawMaze();
	drawKeys();
	while (inGame) {
		drawPlayer();
		drawScore();

		gameKeyPressed = _getch();

		processPlayerInput();

		if (checkIfPlayerIsOnKey()) {
			takeKey();
		}

		if (checkFinalCondition()) {
			setFinalScore();
			inGame = false;
			isWin = true;
		}
	}

	destroyMaze();
	destroyPlayer();
	destroyScore();

	drawGameEnd(isWin);
}