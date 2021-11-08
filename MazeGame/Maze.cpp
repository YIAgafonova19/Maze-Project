#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Maze.h"
#include "FrontEndHelpers.h"

using namespace std;

int mazeSize;
MazeCell** mazeCell;
int neighbourRow, neighbourCol;
int unvisitedNeighboursCount;
int unvisitedNeighbours[4][2];

//This function takes the maze size
int getMazeSize() {
	return mazeSize;
}

//This function checks if a cell has a top wall
bool mazeCellHasTopWall(int row, int col) {
	return mazeCell[row][col].top;
}

//This function checks if a cell has a bottom wall
bool mazeCellHasBottomWall(int row, int col) {
	return mazeCell[row][col].bottom;
}

//This function checks if a cell has a left wall
bool mazeCellHasLeftWall(int row, int col) {
	return mazeCell[row][col].left;
}

//This function checks if a cell has a right wall
bool mazeCellHasRightWall(int row, int col) {
	return mazeCell[row][col].right;
}

//This function checks if a cell has 3 walls
bool isMazeCellTucked(int row, int col) {
	int wallCount = 0;

	if (mazeCellHasTopWall(row, col)) {
		wallCount++;
	}

	if (mazeCellHasBottomWall(row, col)) {
		wallCount++;
	}

	if (mazeCellHasLeftWall(row, col)) {
		wallCount++;
	}

	if (mazeCellHasRightWall(row, col)) {
		wallCount++;
	}

	return (wallCount == 3);
}

//This function builds a grid
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

//This function checks if a cell has unvisited neighbouring cells
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

//This function randomly chooses an unvisited neighbour of a cell
void chooseUnvisitedNeighbour() {
	int choosenUnvisitedNeighbour = rand() % unvisitedNeighboursCount + 1;
	neighbourRow = unvisitedNeighbours[choosenUnvisitedNeighbour - 1][0];
	neighbourCol = unvisitedNeighbours[choosenUnvisitedNeighbour - 1][1];
}

//This function removes the wall between the current cell and one of its neighbouring cells
void removeWallBetween(int currentRow, int currentCol, int neighbourRow, int neighbourCol) {
	// checkForTopNeighbour
	if (currentRow == neighbourRow + 1) {
		mazeCell[currentRow][currentCol].top = false;
		mazeCell[neighbourRow][neighbourCol].bottom = false;

		gotoxy(1 + currentCol * 5, 2 + currentRow * 2 - 1); cout << "    ";
	}
	// checkForBottomNeighbour
	if (currentRow == neighbourRow - 1) {
		mazeCell[currentRow][currentCol].bottom = false;
		mazeCell[neighbourRow][neighbourCol].top = false;

		gotoxy(1 + currentCol * 5, 2 + currentRow * 2 + 1); cout << "    ";
	}
	// checkForLeftNeighbour
	if (currentCol == neighbourCol + 1) {
		mazeCell[currentRow][currentCol].left = false;
		mazeCell[neighbourRow][neighbourCol].right = false;

		gotoxy(1 + currentCol * 5 - 1, 2 + currentRow * 2); cout << " ";
	}
	// checkForRightNeighbour
	if (currentCol == neighbourCol - 1) {
		mazeCell[currentRow][currentCol].right = false;
		mazeCell[neighbourRow][neighbourCol].left = false;

		gotoxy(1 + currentCol * 5 + 4, 2 + currentRow * 2); cout << " ";
	}
}

//This function generates a random maze
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

//This function draws the generated in the previous function maze in the console
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

//This function destroys the maze
void destroyMaze() {
	for (int i = 0; i < mazeSize; i++) {
		delete[] mazeCell[i];
	}
	delete[] mazeCell;
	mazeCell = NULL;
}