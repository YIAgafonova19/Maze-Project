#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "LevelMenu.h"
#include "Maze.h"
#include "Player.h"
#include "Game.h"
#include "FrontEndHelpers.h"

using namespace std;

int activeLevelItem = 0;
int levelMenuItemColor[] = { 11, 11, 11, 11, 11 };
char levelKeyPressed;
bool inLevelMenu = true;

void drawLevelMenuLayout() {
    setColor(11); gotoxy(0, 0);
    cout << " _______  _______  _        _______  _______ _________   _        _______           _______  _       " << endl;
    cout << "(  ____ \\(  ____ \\( \\      (  ____ \\(  ____ \\\\__   __/  ( \\      (  ____ \\|\\     /|(  ____ \\( \\      " << endl;
    cout << "| (    \\/| (    \\/| (      | (    \\/| (    \\/   ) (     | (      | (    \\/| )   ( || (    \\/| (      " << endl;
    cout << "| (_____ | (__    | |      | (__    | |         | |     | |      | (__    | |   | || (__    | |      " << endl;
    cout << "(_____  )|  __)   | |      |  __)   | |         | |     | |      |  __)   ( (   ) )|  __)   | |      " << endl;
    cout << "      ) || (      | |      | (      | |         | |     | |      | (       \\ \\_/ / | (      | |      " << endl;
    cout << "/\\____) || (____/\\| (____/\\| (____/\\| (____/\\   | |     | (____/\\| (____/\\  \\   /  | (____/\\| (____/\\" << endl;
    cout << "\\_______)(_______/(_______/(_______/(_______/   )_(     (_______/(_______/   \\_/   (_______/(_______/" << endl;
}

void drawLevelMenu() {
    drawLevelMenuLayout();

    levelMenuItemColor[0] = 11;
    levelMenuItemColor[1] = 11;
    levelMenuItemColor[2] = 11;
    levelMenuItemColor[3] = 11;
    levelMenuItemColor[4] = 11;

    levelMenuItemColor[activeLevelItem] = 14;

    gotoxy(30, 12); setColor(levelMenuItemColor[0]); cout << " Easy ";
    gotoxy(30, 13); setColor(levelMenuItemColor[1]); cout << " Medium ";
    gotoxy(30, 14); setColor(levelMenuItemColor[2]); cout << " Hard ";
    gotoxy(30, 15); setColor(levelMenuItemColor[3]); cout << " Impossible ";
    gotoxy(30, 16); setColor(levelMenuItemColor[4]); cout << " Custom ";
}

void processLevelMenuInput(char levelKeyPressed) {
    switch (levelKeyPressed) {
    case(KEY_UP):
        activeLevelItem = (activeLevelItem + 4) % 5;
        break;
    case(KEY_DOWN):
        activeLevelItem = (activeLevelItem + 1) % 5;
        break;
    case(KEY_ESC):
        system("CLS");
        inLevelMenu = false;
        break;
    case(KEY_ENTER):
        switch (activeLevelItem) {
            case(0):
                playGame(10);
                break;
            case(1):
                playGame(15);
                break;
            case(2):
                playGame(20);
                break;
            case(3):
                playGame(20);
                break;
            case(4):
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }
}

void levelMenu() {
    system("CLS");
    setCursor(false);
    inLevelMenu = true;

    while (inLevelMenu) {
        drawLevelMenu();

        levelKeyPressed = _getch();

        processLevelMenuInput(levelKeyPressed);
    }

    inLevelMenu = false;
}