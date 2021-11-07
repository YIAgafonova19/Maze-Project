#include <iostream>
#include <Windows.h>

#include "FrontEndHelpers.h"

using namespace std;
// This function is for Console Color
void setColor(int color) {
    if (STD_OUTPUT_HANDLE) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}

// This function is for Console Position
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// This function is for Console Cursor
void setCursor(bool visible) {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// This function is for Full Screen
void setFullScreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}