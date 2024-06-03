#include "Player.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPos(MAIN_WINDOW_WIDTH / 2 - PLAYER_WIDTH / 2, MAIN_WINDOW_HEIGHT - PLAYER_HEIGHT);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
	auto res = QPixmap(":/assets/spacecraft.png");
	if (res.isNull()) {
		printf("Player::Player() res is null\n");
	}
	setPixmap(res.scaled(PLAYER_WIDTH, PLAYER_HEIGHT));

	//automatic movement of the player
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(updateMovements()));
	timer->start(1);
	movements = 0;

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
			this->movements |= LEFT;
			break;
		case Qt::Key_D:
			this->movements |= RIGHT;
			break;
		case Qt::Key_W:
			this->movements |= UP;
			break;
		case Qt::Key_S:
			this->movements |= DOWN;
			break;
		case Qt::Key_Escape:
			exit(0);
			break;
		case Qt::Key_Space:
			printf("Player::keyPressEvent() x: %f y: %f\n", pos().x(), pos().y()); // debug
			Bullet * bullet = new Bullet(x() + PLAYER_WIDTH / 2, y());
			scene()->addItem(bullet);
	}
}

void Player::keyReleaseEvent(QKeyEvent *event) {
	if (event->isAutoRepeat()) {
		return;
	}
	switch (event->key()) {
		case Qt::Key_A:
			this->movements &= ~LEFT;
			break;
		case Qt::Key_D:
			this->movements &= ~RIGHT;
			break;
		case Qt::Key_W:
			this->movements &= ~UP;
			break;
		case Qt::Key_S:
			this->movements &= ~DOWN;
			break;
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

void Player::updateMovements() {
	if (this->movements & LEFT) { //this is not right, to check if the
		TrySetPos(x()-1, y());
	}
	if (this->movements & RIGHT) {
		TrySetPos(x()+1, y());
	}
	if (this->movements & UP) {
		TrySetPos(x(), y()-1);
	}
	if (this->movements & DOWN) {
		TrySetPos(x(), y()+1);
	}
}

//int Player::decrementHealth() {
//	health->decrement();
//	return health->getHealth();
//}
//
//Health* Player::getHealth() {
//	return health;
//}

