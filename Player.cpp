#include <QGraphicsScene>
#include <QKeyEvent>
#include <typeinfo>
#include "Player.h"
#include "Enemy.h"
#include "EnemyRow.h"
#include "Game.h"

extern Game * game;

Player::Player(int x, int y, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //Set width and height of player.
    width = game->GLOBAL_WIDTH / 3.763;
    height = game->GLOBAL_HEIGHT / 11.35;

    //Set position of object.
    setPos(x,y);

    //Set x_Position and y_Position. This will be used in colition detection.
    x_Position = x;
    y_Position = y;

    // set graphic image of player and size based on width and height.
    QImage images("resources/starStrip.png");
    setPixmap(QPixmap::fromImage(images.scaled(width,height)));


   // Setup up variables involved with how keys are pressed.
    for (int i =0; i < 4; i++){
        array[i] = 0;
    }
    firstRelease = false;
}

//Action taken when a key is pressed.
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
                  game->pauseGame();

    //Key pressed inolved in making test track.
    }
    else if (event->key() == Qt::Key_T){
                  game->test->changeValue();
    }

    //Moving sidebars individually.
    else if(event->key() == Qt::Key_U){
        game->manageSideBar->moveUp2();
    }
    else if(event->key() == Qt::Key_J){
        game->manageSideBar->moveDown2();
    }
    else if(event->key() == Qt::Key_I){
        game->manageSideBar->moveUp();
    }
    else if(event->key() == Qt::Key_K){
        game->manageSideBar->moveDown();
    }

    //Main keys presses to hit notes.
else if (event->key()  == Qt::Key_A || event->key() == Qt::Key_S ||  Qt::Key_D || event->key() == Qt::Key_F){
        firstRelease = true;
        keysPressed += ((QKeyEvent*)event)->key();
   }
}

//Action taken when key is released.
void Player::keyReleaseEvent(QKeyEvent *event){
    //When keys are released then process currently pressed keys.
    if(firstRelease){
        processMultiKey();
        destroyEnemy();
    }
    firstRelease = false;
    keysPressed -= ((QKeyEvent*)event)->key();
}

//Setup array values based on what keys are pressed.
void Player::processMultiKey()
{
    if (keysPressed.contains(Qt::Key_A)){
         array[0] = 1;
    }
    if (keysPressed.contains(Qt::Key_S)){
           array[1] = 1;
    }
    if (keysPressed.contains(Qt::Key_D)){
        array[2] = 1;

    }
    if (keysPressed.contains(Qt::Key_F)){
        array[3] = 1;

    }
}

//Destroy enemies hit and change score depending on result.
void Player::destroyEnemy()
{
        QList<QGraphicsItem *> colliding_items = collidingItems();

        //Setup checkarray to keep track of which notes where a hit and which weren't.
        int checkArray[4];
        for (int i =0; i < 4; i++){
            checkArray[i] = 0;
        }

        //Note lengths need for calculating collision.
        int NoteLength = int(width / 4);
        int halfNote = int(NoteLength / 2);

        //Check collided items.
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            //Maybe limit y to how closely it reads in the input later, add "&& colliding_items[i]->y() > value here"
            if (typeid(*(colliding_items[i])) == typeid(Enemy) && colliding_items[i]->y() > y_Position + 4 ){
                //Determine which items collided based on x position.
                 if(colliding_items[i]->x() < x_Position + halfNote){
                     checkArray[0] = 1;
                    // game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >=  x_Position + halfNote && colliding_items[i]->x() <  x_Position + NoteLength + halfNote){
                     checkArray[1] = 1;
                    // game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >=  x_Position + NoteLength + halfNote && colliding_items[i]->x() <  x_Position + NoteLength * 2 + halfNote){
                     checkArray[2] = 1;
                     //game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >=  x_Position + NoteLength * 2 + halfNote ){
                     checkArray[3] = 1;
                     //game->noteCount->increase();
                 }

                 scene()->removeItem(colliding_items[i]);
                 delete colliding_items[i];

            }

        }

        //Change score based on hits or misses of notes.
        bool fail = false;
        for (int i =0; i < 4; i++){
            if(array[i] == checkArray[i] && array[i] == 1){
                game->score->increase();
            }
            else if(array[i] != checkArray[i] )
                fail = true;
              //  game->score->decrease();

        }
        if(fail == true){
            game->score->decrease();
        }

        //Reset array values for next check.
        for (int i =0; i < 4; i++){
            array[i] = 0;
        }
}
