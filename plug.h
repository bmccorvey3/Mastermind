#ifndef PLUG_H
#define PLUG_H
#include "peg.h"
class Plug : public Peg
{
public:
    Plug();
    virtual ~Plug() = default;
    bool valid() {
        return color != Qt::GlobalColor::gray;
    }

operator bool() {
    return color != Qt::GlobalColor::gray;
}
    bool isValid(){
        return color != Qt::GlobalColor::gray;
    }

bool operator!() {
    return !bool();
}

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    bool dragOver;
    bool hasShadow;
};

#endif // PLUG_H
