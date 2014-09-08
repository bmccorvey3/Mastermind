#include "pin.h"
#include <QtWidgets>
#include <QGraphicsItem>
#include <QApplication>

Pin::Pin() : color{QColor{Qt::GlobalColor::gray}} {

    setToolTip(QString("%1\n%2\n%3")
               .arg("Black = correct positiion").arg("White = correct color, wrong position").arg("Grey = incorrect"));
}

Pin::Pin(const Pin &c) : color{c.color} {

}

Pin& Pin::operator = (const Pin& rhs) {
     Pin temp{rhs};
     std::swap(color, temp.color);
     return *this;
}

QRectF Pin::boundingRect() const {
    return QRectF(-6,-6,12,12);
}

void Pin::set(correctness val) {
    if(val == correctness::RCRP) {
        color = QColor{Qt::GlobalColor::black};
        setToolTip(QString("Peg in correct position!"));
                //.arg("Peg in correct position!"));
    }
    else if (val == correctness::RCWP) {
        color = QColor{Qt::GlobalColor::white};
        //setToolTip("Correct Peg but not correct position!");
    }
    else {
        color = QColor{Qt::GlobalColor::gray};
    }
}

void Pin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (!isEnabled()) {
       painter->setOpacity(0.5);

    }
    painter->setPen(QPen(Qt::black,1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(-5,-5, 10, 10);
}


