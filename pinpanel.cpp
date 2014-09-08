#include "pinpanel.h"

PinPanel::PinPanel(qreal x, qreal y) : x{x}, y{y} {
    for(int i = 0; i<4; ++i) {
        if(i==0) {
            panel[i].setPos(x-8,y-8);
        }
        if(i==1) {
            panel[i].setPos(x-8,y+8);
        }
        if(i==2) {
            panel[i].setPos(x+8,y-8);
        }
        if(i==3) {
            panel[i].setPos(x+8,y+8);
        }
    }
    QGraphicsItem::setPos(x,y);
}

QRectF PinPanel::boundingRect() const {
    return QRectF(-16, -16, 32, 32);
}

void PinPanel::setPins(int RCRP, int RCWP) {
    int pin_num = 0;
    if(RCRP + RCWP > 4) {
        //throw "Wrong number of pins!";
    }
    for(int i = 0; i < RCRP; ++i) {
        panel[pin_num].set(correctness::RCRP);
        pin_num++;
    }
    for(int i = 0; i< RCWP; ++i) {
        panel[pin_num].set(correctness::RCWP);
        pin_num++;
    }
}

void PinPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget) {

    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (!isEnabled()) {
       painter->setOpacity(0.5);

    }
    painter->setPen(Qt::black);
    painter->setBrush(QColor(204,153,0));
    painter->drawRoundRect(boundingRect());
}
