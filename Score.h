#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    void increase2();
    void decrease();
    void rewriteFile();
    int getScore();
    int highScore;
    int highs[3];
    int score;
private:
//    int score;
};
#endif // SCORE_H
