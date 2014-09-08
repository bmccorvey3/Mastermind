#include "pegpanel.h"

PegPanel::PegPanel() : panel{Peg{col::RED}, Peg{col::BLUE}, Peg{col::GREEN}, Peg{col::BLACK},Peg{col::YELLOW}, Peg{col::WHITE}} {
    //panel =  {Peg{col::RED}, Peg{col::BLUE}, Peg{col::GREEN}, Peg{col::BLACK},Peg{col::YELLOW}, Peg{col::WHITE}};
    /*panel[0] = Peg{col::RED};
    panel [1]  = Peg{col::BLUE};
    panel[2]  = Peg{col::GREEN};
    panel [3] = Peg{col::BLACK};
    panel [4] = Peg{col::YELLOW};
    panel [5] = Peg{col::WHITE};*/
    for (int i = 0; i < 6; ++i) {
        panel[i].setPos(x,y-72 + i*34);
    }
    QGraphicsItem::setPos(x,y);
}

 QRectF PegPanel::boundingRect() const {
     return QRectF{-18, -102, 36, 230};
 }

 void PegPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
     Q_UNUSED(option);
     Q_UNUSED(widget);
    painter->setPen(Qt::black);
    painter->setBrush((Qt::lightGray));
    painter->drawRoundRect(boundingRect());

    /*for (int i = 5; i >= 0; --i) {
        //panel[i].setPos(x-40,y+i*35);
        //panel[i].paint(painter, option, widget);
    }*/

 }
