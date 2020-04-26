#include "Game.h"
#include "EnemyRow.h"
#include "Enemy.h"
#include "Player.h"
#include "Score.h"
#include "ListSetup.h"
#include "ManageSideBars.h"
#include "Button.h"
#include "Test.h"
#include "math.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <fstream>
#include <QLineEdit>
#include <QPoint>
#include <sstream>
#include <QHBoxLayout>
#include <QString>
#include <QGraphicsTextItem>
#include <iostream>

using namespace std;

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    // Set the the width in height size of screen.
    GLOBAL_WIDTH = 1920;
    GLOBAL_HEIGHT = 1080;

    //Setup scene and some settings.
    scene->setSceneRect(0,0, GLOBAL_WIDTH, GLOBAL_HEIGHT);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setFixedSize(GLOBAL_WIDTH,GLOBAL_HEIGHT);

   //Setup songOptions to control songs later.
    songOptions = new SongOptions;

}

void Game::start(){
    //Need to clear screen for when playing again. This function can be called multiple times.
    scene->clear();

    //Set pause boolean to check if paused.
    paused = false;

    //listSetup object used for making right track to play.
    listSetup = new ListSetup;

    //Testing object used in making test tracks with song playing.
    test = new Test();

    //Setup background image.
    QImage stuff("resources/gameScreen4.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));


    //Add score object to scene.
    score = new Score();
    score->setPos(score->x(), score->y() + GLOBAL_HEIGHT / 55);
    scene->addItem(score);

    //health
//    health = new Health();
//    health->setPos(health->x() + globalWidth / 3, health->y() + globalHeight / 55);
//    scene->addItem(health);

    //Add song title object to scene.
    string test = listSetup->title(globalSongNum);
    QString test2 = QString::fromStdString(test);
    QGraphicsTextItem * titleSong = new QGraphicsTextItem(QString("~" + test2 + "~"));
    QFont titleFont("times", GLOBAL_HEIGHT / 60);
    titleSong->setFont(titleFont);
    titleSong->setDefaultTextColor(Qt::white);
    titleSong->setPos(GLOBAL_WIDTH / 4, titleSong->y());
    scene->addItem(titleSong);

    //Add player object to scene.
    player = new Player();
    player->setPos(round(GLOBAL_WIDTH * (.365)), GLOBAL_WIDTH * 0.467);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //Add EnemyRow object to scene.
    enemys = new EnemyRow();
    scene->addItem(enemys);

    //Add ManageSideBar object to scene.
    manageSideBar = new ManageSideBars();

    //Setup which track to play for listSetup.
    listSetup->makeList(globalSongNum);

    //Add NoteCount object to scene.
    noteCount = new NoteCount();
    noteCount->setPos(GLOBAL_WIDTH -  155, noteCount->y() + GLOBAL_HEIGHT / 55);
    scene->addItem(noteCount);

    //Start droping enemies and start song.
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),enemys,SLOT(dropEnemys()));
    songOptions->selectSong(globalSongNum);
    songOptions->startCount = 0;
    timer->start(180);

    show();
}

//Need to adjust how set globalSongNum.
//Function to set globalSongNum to 1 and start game.
void Game::selectTransition(){
    globalSongNum = 1;
    start();
}
//Function to set globalSongNum to 1 and start game.
void Game::selectOne(){
    globalSongNum = 1;
    start();
}
//Function to set globalSongNum to 2 and start game.
void Game::selectTwo(){
    globalSongNum = 2;
    start();
}
//Function to set globalSongNum to 3 and start game.
void Game::selectThree(){
    globalSongNum = 3;
    start();
}


void Game::displayMainMenu(){
    //Need to clear screen for when playing again. This function can be called multiple times.
    scene->clear();

    //Play intro song.
    songOptions->selectSong(10);
    songOptions->play();

    //Add title text object to scene.
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Rhythm Game"));
    QFont titleFont("comic sans",28, QFont::Bold);
    titleFont.setUnderline(true);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 300;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //Add author text object to scene.
    QGraphicsTextItem* titleTexts = new QGraphicsTextItem(QString("By H&A inc."));
    QFont titleFonts("comic sans",15);
    titleTexts->setFont(titleFonts);
    titleTexts->setDefaultTextColor(Qt::white);
    int txPoss = this->width()/2 - titleTexts->boundingRect().width()/2;
    int tyPoss = 390;
    titleTexts->setPos(txPoss,tyPoss);
    scene->addItem(titleTexts);

    //Add button object to play Song1.
    Button* buttonOne = new Button(QString("Song 1"));
    int cxPos = this->width()/2 - buttonOne->boundingRect().width()/2;
    int cyPos = 500;
    buttonOne->setPos(cxPos,cyPos);
    connect(buttonOne,SIGNAL(clicked()),this,SLOT(selectOne()));
    scene->addItem(buttonOne);

    //Add button object to play Song1.
    Button* buttonTwo = new Button(QString("Song 2"));
    int cxPos2 = this->width()/2 - buttonTwo->boundingRect().width()/2;
    int cyPos2 = 600;
    buttonTwo->setPos(cxPos2,cyPos2);
    connect(buttonTwo,SIGNAL(clicked()),this,SLOT(selectTwo()));
    scene->addItem(buttonTwo);

    //Add button object to play Song1.
    Button* buttonThree = new Button(QString("Song 3"));
    int cxPos3 = this->width()/2 - buttonThree->boundingRect().width()/2;
    int cyPos3 = 700;
    buttonThree->setPos(cxPos3,cyPos3);
    connect(buttonThree,SIGNAL(clicked()),this,SLOT(selectThree()));
    scene->addItem(buttonThree);

    //Set background image.
    QImage stuff("resources/startMenu2.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));
}

void Game::displayGameOverWindow(){
    //Keep track of current score and the highscore for the track before clearing scene.
    int lastHighScore = score->highScore;
    int myScore = score->getScore();
    //Write over high score in file if necessary.
    score->rewriteFile();
    scene->clear();

    //Play game end song.
    songOptions->selectSong(11);
    songOptions->play();
    songOptions->startCount = 0;

    //Make test file with test track.
    test->setupTextFile();

    //Set background image.
    QImage stuff("resources/startMenu2.png");
    setBackgroundBrush(QBrush(stuff.scaled(GLOBAL_WIDTH,GLOBAL_HEIGHT)));

    //Add End of Game text to scene.
    QGraphicsTextItem* overText = new QGraphicsTextItem(QString("End of Game"));
    QFont titleFont("comic sans",30, QFont::Bold);
    overText->setFont(titleFont);
    overText->setDefaultTextColor(Qt::white);
    overText->setPos(this->width()/2 - overText->boundingRect().width()/2, 200);
    scene->addItem(overText);

    //Add highScore text to scene.
    QGraphicsTextItem* displayHighScore = new QGraphicsTextItem(QString("High Score:") + QString::number(lastHighScore));
    QFont highScoreFont("comic sans",18);
    displayHighScore->setDefaultTextColor(Qt::white);
    displayHighScore->setFont(highScoreFont);
   displayHighScore->setPos(this->width()/2 - displayHighScore->boundingRect().width()/2, 300);
   scene->addItem(displayHighScore);


    //Add current score text to scene.
   QString scores = QString("Your Score: ")+QString::number(myScore);
    QGraphicsTextItem* displayScore = new QGraphicsTextItem( scores);
    QFont scoreFont("comic sans",18);
     displayScore->setDefaultTextColor(Qt::white);
     displayScore->setFont(scoreFont);
    displayScore->setPos(this->width()/2 - displayScore->boundingRect().width()/2, 400);
    scene->addItem(displayScore);

    //Add text stating if new highscore was set.
    if ( myScore > lastHighScore){
        QGraphicsTextItem* displayIfNew = new QGraphicsTextItem( QString("New High Score!!"));
        QFont IfFont("comic sans",18);
         displayIfNew->setDefaultTextColor(Qt::blue);
         displayIfNew->setFont(IfFont);
        displayIfNew->setPos(this->width()/2 - displayIfNew->boundingRect().width()/2, 500);
        scene->addItem(displayIfNew);
    }

    //Add button to go to main menu to scene.
    Button* menu = new Button(QString("Main Menu"));
    menu->setPos(this->width()/2 - menu->boundingRect().width()/2  ,600);
    scene->addItem(menu);
    connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));

    //Add button to retry current song to scene.
    Button* playAgain = new Button(QString("Retry"));
    playAgain->setPos(this->width()/2 - playAgain->boundingRect().width()/2,710);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));

    //Add button to quit to scene.
    Button* quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2 - quit->boundingRect().width()/2 ,820);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


}

void Game::pauseGame(){
    //Check if game can pause.
    if(!paused){
        paused = !paused;

        //Pause song and droping enemies at nearly the same time to sustain song sync with track.
        enemys->timer->stop();
        songOptions->pause();


        //Add pause text to scene.
        pauseText = new QGraphicsTextItem(QString("PAUSE"));
        QFont titleFonts("comic sans",15);
        pauseText->setFont(titleFonts);
        pauseText->setDefaultTextColor(Qt::white);
        int txPoss = this->width()/2 - pauseText->boundingRect().width()/2;
        int tyPoss = 390;
        pauseText->setPos(txPoss,tyPoss);
        scene->addItem(pauseText);

        //Add play button to scene.
        plays = new Button(QString("Play"));
        plays->setPos(this->width()/2 - plays->boundingRect().width()/2,500);
        scene->addItem(plays);
        connect(plays,SIGNAL(clicked()),this,SLOT(unPause()));

        //Add main menu button to scene.
        menu = new Button(QString("Main Menu"));
        menu->setPos(this->width()/2 - menu->boundingRect().width()/2  ,600);
        scene->addItem(menu);
        connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));

   }
}

void Game::unPause()
{
    paused = !paused;

    //Remove pause text.
    scene->removeItem(pauseText);
   delete pauseText;

    //Remove play button.
    scene->removeItem(plays);
   delete plays;

    //Remove main menu button.
    scene->removeItem(menu);
    delete menu;

    //Start song and enemy drop timer. These need to be next to each other to lower delay bettween the two.
    enemys->timer->start(5);
    songOptions->play();

    player->setFocus();

}

