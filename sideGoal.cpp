#include "sideGoal.h"
#include "Game.h"
#include <QImage>
#include <random>
#include "math.h"

extern Game * game;
SideGoal::SideGoal(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QImage images("resources/smallStar.png");

    objHeight = round(game->height() / 16);
    setPixmap(QPixmap::fromImage(images.scaled(objHeight,objHeight)));

    //set the point in the y-axis the object is in
    positionPoint = 0;
}

void SideGoal::changeY()
{
    /*
    int random = this->y();
    while(this->y() == random){
        random = getRandom();
    }
    setPos(x(), random);
    */

    int random = positionPoint;
    while(random == positionPoint){
        random = getRandom();

    }
    positionPoint = random;
    setPos(x(), (game->GLOBAL_HEIGHT / 2 + objHeight / 2) + positionPoint * objHeight);

}

int SideGoal::getRandom()
{
    //random position in side bar relative to sideBar objects max and min of -6 to 4
    int value = (rand() % 11) - 6;
    return value;
}
