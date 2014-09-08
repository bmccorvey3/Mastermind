#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include "dealer.h"
class Button : public QGraphicsItem
{
private:
    Dealer* d;
    QGraphicsView* scene;
    int x1=0, y1=0;
public:
    Button(Dealer *de, QGraphicsView *scn);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUTTON_H
