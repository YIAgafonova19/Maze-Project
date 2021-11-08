#include <iostream>

#include "Score.h"
#include "Game.h"
#include "Keys.h"
#include "FrontEndHelpers.h"

using namespace std;

int playerScore;
int bestScore[] = { 50, 80, 100 };

//This function initializes the score of the player
void initPlayerScore() {
	playerScore = 0;
}

//This function adds 1 to the current score of the player
void setScore() {
	playerScore++;
}

//This function draws the Leaderboard menu of the game
void drawLeaderboard() {
	system("CLS");

	setColor(11); gotoxy(0, 0);
	cout << " _        _______  _______  ______   _______  _______  ______   _______  _______  _______  ______  " << endl;
	cout << "( \\      (  ____ \\(  ___  )(  __  \\ (  ____ \\(  ____ )(  ___ \\ (  ___  )(  ___  )(  ____ )(  __  \\ " << endl;
	cout << "| (      | (    \\/| (   ) || (  \\  )| (    \\/| (    )|| (   ) )| (   ) || (   ) || (    )|| (  \\  )" << endl;
	cout << "| |      | (__    | (___) || |   ) || (__    | (____)|| (__/ / | |   | || (___) || (____)|| |   ) |" << endl;
	cout << "| |      |  __)   |  ___  || |   | ||  __)   |     __)|  __ (  | |   | ||  ___  ||     __)| |   | |" << endl;
	cout << "| |      | (      | (   ) || |   ) || (      | (\\ (   | (  \\ \\ | |   | || (   ) || (\\ (   | |   ) |" << endl;
	cout << "| (____/\\| (____/\\| )   ( || (__/  )| (____/\\| ) \\ \\__| )___) )| (___) || )   ( || ) \\ \\__| (__/  )" << endl;
	cout << "(_______/(_______/|/     \\|(______/ (_______/|/   \\__/|/ \\___/ (_______)|/     \\||/   \\__/(______/" << endl << endl;

	cout << "Easy level best score: " << bestScore[DIFFICULTY_EASY] << endl;
	cout << "Medium level best score: " << bestScore[DIFFICULTY_MEDIUM] << endl;
	cout << "Hard level best score: " << bestScore[DIFFICULTY_HARD] << endl;

	system("PAUSE");
	system("CLS");
}

//This function checks if the player's score is higher than the current best score on the according level and sets it as the new best if it better
void setFinalScore() {
	if (playerScore < bestScore[getCurrentDifficulty()]) {
		bestScore[getCurrentDifficulty()] = playerScore;
	}
}

//This function draws the score on the console
void drawScore() {
	gotoxy(0, 0); cout << "Key count: " << getPlayerKeys() << " / Current score: " << playerScore << " / Best score: " << bestScore[getCurrentDifficulty()];
}

//This function is part of our future ideas and will destroy the score when written with dynamic memory
void destroyScore() {
	// TODO
}