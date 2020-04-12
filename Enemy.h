#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    //~Enemy();
     QTimer * pauseCheck;
    QTimer * movement;
    void setImage(int value);
    void setTimer(QTimer *timer);
public slots:
    void move();
    void stopMove();

};


#endif // ENEMY_H
