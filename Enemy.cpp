#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <typeinfo>
#include <QList>

extern Game * game;

Enemy::Enemy(int height, int width, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //values used to set height and width of image
    this->height = height;
    this->width = width;

}

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

void Enemy::move(){
    //18 //6
    setPos(x(),y()+3);

    if (pos().y() > 1000){
        //fix
        scene()->removeItem(this);

        delete this;
    //    game->health->decrease();

    }

    //delete later, no need
    //check if paused and pauses timer
//    if (game->paused == true){
//        pauseCheck= new QTimer(this);
//        connect(pauseCheck,SIGNAL(timeout()),this,SLOT(stopMove()));
//        pauseCheck->start(20);
//        //movement->stop();
//        int remaining = movement->remainingTime();
//       movement->stop();
//       movement->setInterval(remaining);
//    }

}

//delete later, no need
void Enemy::stopMove()
{
//    if(game->paused == false){
////        pauseCheck->stop();
////        //movement->
//        int remaining = pauseCheck->remainingTime();
//        pauseCheck->stop();
//        pauseCheck->setInterval(remaining);
//        movement->start(20);
//   }

}

void Enemy::setTimer(QTimer *timer){
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

}

