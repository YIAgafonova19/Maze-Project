#pragma once

struct MazeCell {
	bool visited;
	bool top;
	bool right;
	bool bottom;
	bool left;
};

bool hasUnvisitedNeighbours(int row, int col);
void chooseUnvisitedNeighbour();
void removeWallBetween(int currentRow, int currentCol, int neighbourRow, int neighbourCol);
void generateMaze(int row, int col);
void drawMaze();
void destroyMaze();
int getMazeSize();
bool mazeCellHasTopWall(int row, int col);
bool mazeCellHasBottomWall(int row, int col);
bool mazeCellHasLeftWall(int row, int col);
bool mazeCellHasRightWall(int row, int col);

void buildMaze(int size);
void drawMaze();
void destroyMaze();
int getMazeSize();
bool mazeCellHasTopWall(int row, int col);
bool mazeCellHasBottomWall(int row, int col);
bool mazeCellHasLeftWall(int row, int col);
bool mazeCellHasRightWall(int row, int col);
void removeWallBetween(int currentRow, int currentCol, int neighbourRow, int neighbourCol);

bool isMazeCellTucked(int row, int col);