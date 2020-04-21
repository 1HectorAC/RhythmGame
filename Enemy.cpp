#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <typeinfo>
#include <QList>
#include "Game.h"
#include "Enemy.h"

extern Game * game;

Enemy::Enemy(int height, int width, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Values used to set height and width of the image it will have image.
    this->height = height;
    this->width = width;

}

//Enter a value to set the image of the object.
void Enemy::setImage(int value)
{
    if(value == 1){
        QImage images("resources/yellowStar.png");
        setPixmap(QPixmap::fromImage(images.scaled(width,height)));
    }
    else if(value == 2){
        QImage images("resources/blueStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(width,height)));
    }
    else if(value == 3){
        QImage images("resources/purpleStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(width,height)));
    }
    else{
        QImage images("resources/darkBlueStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(width,height)));
    }
}

//Shift the object downwards in the y direction.
void Enemy::move(){
    //Adjust position of object by +3
    setPos(x(),y()+3);

    //Delete enemy object  if hit lower bond limit.
    if (pos().y() > 1000){
        //fix
        scene()->removeItem(this);
        delete this;
    //    game->health->decrease();
    }
}

//Set a timer for this object that will make it move.
void Enemy::setTimer(QTimer *timer){
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

}

