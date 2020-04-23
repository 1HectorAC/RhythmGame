#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "EnemyRow.h"
#include "Player.h"
#include "Score.h"
//#include "Health.h"
#include "ListSetup.h"
#include "SongOptions.h"
#include "ManageSideBars.h"
#include <QTimer>
#include <QLineEdit>
#include <NoteCount.h>
#include "Test.h"
#include <Button.h>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    QGraphicsScene * scene;
    Player * player;
    QTimer * timer;
    Score * score;
    NoteCount * noteCount;
//    Health * health;
    ListSetup * listSetup;
    Test * test;

    void displayGameOverWindow();
    void pauseGame();
    QLineEdit * songChoice;
    SongOptions * songOptions;
    EnemyRow * enemys;
    QGraphicsTextItem* pauseText;
    int GLOBAL_WIDTH;
    int GLOBAL_HEIGHT;
    bool paused, paused2;
    ManageSideBars * manageSideBar;
    int globalSongNum;
    Button* plays;
    Button* menu;

public slots:
    void displayMainMenu();
    void start();
    void selectTransition();
    void selectOne();
    void selectTwo();
    void selectThree();
    void unPause();
};

#endif // GAME_H
