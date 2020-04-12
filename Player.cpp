#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "EnemyRow.h"
#include "Game.h"
#include <typeinfo>
#include "Enemy.h"
extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set graphic
    setPixmap(QPixmap("resources/starStrip.png"));
   // setPixmap(QPixmap::fromImage(image.scaled(400,100)));
   // firstRelease = true;
    for (int i =0; i < 4; i++){
        array[i] = 0;
    }
    firstRelease = false;

}


void Player::keyPressEvent(QKeyEvent *event){

   // if (event->key()  == Qt::Key_Space || event->key() == Qt::Key_T){
        if (event->key() == Qt::Key_Space){
                      game->pauseGame();


        }
        else if (event->key() == Qt::Key_T){
                      game->test->changeValue();

        }
   // }
    //else{

        //moving sidebars individually
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

        //main keys
    else if (event->key()  == Qt::Key_A || event->key() == Qt::Key_S ||  Qt::Key_D || event->key() == Qt::Key_F){
            firstRelease = true;
           // keysPressed+= event->key();
            keysPressed += ((QKeyEvent*)event)->key();
   }


}
void Player::keyReleaseEvent(QKeyEvent *event){
    if(firstRelease){
        processMultiKey();
        destroyEnemy2();
    }
    firstRelease = false;
   // keysPressed-= event->key();
    keysPressed -= ((QKeyEvent*)event)->key();
    //keysPressed.clear();
}

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

    //side
//    if(keysPressed.contains(Qt::Key_U)){
//        game->manageSideBar->moveUp2();
//    }
//    else if(keysPressed.contains(Qt::Key_J)){
//        game->manageSideBar->moveDown2();
//    }
//     if(keysPressed.contains(Qt::Key_I)){
//        game->manageSideBar->moveUp();
//    }
//    else if(keysPressed.contains(Qt::Key_K)){
//        game->manageSideBar->moveDown();
//    }

}

//void Player::keyPressEvent(QKeyEvent *event){
//    if (event->key() == Qt::Key_A){
//        destroyEnemy(0);

//    }
//    else if (event->key() == Qt::Key_S){
//        destroyEnemy(1);

//    }
//    else if (event->key() == Qt::Key_D){
//        destroyEnemy(2);

//    }
//    else if (event->key() == Qt::Key_F){
//        destroyEnemy(3);

//    }

    //moving sidebars individually
//    else if(event->key() == Qt::Key_U){
//        game->manageSideBar->moveUp2();
//    }
//    else if(event->key() == Qt::Key_J){
//        game->manageSideBar->moveDown2();
//    }
//    else if(event->key() == Qt::Key_I){
//        game->manageSideBar->moveUp();
//    }
//    else if(event->key() == Qt::Key_K){
//        game->manageSideBar->moveDown();
//    }

//    else if (event->key() == Qt::Key_Space){
//                  game->pauseGame();

//    }
//    else if (event->key() == Qt::Key_T){
//                  game->test->changeValue();

//    }
//}


//not needed
void Player::destroyEnemy(int button)
{
        QList<QGraphicsItem *> colliding_items = collidingItems();

        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)){

                //if(colliding_items[i]->x() < 300 && button == 0){
                if(colliding_items[i]->x() < 300 && button == 0){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    game->score->increase();
                    game->noteCount->increase();
                }
                else if(colliding_items[i]->x() >= 300 && colliding_items[i]->x() < 400 && button == 1){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    game->score->increase();
                    game->noteCount->increase();

                }
                else if(colliding_items[i]->x() >= 400 && colliding_items[i]->x() < 500 && button == 2){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    game->score->increase();
                    game->noteCount->increase();

                }
                else if(colliding_items[i]->x() >= 500 && colliding_items[i]->x() < 600 && button == 3){
                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];
                    game->score->increase();
                    game->noteCount->increase();

                }
//                else
//                    game->score->decrease();
                return;
            }
//            else
//                game->score->decrease();
        }
}

void Player::destroyEnemy2()
{
        QList<QGraphicsItem *> colliding_items = collidingItems();

        //set check array
        int checkArray[4];
        for (int i =0; i < 4; i++){
            checkArray[i] = 0;
        }

        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            //y limit to how closely it reads in the input
            if (typeid(*(colliding_items[i])) == typeid(Enemy) && colliding_items[i]->y() > 1025){
                 if(colliding_items[i]->x() < 300){
                     checkArray[0] = 1;
                    // game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >= 300 && colliding_items[i]->x() < 400){
                     checkArray[1] = 1;
                    // game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >= 400 && colliding_items[i]->x() < 500){
                     checkArray[2] = 1;
                     //game->noteCount->increase();
                 }
                 else if(colliding_items[i]->x() >= 500 && colliding_items[i]->x() < 600 ){
                     checkArray[3] = 1;
                     //game->noteCount->increase();
                 }

                 scene()->removeItem(colliding_items[i]);
                 delete colliding_items[i];

            }

        }

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

        for (int i =0; i < 4; i++){
            array[i] = 0;
        }
}
