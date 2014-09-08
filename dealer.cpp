#include <QtWidgets>
#include <QObject>
#include "dealer.h"
#include "button.h"
#include "peg.h"

Dealer::Dealer(QGraphicsView *scn) : x{-100}, y{300}, curr{0}, rows{new Row{x,y}, new Row{x,y-s}, new Row{x,y-2*s}, new Row{x,y-3*s}, new Row{x,y-4*s}, new Row{x,y-5*s}, new Row{x,y-6*s}, new Row{x,y-7*s}, new Row{x,y-8*s}, new Row{x,y-9*s}} , soln{nullptr}, val{nullptr}
{

    val = new Button(this, scn);
    val->setPos(x+175, y);
    rows[0]->setActive(true);
    for (int i=1; i < 10; ++i) {
        rows[i]->setActive(false);
    }

    generateCode();
    for (int i = 0; i < 4; ++i) {
        soln[i]->setPos(x -72 + i*34,y-500);
        solcnt[soln[i]->getColor().rgb()]++;
    }

}


 /*void Dealer::add(QGraphicsScene &s) {
     for (int i = 0; i < 10; ++i) {
         rows[i].add(s);
     }

 }*/
//Dealer::connect();
void Dealer::generateCode() {
    for (int i = 0; i < 4; ++i) {
        int x = qrand() %6;
        col c = col(x);
        soln[i] = new Peg{c};
    }

}

void Dealer::validate() {
    int RCRP = 0;
    int RCWP = 0;
    int second_iter = 0;
    Row* cR = rows[curr];

     //printf("hello");
    if ((!cR->isValid())) {
        QMessageBox mess{QMessageBox::Warning, "nope","You must complete your guess", QMessageBox::Ok};
        mess.exec();
        return;
    }
    if (curr >=9) {
        QMessageBox mess{QMessageBox::NoIcon, "Aww", "You Lost", QMessageBox::Ok};
        mess.exec();
        exit(0);
    }
    Row* next = rows[curr+1];
    cR->setActive(false);
   /* for (int i = 0; i < 4; ++i) {
        if (cR->plugAt(i)->getColor() == soln[i]->getColor()) {
            RCRP++;
            if(boolArray[i]) {
                //RCRP++;
                RCWP--;
            }
        }
        else  {
            for(int j = 0; j < 4; ++j) {
                if (!boolArray[j] && j!=i && cR->plugAt(j)->getColor() == soln[i]->getColor()) {
                    RCWP++;
                    boolArray[j] = true;
                }
            }
        }
    }
    */
    QHash<QRgb, int> map{solcnt};
   /* for (int i = 0; i < 4; ++i) {
        int n = map.value(cR->plugAt(i)->getColor().rgb());
        if (n > 0) {
            if (cR->plugAt(i)->getColor()==soln[i]->getColor()) {
                ++RCRP;
                //map[cR->plugAt(i)->getColor().rgb()]--;
            } else {
                ++RCWP;

            }
            map[cR->plugAt(i)->getColor().rgb()]--;
        }
    }*/

    for (int i = 0; i < 4; ++i) {
        if (cR->plugAt(i)->getColor()==soln[i]->getColor()) {
            ++RCRP;
            map[cR->plugAt(i)->getColor().rgb()]--;
        }
    }
    for (int i = 0; i < 4; ++i) {
        int n = map.value(cR->plugAt(i)->getColor().rgb());
        if (n > 0 && cR->plugAt(i)->getColor()!=soln[i]->getColor()) {
                ++RCWP;
                map[cR->plugAt(i)->getColor().rgb()]--;
        }
    }


    qDebug() << RCWP;

    PinPanel* pinPanel = cR->pinPanel();
    pinPanel->setPins(RCRP,RCWP);

    if(RCRP == 4) {
        QMessageBox mess{QMessageBox::NoIcon, "Hurray!", "You Win!", QMessageBox::Ok};
        mess.exec();
        cR->setActive(false);
        exit(0);
    }
    
    cR->setActive(false);
    next->setActive(true);
        cR->update();
        next->update();
++curr;






}
