#include "sideGoal.h"
#include "Game.h"
#include <QImage>
#include <random>

extern Game * game;
SideGoal::SideGoal(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QImage images("resources/smallStar.png");
    setPixmap(QPixmap::fromImage(images.scaled(40,40)));
}

void SideGoal::changeY()
{
    int random = this->y();
    while(this->y() == random){
        random = getRandom();
    }
    setPos(x(), random);
}

int SideGoal::getRandom()
{
    int value = 4 + (rand() % 16);
    value = value * 50;
    return value;
}
