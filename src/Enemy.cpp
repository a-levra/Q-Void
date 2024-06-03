#include "Enemy.hpp"

Enemy::Enemy(void) {
	setRect(rand() % (MAIN_WINDOW_WIDTH - ENEMY_WIDTH), 0 , ENEMY_WIDTH, ENEMY_HEIGHT);
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(5);
}


Enemy::~Enemy(void) {}

void Enemy::move() {
	setPos(pos().x(), pos().y() + 1);
	if (pos().y() > MAIN_WINDOW_HEIGHT) {
		delete this;
	}
}