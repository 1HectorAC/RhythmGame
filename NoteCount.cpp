#include "NoteCount.h"
#include <QFont>
#include "Game.h"
extern Game * game;

NoteCount::NoteCount(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    total = game->listSetup->getTotalNotes();
    count = 0;
    setPlainText(QString::number(count) + QString("/") + QString::number(total));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void NoteCount::increase()
{
    count++;
    setPlainText(QString::number(count) + QString("/") + QString::number(total));
}
