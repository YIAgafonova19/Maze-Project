#include <iostream>

#include "Score.h"
#include "Game.h"
#include "Keys.h"
#include "FrontEndHelpers.h"

using namespace std;

int playerScore;
int bestScore[] = { 50, 80, 100 };

void initPlayerScore() {
	playerScore = 0;
}

void setScore() {
	playerScore++;
}

void drawLeaderboard() {
	system("CLS");

	setColor(11); gotoxy(0, 0);
	cout << "Leaderboard menu" << endl;
	cout << "Easy level best score: " << bestScore[DIFFICULTY_EASY] << endl;
	cout << "Medium level best score: " << bestScore[DIFFICULTY_MEDIUM] << endl;
	cout << "Hard level best score: " << bestScore[DIFFICULTY_HARD] << endl;

	system("PAUSE");
}

void setFinalScore() {
	if (playerScore < bestScore[getCurrentDifficulty()]) {
		bestScore[getCurrentDifficulty()] = playerScore;
	}
}

void drawScore() {
	gotoxy(0, 0); cout << "Key count: " << getPlayerKeys() << " / Current score: " << playerScore << " / Best score: " << bestScore[getCurrentDifficulty()];
}

void destroyScore() {
	// TODO
}