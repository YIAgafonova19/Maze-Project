#include <iostream>

#include "Help.h"
#include "FrontEndHelpers.h"

using namespace std;

void drawHelp() {
    system("CLS");

    setColor(11); gotoxy(0, 0);
    cout << "Help menu" << endl;

    system("PAUSE");
}