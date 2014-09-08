#ifndef ROW_H
#include "plug.h"
#include "pinpanel.h"
#define ROW_H

class Row : public QGraphicsItem {
private:
    qreal x;
    qreal y;
    Plug *panel[4];
    PinPanel pins;
    bool active = false;


public:
    Row(qreal x, qreal y);
    Row(const Row&) = delete;
    Row& operator= (const Row&) = delete;
    virtual ~Row() {
        for (int i =0; i < 4; ++i) {
            delete panel[i];
        }
        //delete [] panel;
    }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPos(qreal, qreal) {}
        Plug* plugAt(int i) {
            if (i < 4 && i >= 0)
                return panel[i];
            throw "hi";
        }
    void setActive(bool b) {
        active = b;
        pins.setEnabled(b);
        for (int i = 0; i < 4; ++i) {
            if (panel[i] != nullptr)
                panel[i]->setEnabled(b);
            if (pins.pinAt(i) != nullptr)
                pins.pinAt(i)->setEnabled(b);
        }
    }
    PinPanel* pinPanel() {
        return &pins;
    }
bool isValid() {
    for (int i=0; i < 4; ++i) {
        if (!(panel[i]->isValid())) return false;
    }
    return true;
}
    operator bool() {
        /*for (int i=0; i < 4; ++i) {
            if (!*panel[i]) return false;
        }*/
        return true;
    }
    bool operator!() {
        return !bool();
    }
};


/*
class Row : public QGraphicsItem {
private:
    qreal x;
    qreal y;
    Plug panel[4];
    //PinPanel pins;
    bool active = false;

public:
    Row(qreal x, qreal y,Plug p0 = Plug{}, Plug p1= Plug{},Plug p2= Plug{},Plug p3= Plug{});
    Row(const Row&) = delete;
    Row& operator= (const Row&) = delete;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPos(qreal, qreal) {}
        Plug* plugAt(int i) {
            if (i < 4 && i >= 0)
                return &panel[i];
            throw "hi";
        }
    void setActive(bool b) {
        active = b;
    }
};
*/
#endif // ROW_H
