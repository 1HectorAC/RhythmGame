#include "EnemyRow.h"
#include "Game.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QList>
extern Game * game;
EnemyRow::EnemyRow(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    position = 0;
    timer = new QTimer(this);
    //20 //10
    timer->start(5);

}
void EnemyRow::spawn(int position){
    //size based on 1/4 of the the player part is
    Enemy * enemy = new Enemy(game->GLOBAL_WIDTH / 4 / 4,game->GLOBAL_WIDTH / 4 / 4);
    enemy->setPos(round(game->GLOBAL_WIDTH * (.3)) + position * 130, game->GLOBAL_WIDTH / 25);
    enemy->setImage(position);

    scene()->addItem(enemy);
    enemy->setTimer(timer);

}

void EnemyRow::dropEnemys()
{

    game->test->raiseTrack();

    //delay to song
    game->songOptions->startCount++;
    if(game->songOptions->startCount == 5)
        game->songOptions->play();

    //Prevent enemy spawn if paused
    if(game->paused == false){

        //game over check
        if (game->listSetup->list[game->listSetup->rows][0] == 2){
//            game->scene->clear();
//            game->songOptions->currentSong->stop();
//            game->songOptions->startCount = 0;
         //   game->displayMainMenu();
              game->displayGameOverWindow();

        }

        //pos of far left fret button
        int position = 1;
        //end game

        //spawn fret buttons
        for (int i = 0; i < 4; i++){
            //change
            if (game->listSetup->list[game->listSetup->rows][i] == 1){
                spawn(position );

            }

            position+=1;
        }
        game->listSetup->rows++;
    }

}


