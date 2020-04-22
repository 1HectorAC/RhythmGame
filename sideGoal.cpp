#include <QImage>
#include <random>
#include "sideGoal.h"
#include "Game.h"

extern Game * game;

SideGoal::SideGoal(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Setup image of object.
    QImage images("resources/smallStar.png");
    objHeight = round(game->height() / 16);
    setPixmap(QPixmap::fromImage(images.scaled(objHeight,objHeight)));

    //Set postitionPoint to 0. This signifies its position over a limiited y-axis values.
    positionPoint = 0;
}

//Change the y-position of the object to a random value.
void SideGoal::changeY()
{
    //Need random variable to make sure that the resulting change in position isn't the same as before.
    int random = positionPoint;
    while(random == positionPoint){
        random = getRandom();

    }
    positionPoint = random;
    setPos(x(), (game->GLOBAL_HEIGHT / 2 + objHeight / 2) + positionPoint * objHeight);

}

//Get a random number between -6 and 4. These values relate to what the y-position can be.
int SideGoal::getRandom()
{
    //random position in side bar relative to sideBar objects max and min of -6 to 4
    int value = (rand() % 11) - 6;
    return value;
}
