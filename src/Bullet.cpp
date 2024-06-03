#include "Bullet.hpp"
#include "Game.hpp"

#define BULLET_WIDTH 10
#define BULLET_HALF_WIDTH 5
#define BULLET_HEIGHT 50

extern Game *game;

Bullet::Bullet(void) {
	setRect(0, 0, 10, 50);
	printf("Bullet::Bullet() x: %f y: %f\n", pos().x(), pos().y()); //debug
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);
}

Bullet::Bullet(qreal posX, qreal posY) {
	setRect(posX - BULLET_HALF_WIDTH, posY, BULLET_WIDTH, BULLET_HEIGHT);
	printf("Bullet::Bullet(posX, posY) x: %f y: %f\n", pos().x(), pos().y()); //debug
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);
}

Bullet::Bullet(const Bullet &other) { *this = other; }

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(const Bullet &other) {
	if (this != &other) {

	}
	return (*this);
}

//TODO this is shady ... why is it not just pos().y() < 0 ?
//TODO Can also optimize case when the player is at the top of the screen
void Bullet::move() {

	if (check_collision())
		return;

	setPos(0, y()-10);
	if (pos().y() + rect().height()  < -MAIN_WINDOW_HEIGHT) {
		printf("Bullet::move() DELETION x: %f y: %f\n", pos().x(), pos().y()); //debug
		scene()->removeItem(this);
		delete this;
	}
}


bool Bullet::check_collision() {
	QList<QGraphicsItem *> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; i++) {
		if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
			game->updateScore();
			scene()->removeItem(colliding_items[i]);
			scene()->removeItem(this);
			delete colliding_items[i];
			delete this;
			return (true);
		}
	}
	return (false);
}
