#include <iostream>
#include <Windows.h>

#include "FrontEndHelpers.h"

using namespace std;

void color(int color) {
    if (STD_OUTPUT_HANDLE) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}