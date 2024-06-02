
#include <QApplication>
#include <QGraphicsScene>
#include "../include/MyRect.h"
#include <QGraphicsView>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    MyRect* rect = new MyRect();
    QGraphicsView* view = new QGraphicsView(scene);

    rect->setRect(0,0,100,100);
    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    view->show();

    //the following make the window quit ..
    // delete(scene);
    // delete(rect);
    return a.exec();
}
