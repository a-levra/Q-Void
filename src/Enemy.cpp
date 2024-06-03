#include "Enemy.hpp"

Enemy::Enemy(void) {
	auto enemy = QPixmap(":/assets/blue_enemy.png");
	enemy = enemy.scaled(50, 50);
	setPixmap(enemy);

	//set random position on x axis
	int random_number = rand() % 700;
	setPos(random_number, 0);

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