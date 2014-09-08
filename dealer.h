#ifndef DEALER_H
#define DEALER_H
#include <QPushButton>
#include <QGraphicsView>
//#include "button.h"
#include "row.h"
class Button;
class Dealer : public QObject
{
private:
    constexpr static  qreal s{50};
    //static qrand rand;
    qreal x;
    qreal y;
    int curr;
    Row *rows[10];//[10];
    Peg *soln[4];
    bool boolArray[4];
    bool showSln = false;
     void generateCode();
     Button* val;
     QHash<QRgb, int> solcnt;
public:
    Dealer(QGraphicsView *scn);
    void add(QGraphicsScene& s);
    Row* rowAt(int i) {
        if (i < 10 && i >= 0)
            return rows[i];
        throw "hi";
    }
    Button* getButton() {
        return val;
    }
Peg* pegAt(int i) {
    if (i < 4 && i >= 0)
        return soln[i];
    throw "hi";
}


public slots:
    void validate();

};



//~

#endif // DEALER_H
