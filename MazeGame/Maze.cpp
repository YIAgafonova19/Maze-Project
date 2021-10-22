#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Maze.h"
#include "FrontEndHelpers.h"

using namespace std;

int mazeSize = 10;
bool** mazeCell;
int neighbourRow, neighbourCol;
int unvisitedNeighboursCount;
int unvisitedNeighbours[4][2];

void buildMaze(int size) {
	mazeSize = size;
	mazeCell = new bool* [mazeSize];
	for (int i = 0; i < mazeSize; i++) {
		mazeCell[i] = new bool[mazeSize];
	}

	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			mazeCell[i][j] = false;
		}
	}

	generateMaze(0, 0);
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
		if (!mazeCell[row - 1][col]) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row - 1;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col;
			unvisitedNeighboursCount++;
		}
	}
	// checkBottom
	if (row < mazeSize - 1) {
		if (!mazeCell[row + 1][col]) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row + 1;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col;
			unvisitedNeighboursCount++;
		}
	}
	// checkLeft
	if (col > 0) {
		if (!mazeCell[row][col - 1]) {
			result = true;
			unvisitedNeighbours[unvisitedNeighboursCount][0] = row;
			unvisitedNeighbours[unvisitedNeighboursCount][1] = col - 1;
			unvisitedNeighboursCount++;
		}
	}
	// checkRight
	if (col < mazeSize - 1) {
		if (!mazeCell[row][col + 1]) {
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
	neighbourRow = unvisitedNeighbours[choosenUnvisitedNeighbour][0];
	neighbourCol = unvisitedNeighbours[choosenUnvisitedNeighbour][1];
}

void removeWallBetween(int currentRow, int currentCol, int neighbourRow, int neighbourCol) {
	// TODO
}

void generateMaze(int row, int col) {
	//1. Given a current cell as a parameter
	//2. Mark the current cell as visited
		mazeCell[row][col] = true;
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
	// TODO
}

void destroyMaze() {
	for (int i = 0; i < mazeSize; i++) {
		delete[] mazeCell[i];
	}
	delete[] mazeCell;
	mazeCell = NULL;
}