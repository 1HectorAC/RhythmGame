#ifndef SIDEGOAL_H
#define SIDEGOAL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class SideGoal: public QObject, public QGraphicsPixmapItem
{
public:
    SideGoal(QGraphicsItem * parent=0);
    void changeY();
    int getRandom();
};

#endif // SIDEGOAL_H
