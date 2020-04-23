#ifndef NOTECOUNT_H
#define NOTECOUNT_H

#include <QGraphicsItem>
class NoteCount: public QGraphicsTextItem
{
public:
    NoteCount(QGraphicsItem * parent = 0);
    void increase();
    int total;
    int count;
};

#endif // NOTECOUNT_H
