#include <QGraphicsScene>
#include <QLabel>
#include "ManageSideBars.h"
#include "SideBar.h"
#include "Game.h"
#include "sideGoal.h"

extern Game * game;

ManageSideBars::ManageSideBars()
{
    //Make right side bar and set position.
    rightBar = new SideBar();
    rightBar->setPos(game->GLOBAL_WIDTH *  .69, game->GLOBAL_HEIGHT / 2 + rightBar->objHeight / 2);

    //Make left side bar and set position.
    leftBar = new SideBar();
    leftBar->setPos(game->GLOBAL_WIDTH * .272, game->GLOBAL_HEIGHT / 2 + rightBar->objHeight / 2);

    //Make right goal and set position.
    rightGoal = new SideGoal();
    rightGoal->setPos(game->GLOBAL_WIDTH * .69, 600);
    rightGoal->changeY();

    //Make leftt goal and set position.
    leftGoal = new SideGoal();
    leftGoal->setPos(game->GLOBAL_WIDTH * .272, 600);
    leftGoal->changeY();


    //Add side bars and goals to scene.
    game->scene->addItem(rightGoal);
    game->scene->addItem(leftGoal);
    game->scene->addItem(rightBar);
    game->scene->addItem(leftBar);

    //Set goals check to see if side bars are hitting goals.
    goalHit1 = false;
    goalHit2 = false;

}

//Move rightBar object up and check for win.
void ManageSideBars::moveUp()
{
    rightBar->moveUp();
    if(rightBar->y() == rightGoal->y())
        goalHit1 = true;
    else
        goalHit1 = false;
    WinCheck();

}

//Move leftBar object up and check for win.
void ManageSideBars::moveUp2()
{
    leftBar->moveUp();
    if(leftBar->y() == leftGoal->y())
        goalHit2 = true;
    else
        goalHit2 = false;
    WinCheck();
}

//Move rightBar object down and check for win.
void ManageSideBars::moveDown()
{
    rightBar->moveDown();
    if(rightBar->y() == rightGoal->y())
        goalHit1 = true;
    else
        goalHit1 = false;
    WinCheck();

}

//Move leftBar object down and check for win.
void ManageSideBars::moveDown2()
{
    leftBar->moveDown();
    if(leftBar->y() == leftGoal->y())
        goalHit2 = true;
    else
        goalHit2 = false;
    WinCheck();
}

//Check for win or alignment of bar and goal.
void ManageSideBars::WinCheck()
{
    if(goalHit1 == true && goalHit2 == true){
        game->score->increase2();

        //Change y position of goals.
        rightGoal->changeY();
        leftGoal->changeY();

        //Reset goal hit checks.
        goalHit1 = false;
        goalHit2 = false;

    }

}
