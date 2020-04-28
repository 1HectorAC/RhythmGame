#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QSet>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(int x, int y, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void processMultiKey();
    void destroyEnemy();

    bool firstRelease;
    int array[4];
    int width;
    int height;
    int x_Position;
    int y_Position;
    QSet<int> keysPressed;
//    QMediaPlayer * hitsound;

};



#endif // PLAYER_H
