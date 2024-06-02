
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QApplication>


// class My2Rect : public QGraphicsItem{
// public:
//     My2Rect();
//     void keyPressEvent(QKeyEvent * event) override;
//     QRectF boundingRect() const override;
//     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
// };

// My2Rect::My2Rect() {}


// QRectF My2Rect::boundingRect() const {
//     // Define the bounding rectangle of the item
//     return QRectF(0, 0, 100, 100);
// }

// void My2Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//     // Define how the item is painted
//     painter->setBrush(Qt::blue);
//     painter->drawRect(0, 0, 100, 100);
// }

// void My2Rect::keyPressEvent(QKeyEvent *event) {
//     qDebug() << "A key has been pressed";
// }



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    MyRect* rect = new MyRect();
    QGraphicsView* view = new QGraphicsView(scene);

    rect->setRect(0,0,100,100);
    scene->addItem(rect);

    view->show();

    // delete(scene);
    // delete(rect);
    return a.exec();
}
