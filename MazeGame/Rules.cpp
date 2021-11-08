#include <iostream>

#include "Rules.h"
#include "FrontEndHelpers.h"

using namespace std;

// draws the Rules menu of the game
void drawRules() {
    system("CLS");

    setColor(11); gotoxy(0, 0);
    cout << " _______           _        _______  _______ " << endl;
    cout << "(  ____ )|\\     /|( \\      (  ____ \\(  ____ \\" << endl;
    cout << "| (    )|| )   ( || (      | (    \\/| (    \\/" << endl;
    cout << "| (____)|| |   | || |      | (__    | (_____ " << endl;
    cout << "|     __)| |   | || |      |  __)   (_____  )" << endl;
    cout << "| (\\ (   | |   | || |      | (            ) |" << endl;
    cout << "| ) \\ \\__| (___) || (____/\\| (____/\\/\\____) |" << endl;
    cout << "|/   \\__/(_______)(_______/(_______/\\_______)" << endl << endl;

    cout << "The rules are simple. To navigate around the game, you can use" << endl;
    cout << "the arrow keys and the escape and enter buttons. When you start a" << endl;
    cout << "game, you will find your avatar in the upper left corner and your" << endl;
    cout << "mission is to guide it through the maze to the lower right corner." << endl;
    cout << "In the maze you will find keys 0==+ with which you will be able to" << endl;
    cout << "break and go through walls so that you may finish the maze with" << endl;
    cout << "fewer moves. However, you cannot break the outer walls of the maze." << endl;
    cout << "To check your best score for every level, go to the Leaderboard." << endl << endl;

    system("PAUSE");
    system("CLS");
}