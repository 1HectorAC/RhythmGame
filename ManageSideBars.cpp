#include "ManageSideBars.h"
#include "SideBar.h"
#include <QGraphicsScene>
#include "Game.h"
#include <QLabel>
#include <sideGoal.h>
extern Game * game;
ManageSideBars::ManageSideBars()
{
    rightBar = new SideBar();
    rightBar->setPos(game->GLOBAL_WIDTH *  .69, game->GLOBAL_HEIGHT / 2 + rightBar->objHeight / 2);
    leftBar = new SideBar();
    leftBar->setPos(game->GLOBAL_WIDTH * .272, game->GLOBAL_HEIGHT / 2 + rightBar->objHeight / 2);

    rightGoal = new SideGoal();
    rightGoal->setPos(game->GLOBAL_WIDTH * .69, 600);
    rightGoal->changeY();
    leftGoal = new SideGoal();
    leftGoal->setPos(game->GLOBAL_WIDTH * .272, 600);
    leftGoal->changeY();


    //change later
  //  QImage images("resources/redBox.png");
   // QImage images("resources/squareObj.png");

  //  rightBar->setPixmap(QPixmap::fromImage(images.scaled(50,50)));
    game->scene->addItem(rightGoal);
    game->scene->addItem(leftGoal);

    game->scene->addItem(rightBar);
    game->scene->addItem(leftBar);
//    game->scene->addItem(rightGoal);
//    game->scene->addItem(leftGoal);

    goalHit1 = false;
    goalHit2 = false;

}

void ManageSideBars::moveUp()
{
    rightBar->moveUp();
    if(rightBar->y() == rightGoal->y())
        goalHit1 = true;
    else
        goalHit1 = false;
    WinCheck();

}

void ManageSideBars::moveUp2()
{
    leftBar->moveUp();
    if(leftBar->y() == leftGoal->y())
        goalHit2 = true;
    else
        goalHit2 = false;
    WinCheck();
}

void ManageSideBars::moveDown()
{
    rightBar->moveDown();
    if(rightBar->y() == rightGoal->y())
        goalHit1 = true;
    else
        goalHit1 = false;
    WinCheck();

}

void ManageSideBars::moveDown2()
{
    leftBar->moveDown();
    if(leftBar->y() == leftGoal->y())
        goalHit2 = true;
    else
        goalHit2 = false;
    WinCheck();
}


void ManageSideBars::WinCheck()
{
    if(goalHit1 == true && goalHit2 == true){
        game->score->increase2();
        rightGoal->changeY();
        leftGoal->changeY();
        goalHit1 = false;
        goalHit2 = false;

    }

}
