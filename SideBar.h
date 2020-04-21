#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class SideBar: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT

public:
    SideBar(QGraphicsItem * parent=0);
    void moveUp();
    void moveDown();

    int objHeight ;
    int positionPoint;
};

#endif // SIDEBAR_H
