#ifndef PEG_H
#define PEG_H
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
enum class col
{
    RED,
    BLUE,
    YELLOW,
    GREEN,
    BLACK,
    WHITE
};
class Peg : public QGraphicsItem
{
public:
    Peg(col);
    Peg(QColor);
    Peg(const Peg& c);
    virtual ~Peg() = default;
    Peg& operator = (const Peg& rhs);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QColor getColor() {
        return color;
    }

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QColor color;
    virtual void add(QGraphicsScene& s);

private:
    bool dragged = false;

};

#endif // PEG_H
