#include "Player.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPos(MAIN_WINDOW_WIDTH / 2 - PLAYER_WIDTH / 2, MAIN_WINDOW_HEIGHT - PLAYER_HEIGHT);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
	setPixmap(QPixmap(":/assets/spacecraft2.png"));
//	health = new Health();
//	health->setPos(health->x(), health->y() + 25);
//	scene()->addItem(health);
}

void Player::keyPressEvent(QKeyEvent *event){
	if (event->isAutoRepeat()) {
		return;
	}
	switch (event->key()) {
		case Qt::Key_A:
			TrySetPos(x()-10, y());
			break;
		case Qt::Key_D:
			TrySetPos(x()+10, y());
			break;
		case Qt::Key_W:
			TrySetPos(x(), y()-10);
			break;
		case Qt::Key_S:
			TrySetPos(x(), y()+10);
			break;
		case Qt::Key_Escape:
			exit(0);
			break;
		case Qt::Key_Space:
			printf("Player::keyPressEvent() x: %f y: %f\n", pos().x(), pos().y()); // debug
			Bullet * bullet = new Bullet(x() + PLAYER_WIDTH / 2, y());
//			Bullet * bullet = new Bullet();
			scene()->addItem(bullet);
	}
}

void Player::TrySetPos(qreal x, qreal y) {
	if (x < 0 || x + PLAYER_WIDTH > MAIN_WINDOW_WIDTH) {
		return;
	}
	if (y < 0 || y + PLAYER_HEIGHT > MAIN_WINDOW_HEIGHT) {
		return;
	}
	setPos(x, y);
}

//int Player::decrementHealth() {
//	health->decrement();
//	return health->getHealth();
//}
//
//Health* Player::getHealth() {
//	return health;
//}

