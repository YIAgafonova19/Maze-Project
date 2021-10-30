#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Maze.h"
#include "FrontEndHelpers.h"

using namespace std;

struct MazeCell {
	bool visited;
	bool top;
	bool right;
	bool bottom;
	bool left;
};

int mazeSize;
MazeCell** mazeCell;
int neighbourRow, neighbourCol;
int unvisitedNeighboursCount;
int unvisitedNeighbours[4][2];

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

int getMazeSize() {
	return mazeSize;
}

bool mazeCellHasTopWall(int row, int col) {
	return mazeCell[row][col].top;
}

bool mazeCellHasBottomWall(int row, int col) {
	return mazeCell[row][col].bottom;
}

bool mazeCellHasLeftWall(int row, int col) {
	return mazeCell[row][col].left;
}

bool mazeCellHasRightWall(int row, int col) {
	return mazeCell[row][col].right;
}

void buildMaze(int size) {
	mazeSize = size;
	mazeCell = new MazeCell * [mazeSize];
	for (int i = 0; i < mazeSize; i++) {
		mazeCell[i] = new MazeCell[mazeSize];
	}

	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			mazeCell[i][j].visited = false;
			mazeCell[i][j].top = true;
			mazeCell[i][j].right = true;
			mazeCell[i][j].bottom = true;
			mazeCell[i][j].left = true;
		}
	}

	mazeCell[0][0].left = true;
	mazeCell[mazeSize - 1][mazeSize - 1].right = false;

	generateMaze(0, 0);

	drawMaze();
}

bool hasUnvisitedNeighbours(int row, int col) {
	bool result = false;
	unvisitedNeighboursCount = 0;

	for (int i = 0; i < 3; i++) {
		unvisitedNeighbours[i][0] = -1;
		unvisitedNeighbours[i][1] = -1;
	}

	// checkTop
	if (row > 0) {
		if (!mazeCell[row - 1][col].visited) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row - 1;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col;
			unvisitedNeighboursCount++;
		}
	}
	// checkBottom
	if (row < mazeSize - 1) {
		if (!mazeCell[row + 1][col].visited) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row + 1;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col;
			unvisitedNeighboursCount++;
		}
	}
	// checkLeft
	if (col > 0) {
		if (!mazeCell[row][col - 1].visited) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col - 1;
			unvisitedNeighboursCount++;
		}
	}
	// checkRight
	if (col < mazeSize - 1) {
		if (!mazeCell[row][col + 1].visited) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col + 1;
			unvisitedNeighboursCount++;
		}
	}

	return result;
}

void chooseUnvisitedNeighbour() {
	int choosenUnvisitedNeighbour = rand() % unvisitedNeighboursCount + 1;
	neighbourRow = unvisitedNeighbours[choosenUnvisitedNeighbour - 1][0];
	neighbourCol = unvisitedNeighbours[choosenUnvisitedNeighbour - 1][1];
}

void removeWallBetween(int currentRow, int currentCol, int neighbourRow, int neighbourCol) {
	// checkForTopNeighbour
	if (currentRow == neighbourRow + 1) {
		mazeCell[currentRow][currentCol].top = false;
		mazeCell[neighbourRow][neighbourCol].bottom = false;
	}
	// checkForBottomNeighbour
	if (currentRow == neighbourRow - 1) {
		mazeCell[currentRow][currentCol].bottom = false;
		mazeCell[neighbourRow][neighbourCol].top = false;
	}
	// checkForLeftNeighbour
	if (currentCol == neighbourCol + 1) {
		mazeCell[currentRow][currentCol].left = false;
		mazeCell[neighbourRow][neighbourCol].right = false;
	}
	// checkForRightNeighbour
	if (currentCol == neighbourCol - 1) {
		mazeCell[currentRow][currentCol].right = false;
		mazeCell[neighbourRow][neighbourCol].left = false;
	}
}

void generateMaze(int row, int col) {
	//1. Given a current cell as a parameter
	//2. Mark the current cell as visited
		mazeCell[row][col].visited = true;
	//3. While the current cell has any unvisited neighbour cells
		while (hasUnvisitedNeighbours(row, col)) {
			//1. Choose one of the unvisited neighbours
			chooseUnvisitedNeighbour();
			//2. Remove the wall between the current cell and the chosen cell
			removeWallBetween(row, col, neighbourRow, neighbourCol);
			//3. Invoke the routine recursively for a chosen cell which is invoked once for any initial cell in the area.
			generateMaze(neighbourRow, neighbourCol);
		}
}

void drawMaze() {
	setColor(11);

	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			if (mazeCell[i][j].top) {
				gotoxy(1 + j * 5, 2 + i * 2 - 1); cout << "----";
			}
			if (mazeCell[i][j].bottom) {
				gotoxy(1 + j * 5, 2 + i * 2 + 1); cout << "----";
			}
			if (mazeCell[i][j].left) {
				gotoxy(1 + j * 5 - 1, 2 + i * 2); cout << "|";
			}
			if (mazeCell[i][j].right) {
				gotoxy(1 + j * 5 + 4, 2 + i * 2); cout << "|";
			}

			gotoxy(1 + j * 5 - 1, 2 + i * 2 - 1); cout << "+";
			gotoxy(1 + j * 5 - 1, 2 + i * 2 + 1); cout << "+";
			gotoxy(1 + j * 5 + 4, 2 + i * 2 - 1); cout << "+";
			gotoxy(1 + j * 5 + 4, 2 + i * 2 + 1); cout << "+";
		}
	}
	cout << endl;
}

void destroyMaze() {
	for (int i = 0; i < mazeSize; i++) {
		delete[] mazeCell[i];
	}
	delete[] mazeCell;
	mazeCell = NULL;
}