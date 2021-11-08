#include <iostream>
#include <Windows.h>

#include "FrontEndHelpers.h"

using namespace std;

// sets the color of the console
void setColor(int color) {
    if (STD_OUTPUT_HANDLE) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}

// sets the coordinates of an object in the console
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// sets the position of the cursor in the console
void setCursor(bool visible) {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// sets the console to full screen
void setFullScreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}