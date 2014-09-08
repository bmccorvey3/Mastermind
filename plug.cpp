#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include "plug.h"

Plug::Plug() : Peg(Qt::GlobalColor::gray), dragOver{false}{
    setAcceptDrops(true);
}

void Plug::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
    if (event->mimeData()->hasColor()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }
}

void Plug::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void Plug::dropEvent(QGraphicsSceneDragDropEvent *event) {
    dragOver = false;
    if (event->mimeData()->hasColor()) {
        color = qvariant_cast<QColor>(event->mimeData()->colorData());
    setToolTip(QString("QColor(%1, %2, %3)\n%4")
                  .arg(color.red()).arg(color.green()).arg(color.blue())
                  .arg("Drag to another plug to copy color!"));
    }
    update();
}

void Plug::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //shadow
    painter->setPen(Qt::NoPen);
        if (!isEnabled()) {
           painter->setOpacity(0.5);

        }
        painter->setPen(Qt::NoPen);
        painter->setBrush(color.darker());
        if (isEnabled()) painter->drawEllipse(-12, -12, 30, 30);
        painter->setPen(QPen{color.darker(), 1});


    //plug
    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawEllipse(-15, -15, 30, 30);
}
