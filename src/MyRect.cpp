#include "../include/MyRect.h"
#include <QGraphicsScene>
MyRect::MyRect() {}

void MyRect::keyPressEvent(QKeyEvent *event){
//    qDebug() << "A key has been pressed";
	switch (event->key()) {
		case Qt::Key_A:
			setPos(x()-10, y());
			break;
		case Qt::Key_D:
			setPos(x()+10, y());
			break;
		case Qt::Key_W:
			setPos(x(), y()-10);
			break;
		case Qt::Key_S:
			setPos(x(), y()+10);
			break;
		case Qt::Key_Space:
			Bullet * bullet = new Bullet();
			scene()->addItem(bullet);
		default:
			break;
	}
}

