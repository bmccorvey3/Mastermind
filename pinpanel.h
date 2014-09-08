#ifndef PINPANEL_H
#define PINPANEL_H

#include <QGraphicsItem>
#include "pin.h"

class PinPanel : public QGraphicsItem {
private:
    Pin panel[4];
    qreal x;
    qreal y;
public:
    PinPanel(qreal x, qreal y);
    QRectF boundingRect() const;
    void setPins(int RCRP, int RCWP);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Pin* pinAt(int i) {
        if (i < 4 && i >= 0)
            return &panel[i];
        throw "hi pin";
    }
};

#endif // PINPANEL_H
