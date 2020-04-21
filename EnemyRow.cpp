#include <QGraphicsScene>
#include <QList>
#include "EnemyRow.h"
#include "Game.h"
#include "Enemy.h"

extern Game * game;
EnemyRow::EnemyRow(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //Position used in keeping track of value in row currently on when droping enemy.
    position = 0;

    //Setup timer to drop enemies at constant interval.
    timer = new QTimer(this);
    timer->start(5);
}

//Spawn an Enemy object.
void EnemyRow::spawn(int position){
    Enemy * enemy = new Enemy(game->GLOBAL_WIDTH / 4 / 4,game->GLOBAL_WIDTH / 4 / 4);
    enemy->setPos(round(game->GLOBAL_WIDTH * (.3)) + position * 130, game->GLOBAL_WIDTH / 25);
    enemy->setImage(position);
    scene()->addItem(enemy);
    enemy->setTimer(timer);

}

//Drop a row of enemies.
void EnemyRow::dropEnemys(){

    //Part of test class to create a new track. May need to delete later.
    game->test->raiseTrack();

    //Add delay to song before playing.
    game->songOptions->startCount++;
    if(game->songOptions->startCount == 5)
        game->songOptions->play();

    //Prevent enemys from  spawning if paused.
    if(game->paused == false){

        //Check if there is an end of track by having a 2 in the track values.
        if (game->listSetup->list[game->listSetup->rows][0] == 2){
              game->displayGameOverWindow();

        }

        //Start with far left enemy position value.
        int position = 1;

        //spawn enemy in row based on track.
        for (int i = 0; i < 4; i++){
            //Spawn if track value is a 1.
            if (game->listSetup->list[game->listSetup->rows][i] == 1){
                spawn(position );

            }

            //Adjust position to spawn next rown of enemies.
            position+=1;
        }

        //Adjust rown in listSetup to make sure current row is updated.
        game->listSetup->rows++;
    }

}


