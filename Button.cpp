#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rectangle for button.
    setRect(0,0,500,100);

    //Setup brush with stying.
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkYellow);
    setBrush(brush);

    // make text object with styling.
    text = new QGraphicsTextItem(name,this);
    QFont titleFont("comic sans",18);
    text->setFont(titleFont);

    //Center text on button.
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);


    // Allow responding to hover events.
    setAcceptHoverEvents(true);
}

//Action taken when mouse is pressed.
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

//Action taken when mouse hovers over. Will change color.
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

//Action taken when mouse leaves hovering. Will change color.
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkYellow);
    setBrush(brush);
}
