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
    bool firstRelease;

    void destroyEnemy(int button);
    int array[4];
    void destroyEnemy2();
    int width;
    int height;
//private:

//    QMediaPlayer * bulletsound;
    QSet<int> keysPressed;

};



#endif // PLAYER_H
