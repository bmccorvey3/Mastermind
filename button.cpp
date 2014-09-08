#include <QtWidgets>
#include <QGraphicsItem>
#include <QApplication>
#include <QColor>
#include <QMessageBox>
#include "button.h"

Button::Button(Dealer *de, QGraphicsView *scn) : d{de}, scene{scn}
{
    setPos(50, 50);
}
QRectF Button::boundingRect() const {
     return QRectF(-30, -15.5, 60, 34);
 }
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QColor color = QColor{102, 51, 0};
    painter->setPen(Qt::NoPen);
    painter->setBrush(color.darker());
    painter->drawRoundRect(boundingRect().adjusted(0,0,1,1).translated(QPoint{2,2}), 100, 50);
    painter->setPen(QPen(color.darker(), 1));
    painter->setBrush(color);
    painter->drawRoundRect(boundingRect().translated(QPoint{x1,y1}), 100, 50);
    painter->setFont(QFont{"Arial", 14, QFont::Bold});
    painter->setPen(QPen{Qt::GlobalColor::yellow});
    QTextOption to;
    to.setAlignment(Qt::AlignCenter);
    painter->drawText(boundingRect().translated(QPoint{x1,y1}), "Guess!",to);


}
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    x1=y1=1;

    update();

}
void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
     Q_UNUSED(event);
    x1=y1=0;
    update();
     d->validate();
}
