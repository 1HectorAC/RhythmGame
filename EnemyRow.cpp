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
    //maybe set color or enemy buttons here
    Enemy * enemy = new Enemy();
    enemy->setPos(position, 200);
    enemy->setImage(position);

    scene()->addItem(enemy);
    enemy->setTimer(timer);

}

void EnemyRow::dropEnemys()
{

    game->test->raiseTrack();

    //delay to song
    game->songOptions->startCount++;
    if(game->songOptions->startCount == 6)
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
        int position = 200;
        //end game

        //spawn fret buttons
        for (int i = 0; i < 4; i++){
            //change
            if (game->listSetup->list[game->listSetup->rows][i] == 1){
                spawn(position);

            }

            position+=100;
        }
        //position = 200;
        game->listSetup->rows++;
    }

}


