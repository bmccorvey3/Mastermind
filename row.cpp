#include "row.h"

Row::Row(qreal x, qreal y) : x{x}, y{y}, panel{new Plug{}, new Plug{}, new Plug{},new Plug{}}, pins{x +98, y}  {
    for (int i = 0; i < 4; ++i) {
        panel[i]->setPos(x -72 + i*34,y);
    }
    QGraphicsItem::setPos(x,y);
}

 QRectF Row::boundingRect() const {
     return QRectF{-102, -18, 230, 36};
 }

 void Row::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
     Q_UNUSED(option);
     Q_UNUSED(widget);

     painter->setPen(Qt::NoPen);

    painter->setBrush((QColor{51, 25, 0}));
    if (!active) {
        painter->setOpacity(0.5);
    }
    if (active) painter->drawRoundRect(boundingRect().translated(5,5));

    painter->setBrush((QColor{102, 51, 0}));
    painter->drawRoundRect(boundingRect());


 }


/*#include "row.h"

Row::Row(qreal x, qreal y, Plug p0, Plug p1,Plug p2,Plug p3) : x{x}, y{y}, panel{p0,p1,p2,p3} {
    for (int i = 0; i < 4; ++i) {
        panel[i].setPos(x -72 + i*34,y);
    }
    QGraphicsItem::setPos(x,y);
}



 QRectF Row::boundingRect() const {
     return QRectF{-102, -18, 230, 36};
 }

 void Row::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
     Q_UNUSED(option);
     Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);

    painter->setBrush((QColor{51, 25, 0}));
    painter->drawRoundRect(boundingRect().translated(5,5));

    painter->setBrush((QColor{102, 51, 0}));
    painter->drawRoundRect(boundingRect());


 }
*/
