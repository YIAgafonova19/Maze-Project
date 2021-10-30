#pragma once

#define PLAYER_MOVE_DIRECTION_UP 0
#define PLAYER_MOVE_DIRECTION_DOWN 1
#define PLAYER_MOVE_DIRECTION_LEFT 2
#define PLAYER_MOVE_DIRECTION_RIGHT 3

void initPlayer();
void drawPlayer();
void movePlayer(int direction);
void destroyPlayer();

bool checkFinalCondition();
int getPlayerCol();
int getPlayerRow();