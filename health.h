#ifndef MISSED_H
#define MISSED_H

#include <QGraphicsTextItem>
class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int gethealth();
private:
    int health;
};

#endif // MISSED_H
