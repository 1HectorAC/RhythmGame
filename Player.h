#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QSet>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void processMultiKey();
    void destroyEnemy();

    bool firstRelease;
    int array[4];
    int width;
    int height;
    QSet<int> keysPressed;
//    QMediaPlayer * hitsound;

};



#endif // PLAYER_H
