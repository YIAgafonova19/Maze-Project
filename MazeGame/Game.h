#pragma once

#define DIFFICULTY_EASY 0
#define DIFFICULTY_MEDIUM 1
#define DIFFICULTY_HARD 2

int getCurrentDifficulty();
void playGame(int difficulty);