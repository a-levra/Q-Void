#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsItem>

#include <QDebug>

class MyRect : public QGraphicsRectItem{
public:
    MyRect();
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H
