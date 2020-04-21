#include "SideBar.h"
#include "Game.h"
#include <QImage>
#include "math.h"

extern Game * game;
SideBar::SideBar(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
        QImage images("resources/squareObj.png");
        objHeight = round(game->GLOBAL_HEIGHT / 16);
        setPixmap(QPixmap::fromImage(images.scaled(objHeight,objHeight)));

        //set the point in the y-axis the object is in
        positionPoint = 0;
}

void SideBar::moveUp()
{
    if(positionPoint < 6){
        setPos(x(), y() - objHeight);
        positionPoint++;
    }


}

void SideBar::moveDown()
{

    if(positionPoint > -4){
        setPos(x(), y() + objHeight);
        positionPoint--;
    }
}
