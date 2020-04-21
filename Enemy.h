#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int height, int width, QGraphicsItem * parent=0);
    //~Enemy();
     QTimer * pauseCheck;
    QTimer * movement;
    void setImage(int value);
    void setTimer(QTimer *timer);
    int height;
    int width;
public slots:
    void move();

};


#endif // ENEMY_H
