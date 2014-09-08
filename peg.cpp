#include "peg.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QBitmap>
//

Peg::Peg(col c) {
    switch (c) {
    case col::RED: color = QColor{Qt::GlobalColor::red};
        break;
    case col::BLUE: color = QColor{Qt::GlobalColor::blue};
        break;
    case col::GREEN : color = QColor{Qt::GlobalColor::green};
        break;
    case col::YELLOW : color = QColor{Qt::GlobalColor::yellow};
        break;
    case col::BLACK : color = QColor{Qt::GlobalColor::black};
        break;
    case col::WHITE : color = QColor{Qt::GlobalColor::white};
        break;
    };
    setToolTip(QString("QColor(%1, %2, %3)\n%4")
                  .arg(color.red()).arg(color.green()).arg(color.blue())
                  .arg("Click and drag this color onto the board!"));
        setCursor(Qt::OpenHandCursor);
        setAcceptedMouseButtons(Qt::LeftButton);

}

Peg::Peg(QColor c) : color{c} {
setToolTip(QString("QColor(%1, %2, %3)\n%4")
              .arg(color.red()).arg(color.green()).arg(color.blue())
              .arg("Click and drag this color onto the board!"));
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}
Peg::Peg(const Peg& c) : color{c.color} {

}
 Peg& Peg::operator = (const Peg& rhs) {
     Peg temp{rhs};
     std::swap(color, temp.color);
     return *this;
}

 QRectF Peg::boundingRect() const {
     return QRectF(-15.5, -15.5, 34, 34);
 }

 void Peg::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
     Q_UNUSED(option);
     Q_UNUSED(widget);
     if (!dragged) {
              painter->setPen(Qt::NoPen);
              painter->setBrush(Qt::darkGray);
              painter->drawEllipse(-12, -12, 30, 30);
          }
          painter->setPen(QPen(Qt::black, 1));
          painter->setBrush(QBrush(color));
          painter->drawEllipse(-15, -15, 30, 30);
 }
 void Peg::mousePressEvent(QGraphicsSceneMouseEvent *) {
     setCursor(Qt::ClosedHandCursor);
 }
 void Peg::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
     if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
         .length() < QApplication::startDragDistance()) {
         return;
     }
     dragged = true;
          QDrag *drag = new QDrag(event->widget());
          QMimeData *mime = new QMimeData;
          drag->setMimeData(mime);
              mime->setColorData(color);
              mime->setText(QString("#%1%2%3")
                            .arg(color.red(), 2, 16, QLatin1Char('0'))
                            .arg(color.green(), 2, 16, QLatin1Char('0'))
                            .arg(color.blue(), 2, 16, QLatin1Char('0')));

              QPixmap pixmap(34, 34);
              pixmap.fill(Qt::white);

              QPainter painter(&pixmap);
              painter.translate(15, 15);
              painter.setRenderHint(QPainter::Antialiasing);
              paint(&painter, 0, 0);
              painter.end();

              pixmap.setMask(pixmap.createHeuristicMask());

              drag->setPixmap(pixmap);
              drag->setHotSpot(QPoint(15, 20));


          drag->exec();
          setCursor(Qt::OpenHandCursor);
          dragged = false;
 }
 void Peg::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
     setCursor(Qt::OpenHandCursor);
 }
void Peg::add(QGraphicsScene& s) {
    s.addItem(this);
}
