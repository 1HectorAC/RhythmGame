#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

#include <typeinfo>
#include <QList>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


//    QImage images("resources/blueBox.png");
//    setPixmap(QPixmap::fromImage(images.scaled(90,90)));

    // make/connect a timer to move() the enemy every so often
   //movement = new QTimer(this);
   // connect(movement,SIGNAL(timeout()),this,SLOT(move()));
    //movement->start(20);
}



void Enemy::setImage(int value)
{
    if(value == 200){
        QImage images("resources/yellowStar.png");
        setPixmap(QPixmap::fromImage(images.scaled(90,90)));
    }
    else if(value == 300){
        QImage images("resources/blueStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(90,90)));
    }
    else if(value == 400){
        QImage images("resources/purpleStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(90,90)));
    }
    else if(value == 500){
        QImage images("resources/darkBlueStar.png");
       setPixmap(QPixmap::fromImage(images.scaled(90,90)));
    }
}

void Enemy::move(){
    //18 //6
    setPos(x(),y()+3);

    if (pos().y() > 1100){
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

