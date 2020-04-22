#include <QImage>
#include "SideBar.h"
#include "Game.h"
#include "math.h"

extern Game * game;

SideBar::SideBar(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Setup image object.
    QImage images("resources/squareObj.png");
    objHeight = round(game->GLOBAL_HEIGHT / 16);
    setPixmap(QPixmap::fromImage(images.scaled(objHeight,objHeight)));

    //Set postitionPoint to 0. This signifies its position over a limiited y-axis values
    positionPoint = 0;
}

//Move the object up by adjusting its y position value.
void SideBar::moveUp(){
    //Moves up only if its position doesn't hit limit.
    if(positionPoint < 6){
        setPos(x(), y() - objHeight);
        positionPoint++;
    }
}

//Move the object down by adjusting its y position value.
void SideBar::moveDown()
{
    //Moves down only if its position doesn't hit limiit.
    if(positionPoint > -4){
        setPos(x(), y() + objHeight);
        positionPoint--;
    }
}
