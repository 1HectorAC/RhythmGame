#include <QFont>
#include "Game.h"
#include "NoteCount.h"

extern Game * game;

NoteCount::NoteCount(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //Setup value to display.
    total = game->listSetup->getTotalNotes();
    count = 0;

    //Add styling to text object.
    setPlainText(QString::number(count) + QString("/") + QString::number(total));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", game->GLOBAL_HEIGHT / 60));
}

//Increase note count and update text display of it.
void NoteCount::increase()
{
    count++;
    setPlainText(QString::number(count) + QString("/") + QString::number(total));
}
