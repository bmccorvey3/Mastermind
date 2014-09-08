#ifndef PEGPANEL_H
#define PEGPANEL_H
#include <QGraphicsItem>
#include <QVector>
#include <peg.h>

class PegPanel : public QGraphicsItem {
private:
    Peg panel[6];
    qreal x = 150;
    qreal y = 50;
public:
    PegPanel();
    PegPanel(const PegPanel&) = delete;
    PegPanel& operator= (const PegPanel&) = delete;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //virtual ~PegPanel() noexcept;
    void setPos(qreal, qreal) {}
    Peg* pegAt(int i) {
        if (i < 6 && i >= 0)
            return &panel[i];
       throw "hi";
    }

};


#endif // PEGPANEL_H
