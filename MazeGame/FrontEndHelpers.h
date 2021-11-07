#pragma once

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 0x0d

void setColor(int color);

void gotoxy(int x, int y);

void setCursor(bool visible);

void setFullScreen();