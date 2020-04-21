#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <fstream>
#include "EnemyRow.h"
#include "Enemy.h"
#include "Player.h"
#include "score.h"
#include "ListSetup.h"
#include "ManageSideBars.h"
#include "Button.h"
#include <QLineEdit>
#include <QPoint>
#include <sstream>
#include <QHBoxLayout>
#include <QString>
#include <QGraphicsTextItem>
#include "Test.h"
#include <iostream>
#include "math.h"

using namespace std;
Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    // 800 x 1200 now, maybe change later.
    GLOBAL_WIDTH = 1920;
    GLOBAL_HEIGHT = 1080;

    scene->setSceneRect(0,0, GLOBAL_WIDTH, GLOBAL_HEIGHT);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   setFixedSize(GLOBAL_WIDTH,GLOBAL_HEIGHT);
    songOptions = new SongOptions;
    paused = false;
    paused2 = false;

}

void Game::start(){

    scene->clear();
    listSetup = new ListSetup;
    test = new Test();

    //set up song option from string to int
//    string song = songChoice->text().toLocal8Bit().constData();
//    int number;
//    if ( ! (istringstream(song) >> number) ) number = 0;


    QImage stuff("resources/gameScreen4.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));


    //score
    score = new Score();
    score->setPos(score->x(), score->y() + GLOBAL_HEIGHT / 55);
    scene->addItem(score);

    //health
//    health = new Health();
//    health->setPos(health->x() + globalWidth / 3, health->y() + globalHeight / 55);
//    scene->addItem(health);

    //title of song
    string test = listSetup->title(globalSongNum);
    QString test2 = QString::fromStdString(test);
    QGraphicsTextItem * titleSong = new QGraphicsTextItem(QString(test2));
    QFont titleFont("times",16);
    titleSong->setFont(titleFont);
    titleSong->setDefaultTextColor(Qt::white);
    titleSong->setPos(titleSong->x() + GLOBAL_WIDTH / 3, titleSong->y() + GLOBAL_HEIGHT / 55);
    scene->addItem(titleSong);

    //player
    player = new Player();
    //200, 1000
    player->setPos(round(GLOBAL_WIDTH * (.365)), GLOBAL_WIDTH * 0.467);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    enemys = new EnemyRow();
    scene->addItem(enemys);

    //side bar
    manageSideBar = new ManageSideBars();
    //scene->addItem(manageSideBar);

    //////////////////////////////////////////edit here was number
    //setup list
    listSetup->makeList(globalSongNum);

    //note count
    noteCount = new NoteCount();
    noteCount->setPos(GLOBAL_WIDTH -  155, noteCount->y() + GLOBAL_HEIGHT / 55);
    scene->addItem(noteCount);

    //spawn enemy and select song
    //next to each other to prevent delay of track from spawns
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),enemys,SLOT(dropEnemys()));
    songOptions->selectSong(globalSongNum);
    timer->start(180);
    ////////////////////////////////////////////////////edit here was number

    show();

}

void Game::selectTransition()
{
    globalSongNum = 1;
    start();
}

void Game::selectOne()
{
    globalSongNum = 1;
    start();
}

void Game::selectTwo()
{
    globalSongNum = 2;
    start();
}

void Game::selectThree()
{
    globalSongNum = 3;
    start();
}


void Game::displayMainMenu(){
    //high score return here with highScore var

    scene->clear();

    //set intro music
    songOptions->selectSong(10);
    songOptions->play();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Rhythm Game"));
    QFont titleFont("comic sans",28, QFont::Bold);
    titleFont.setUnderline(true);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 300;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the author
    QGraphicsTextItem* titleTexts = new QGraphicsTextItem(QString("By H&A inc."));
    QFont titleFonts("comic sans",15);
    titleTexts->setFont(titleFonts);
    titleTexts->setDefaultTextColor(Qt::white);
    int txPoss = this->width()/2 - titleTexts->boundingRect().width()/2;
    int tyPoss = 390;
    titleTexts->setPos(txPoss,tyPoss);
    scene->addItem(titleTexts);

//////////////////////////////////////////////////////////////////////////////////////////////
    // text box info
//    QGraphicsTextItem* songselect = new QGraphicsTextItem(QString("please enter song(0-3)"));
//    //QFont titleFon("comic sans",20);
//    songselect->setFont(titleFonts);
//    songselect->setDefaultTextColor(Qt::white);
//    int bxPos = this->width()/2 - songselect->boundingRect().width()/2;
//    int byPos = 600;
//    songselect->setPos(bxPos,byPos);
//    scene->addItem(songselect);

    //text box
//    songChoice = new QLineEdit();
//    int qxPos = this->width()/2 - 150;
//    int qyPos = 800;
//    QSize size;
//    size.setHeight(80);
//    size.setWidth(300);
//    songChoice->resize(size);
//    QPoint check;
//    check.setX(qxPos);
//    check.setY(qyPos);
//    songChoice->move(check);
//    scene->addWidget(songChoice);


//    Button* playButton = new Button(QString("play"));
//    int cxPos = this->width()/2 - playButton->boundingRect().width()/2;
//    int cyPos = 1000;
//    playButton->setPos(cxPos,cyPos);
//    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
//    scene->addItem(playButton);
    //////////////////////////////////////////////////////////////////////////////////////////////
        Button* buttonOne = new Button(QString("Veiled in Black"));
        int cxPos = this->width()/2 - buttonOne->boundingRect().width()/2;
        int cyPos = 500;
        buttonOne->setPos(cxPos,cyPos);
        connect(buttonOne,SIGNAL(clicked()),this,SLOT(selectOne()));
        scene->addItem(buttonOne);

        Button* buttonTwo = new Button(QString("Battle of Oblivion"));
        int cxPos2 = this->width()/2 - buttonTwo->boundingRect().width()/2;
        int cyPos2 = 600;
        buttonTwo->setPos(cxPos2,cyPos2);
        connect(buttonTwo,SIGNAL(clicked()),this,SLOT(selectTwo()));
        scene->addItem(buttonTwo);

        Button* buttonThree = new Button(QString("Waltzing Gallop"));
        int cxPos3 = this->width()/2 - buttonThree->boundingRect().width()/2;
        int cyPos3 = 700;
        buttonThree->setPos(cxPos3,cyPos3);
        connect(buttonThree,SIGNAL(clicked()),this,SLOT(selectThree()));
        scene->addItem(buttonThree);

    QImage stuff("resources/startMenu2.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));
}

void Game::displayGameOverWindow()
{
    int lastHighScore = score->highScore;
    int myScore = score->getScore();
    QString scores = QString("Your Score: ")+QString::number(myScore);

    score->rewriteFile();
    scene->clear();
    songOptions->selectSong(11);
    songOptions->play();
    songOptions->startCount = 0;
    test->setupTextFile();

    QImage stuff("resources/startMenu2.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));

    //text
    QGraphicsTextItem* overText = new QGraphicsTextItem(QString("End of Game"));
    QFont titleFont("comic sans",30, QFont::Bold);
    overText->setFont(titleFont);
    overText->setDefaultTextColor(Qt::white);
    overText->setPos(this->width()/2 - overText->boundingRect().width()/2, 200);
    scene->addItem(overText);

    //report high Score;
    QGraphicsTextItem* displayHighScore = new QGraphicsTextItem(QString("High Score:") + QString::number(lastHighScore));
    QFont highScoreFont("comic sans",18);
    displayHighScore->setDefaultTextColor(Qt::white);
    displayHighScore->setFont(highScoreFont);
   displayHighScore->setPos(this->width()/2 - displayHighScore->boundingRect().width()/2, 300);
   scene->addItem(displayHighScore);


    //report score
    QGraphicsTextItem* displayScore = new QGraphicsTextItem( scores);
    QFont scoreFont("comic sans",18);
     displayScore->setDefaultTextColor(Qt::white);
     displayScore->setFont(scoreFont);
    displayScore->setPos(this->width()/2 - displayScore->boundingRect().width()/2, 400);
    scene->addItem(displayScore);

    //report got new highScore
    if ( myScore > lastHighScore){
        QGraphicsTextItem* displayIfNew = new QGraphicsTextItem( QString("New High Score!!"));
        QFont IfFont("comic sans",18);
         displayIfNew->setDefaultTextColor(Qt::blue);
         displayIfNew->setFont(IfFont);
        displayIfNew->setPos(this->width()/2 - displayIfNew->boundingRect().width()/2, 500);
        scene->addItem(displayIfNew);
    }

    Button* menu = new Button(QString("Main Menu"));
    menu->setPos(this->width()/2 - menu->boundingRect().width()/2  ,600);
    scene->addItem(menu);
    connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));

    // create playAgain button
    Button* playAgain = new Button(QString("Retry"));
    playAgain->setPos(this->width()/2 - playAgain->boundingRect().width()/2,710);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2 - quit->boundingRect().width()/2 ,820);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


}

void Game::pauseGame()
{
    if(!paused){
        paused = !paused;
        songOptions->pause();
        //fix
        enemys->timer->stop();

        //pause text
        pauseText = new QGraphicsTextItem(QString("PAUSE"));
        QFont titleFonts("comic sans",15);
        pauseText->setFont(titleFonts);
        pauseText->setDefaultTextColor(Qt::white);
        int txPoss = this->width()/2 - pauseText->boundingRect().width()/2;
        int tyPoss = 390;
        pauseText->setPos(txPoss,tyPoss);
        scene->addItem(pauseText);

        //play button
        plays = new Button(QString("Play"));
        plays->setPos(this->width()/2 - plays->boundingRect().width()/2,500);
        scene->addItem(plays);
        connect(plays,SIGNAL(clicked()),this,SLOT(unPause()));

        /*
        //Error found where playing another track after returning to main menu will still have the game paused and no song playing
        // go to main menu
        menu = new Button(QString("Main Menu"));
        menu->setPos(this->width()/2 - menu->boundingRect().width()/2  ,600);
        scene->addItem(menu);
        connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
        */

   }


        // disable all scene items
//    if(!paused2){
//        for (size_t i = 0, n = scene->items().size(); i < n; i++)
//            scene->items()[i]->setEnabled(false);
//        cout << "paused" << endl;
//    }
//    else{
//        for (size_t i = 0, n = scene->items().size(); i < n; i++)
//            scene->items()[i]->setEnabled(true);
//        cout << "not paused" << endl;
//    }
//    paused2 = !paused2;

}

void Game::unPause()
{
     paused = !paused;
    scene->removeItem(pauseText);
   delete pauseText;
    scene->removeItem(plays);
   delete plays;

    //fix menu first
    //scene->removeItem(menu);
    //delete menu;

    enemys->timer->start(5);
    songOptions->play();
   player->setFocus();

}

