#include "Health.h"
#include "Game.h"
#include <QFont>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)

{
    //Setup up health and text for it.
    health = 1000;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

//Lower health value and show in text.
void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Score: 1

}

//Get health value.
int Health::gethealth(){
    return health;
}
