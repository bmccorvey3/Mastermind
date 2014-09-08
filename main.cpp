#include <QApplication>
#include <QGraphicsView>
#include <QTime>
#include <QPushButton>
#include <QMessageBox>
#include "peg.h"
#include "mainwindow.h"
#include "pegpanel.h"
#include "row.h"
#include "dealer.h"
#include "button.h"


class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    virtual void resizeEvent(QResizeEvent *)
    {
    }
};
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//! [0]
//! [1]
    QGraphicsScene scene(-350, -350, 700, 700);


    /*Peg *item = new Peg{col::BLUE};
    item->setPos(100, 50);*/
PegPanel *p = new PegPanel;
 scene.addItem(p);
for (int i = 0; i < 6; ++i) {
    scene.addItem(p->pegAt(i));
}

/*PinPanel *pinPan = new PinPanel{-30,40};
scene.addItem(pinPan);
for(int i = 0; i < 4; ++i) {
    scene.addItem(pinPan->pinAt(i));
}*/

/*Row *r = new Row{-100, 150};
scene.addItem(r);
for (int i = 0; i < 4; ++i) {
   scene.addItem(r->plugAt(i));
}*/

//qreal x{-100}, y{300}, s{5};
//Row *rows[10] = {new Row{x,y}, new Row{x,y-s}, new Row{x,y-2*s}, new Row{x,y-3*s}, new Row{x,y-4*s}, new Row{x,y-5*s}, new Row{x,y-6*s}, new Row{x,y-7*s}, new Row{x,y-8*s}, new Row{x,y-9*s} };




//! [1]
//! [2]

    GraphicsView view(&scene);
    Dealer d{&view};
    for (int i = 0; i < 10; ++i) {
        scene.addItem(d.rowAt(i));
        scene.addItem(d.rowAt(i)->pinPanel());
        for (int j = 0; j < 4; ++j) {
            scene.addItem(d.rowAt(i)->plugAt(j));
            scene.addItem(d.rowAt(i)->pinPanel()->pinAt(j));
        }
    }
    /*for (int i = 0; i < 4; ++i) {
        scene.addItem(d.pegAt(i));
    }*/
scene.addItem(d.getButton());
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(230, 200, 167));
    view.setWindowTitle("Mastermind");
     view.show();

 app.exec();
delete p;
p = nullptr;

}
