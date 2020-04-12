#include "SideBar.h"
#include "Game.h"
#include <QImage>

extern Game * game;
SideBar::SideBar(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
        QImage images("resources/squareObj.png");
        setPixmap(QPixmap::fromImage(images.scaled(50,50)));
}

void SideBar::moveUp()
{
    if(y() > 200)
        setPos(x(), y()  - 50);
}

void SideBar::moveDown()
{

    if(y() < 950)
        setPos(x(), y() + 50);
}
