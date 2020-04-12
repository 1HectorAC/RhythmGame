#ifndef NOTECOUNT_H
#define NOTECOUNT_H

#include <QGraphicsItem>
class NoteCount: public QGraphicsTextItem
{
public:
    NoteCount(QGraphicsItem * parent = 0);
    int total;
    int count;
    void increase();
};

#endif // NOTECOUNT_H
