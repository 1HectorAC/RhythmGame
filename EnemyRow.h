#ifndef ENEMYROW_H
#define ENEMYROW_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTime>
class EnemyRow:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    EnemyRow(QGraphicsItem * parent=0);
    int rows;
    int position;
    QTimer * timer;
public slots:
    void spawn(int position);
    void dropEnemys();
};

#endif // ENEMYROW_H
