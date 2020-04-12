#include "Score.h"
#include <QFont>
#include "Game.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

extern Game * game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

    ifstream file;
    file.open("highScores.txt");
    for(int i = 0; i < 3; i++){
        int test;
        file >> test;
        highs[i] = test;
    }
    file.close();
    highScore = highs[game->globalSongNum -1];
 //   rewriteFile();
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
        setDefaultTextColor(Qt::cyan);
}

void Score::increase2()
{
    score += 5;
    setPlainText(QString("Score: ") + QString::number(score));
        setDefaultTextColor(Qt::yellow);
}

void Score::decrease()
{
//    score += 100;
//    setPlainText(QString("Score: ") + QString::number(score));
//        setDefaultTextColor(Qt::red);
    game->noteCount->increase();
}


//erase
int Score::getScore(){
    return score;
}




void Score::rewriteFile()
{
    if(getScore() > highScore){
        highs[game->globalSongNum - 1] = getScore();
        ofstream files;
        files.open("highScores.txt");
        for(int i = 0; i < 3; i++){
            files << highs[i] << endl;
        }
        files.close();
    }

}
