#pragma once

void buildMaze(int size);
void drawMaze();
void destroyMaze();
int getMazeSize();
bool mazeCellHasTopWall(int row, int col);
bool mazeCellHasBottomWall(int row, int col);
bool mazeCellHasLeftWall(int row, int col);
bool mazeCellHasRightWall(int row, int col);