#include "Score.h"
#include "Game.h"
#include <QFont>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0.
    score = 0;

    // Draw text and setup styling.
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

    //Get the highest scores from the file.
    ifstream file;
    file.open("highScores.txt");
    for(int i = 0; i < 3; i++){
        int test;
        file >> test;
        highs[i] = test;
    }
    file.close();

    //Get the high score of the current track.
    highScore = highs[game->globalSongNum -1];
}

//Increase the score alittle and update text.
void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));

    //Adjust color when score is increased.
    setDefaultTextColor(Qt::cyan);
}

//Increase the score a lot and update text.
void Score::increase2(){
    score += 5;
    setPlainText(QString("Score: ") + QString::number(score));

     //Adjust color when score is increased.
    setDefaultTextColor(Qt::yellow);
}

//Decrease score and update text.
void Score::decrease(){
//    score += 100;
//    setPlainText(QString("Score: ") + QString::number(score));
//    setDefaultTextColor(Qt::red);

    //Curretnly for testing misses. Remove/adjust later.
    game->noteCount->increase();
}


//Get score value.
int Score::getScore(){
    return score;
}

//update high score file if current score is higher.
void Score::rewriteFile()
{
    //Compare current high score with in file high score.
    if(getScore() > highScore){
        //Rewrite high score in array with current high score.
        highs[game->globalSongNum - 1] = getScore();

        //Rewrite high score text file with values in array.
        ofstream files;
        files.open("highScores.txt");
        for(int i = 0; i < 3; i++){
            files << highs[i] << endl;
        }
        files.close();
    }

}
