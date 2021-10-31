#include <iostream>

#include "Help.h"
#include "FrontEndHelpers.h"

using namespace std;

void drawHelp() {
    system("CLS");

    setColor(11); gotoxy(0, 0);
    cout << "          _______  _        _______    _______  _______  _                " << endl;
    cout << "|\\     /|(  ____ \\( \\      (  ____ )  (       )(  ____ \\( (    /||\\     /|" << endl;
    cout << "| )   ( || (    \\/| (      | (    )|  | () () || (    \\/|  \\  ( || )   ( |" << endl;
    cout << "| (___) || (__    | |      | (____)|  | || || || (__    |   \\ | || |   | |" << endl;
    cout << "|  ___  ||  __)   | |      |  _____)  | |(_)| ||  __)   | (\\ \\) || |   | |" << endl;
    cout << "| (   ) || (      | |      | (        | |   | || (      | | \\   || |   | |" << endl;
    cout << "| )   ( || (____/\\| (____/\\| )        | )   ( || (____/\\| )  \\  || (___) |" << endl;
    cout << "|/     \\|(_______/(_______/|/         |/     \\|(_______/|/    )_)(_______)" << endl << endl;

    system("PAUSE");
}