#ifndef PIN_H
#define PIN_H

#include <QGraphicsItem>
#include <QPainter>

enum class pin_col {BLACK,WHITE,GRAY};
enum class correctness {RCRP, RCWP, WCWP};

class Pin : public QGraphicsItem {

private:
    QColor color;

public:
    Pin();
    virtual ~Pin() = default;
    Pin(const Pin& c);
    Pin& operator = (const Pin& rhs);
    QRectF boundingRect() const;
    void set(correctness val);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PIN_H
