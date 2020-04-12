#include <QApplication>
#include "Game.h"
#include <QtGui>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Game * game;

int main(int argc, char *argv[])
{
    srand(time(0));

    QApplication a(argc, argv);
    game = new Game();
    game->show();
    //game->start();

    game->displayMainMenu();
    return a.exec();
}
