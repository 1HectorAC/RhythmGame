#include "Health.h"
#include <QFont>
#include "Game.h"
extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)

{
    health = 1000;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Score: 1

}

int Health::gethealth(){
    return health;
}
