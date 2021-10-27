#include <iostream>

#include "Score.h"
#include "FrontEndHelpers.h"

using namespace std;

int playerScore;
int highestScore;

void initScore() {
	highestScore = 50;
}

void initPlayerScore() {
	playerScore = 0;
}

void setScore() {
	playerScore++;
}

void setFinalScore() {
	if (playerScore < highestScore) {
		highestScore = playerScore;
	}
}

void drawScore() {
	gotoxy(0, 0); cout << "Player score: " << playerScore << " / Highest score: " << highestScore;
}

void destroyScore() {
	// TODO
}