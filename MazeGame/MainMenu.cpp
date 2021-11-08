#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "MainMenu.h"
#include "LevelMenu.h"
#include "Score.h"
#include "Rules.h"
#include "FrontEndHelpers.h"

using namespace std;

int activeItem = 0;
int mainMenuItemColor[] = { 11, 11, 11, 11 };
char keyPressed;
bool inMainMenu = true;

// draws the Main Menu layout
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

// draws the options of the Main Menu
void drawMainMenu() {
    drawMainMenuLayout();

    mainMenuItemColor[0] = 11;
    mainMenuItemColor[1] = 11;
    mainMenuItemColor[2] = 11;
    mainMenuItemColor[3] = 11;

    mainMenuItemColor[activeItem] = 14;

    gotoxy(30, 12); setColor(mainMenuItemColor[0]); cout << " Start ";
    gotoxy(30, 13); setColor(mainMenuItemColor[1]); cout << " Leaderboard ";
    gotoxy(30, 14); setColor(mainMenuItemColor[2]); cout << " Rules ";
    gotoxy(30, 15); setColor(mainMenuItemColor[3]); cout << " Quit ";
}

// draws the greeting that is displayed at the end of the program
void drawTheEnd() {
    system("CLS");
    setColor(11);
    cout << " _______  _______  _______             _______             _______  _______  _______  _       \n";
    cout << "(  ____ \\(  ____ \\(  ____ \\  |\\     /|(  ___  )|\\     /|  (  ____ \\(  ___  )(  ___  )( (    /|\n";
    cout << "| (    \\/| (    \\/| (    \\/  ( \\   / )| (   ) || )   ( |  | (    \\/| (   ) || (   ) ||  \\  ( |\n";
    cout << "| (_____ | (__    | (__       \\ (_) / | |   | || |   | |  | (_____ | |   | || |   | ||   \\ | |\n";
    cout << "(_____  )|  __)   |  __)       \\   /  | |   | || |   | |  (_____  )| |   | || |   | || (\\ \\) |\n";
    cout << "      ) || (      | (           ) (   | |   | || |   | |        ) || |   | || |   | || | \\   |\n";
    cout << "/\\____) || (____/\\| (____/\\     | |   | (___) || (___) |  /\\____) || (___) || (___) || )  \\  |\n";
    cout << "\\_______)(_______/(_______/     \\_/   (_______)(_______)  \\_______)(_______)(_______)|/    )_)\n";
    cout << "\n\n\n";
    setColor(11);

    system("PAUSE");
}

// proccesses the input from the Main Menu
void processMainMenuInput(char keyPressed) {
    switch (keyPressed) {
        case(KEY_UP):
            activeItem = (activeItem + 3) % 4;
            break;
        case(KEY_DOWN):
            activeItem = (activeItem + 1) % 4;
            break;
        case(KEY_ESC):
            inMainMenu = false;
            break;
        case(KEY_ENTER):
            switch (activeItem) {
                case(0):
                    levelMenu();
                    break;
                case(1):
                    drawLeaderboard();
                    break;
                case(2):
                    drawRules();
                    break;
                case(3):
                    inMainMenu = false;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

//This function is the main Main menu function
void mainMenu() {
    setCursor(false);
    inMainMenu = true;

    while (inMainMenu) {
        drawMainMenu();

        keyPressed = _getch();

        processMainMenuInput(keyPressed);
    }

    drawTheEnd();
    setCursor(true);
    setColor(15);
}