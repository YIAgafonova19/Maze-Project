#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "MainMenu.h"
#include "FrontEndHelpers.h"

using namespace std;

int activeItem = 0;
const int ITEMSCOUNT = 4;
int mainMenuItemColor[] = { 11, 11, 11, 11 };
char keyPressed;
bool inMainMenu = true;

void drawMainMenuLayout() {
    setColor(11); gotoxy(0, 0);
    cout << " _______  _______ _________ _          _______  _______  _" << endl;
    cout << "(       )(  ___  )\\__   __/( (    /|  (       )(  ____ \\( (    /||\\     /|" << endl;
    cout << "| () () || (   ) |   ) (   |  \\  ( |  | () () || (    \\/|  \\  ( || )   ( |" << endl;
    cout << "| || || || (___) |   | |   |   \\ | |  | || || || (__    |   \\ | || |   | |" << endl;
    cout << "| |(_)| ||  ___  |   | |   | (\\ \\) |  | |(_)| ||  __)   | (\\ \\) || |   | |" << endl;
    cout << "| |   | || (   ) |   | |   | | \\   |  | |   | || (      | | \\   || |   | |" << endl;
    cout << "| )   ( || )   ( |___) (___| )  \\  |  | )   ( || (____/\\| )  \\  || (___) |" << endl;
    cout << "|/     \\||/     \\|\\_______/|/    )_)  |/     \\|(_______/|/    )_)(_______)" << endl;
}

void drawMainMenu() {
    drawMainMenuLayout();

    mainMenuItemColor[0] = 11;
    mainMenuItemColor[1] = 11;
    mainMenuItemColor[2] = 11;
    mainMenuItemColor[3] = 11;

    mainMenuItemColor[activeItem] = 14;

    gotoxy(30, 12); setColor(mainMenuItemColor[0]); cout << " Start ";
    gotoxy(30, 13); setColor(mainMenuItemColor[1]); cout << " Leaderboard ";
    gotoxy(30, 14); setColor(mainMenuItemColor[2]); cout << " Help ";
    gotoxy(30, 15); setColor(mainMenuItemColor[3]); cout << " Quit ";
}


void processMainMenuInput(char keyPressed) {
    switch (keyPressed) {
        case(72):
            activeItem = (activeItem + 3) % 4;
            break;
        case(80):
            activeItem = (activeItem + 1) % 4;
            break;
        case(27):
            inMainMenu = false;
            break;
        default:
            break;
    }
}

void mainMenu() {
    setCursor(false);
    inMainMenu = true;

    while (inMainMenu) {
        drawMainMenu();

        keyPressed = _getch();

        processMainMenuInput(keyPressed);
    }

    setCursor(true);
}