#include "Bullet.hpp"
#include "Prop.hpp"
#include "Game.hpp"

#define BULLET_WIDTH 10
#define BULLET_HALF_WIDTH 5
#define BULLET_HEIGHT 50

extern Game *game;

Bullet::Bullet(void) {
//	setRect(0, 0, 10, 50);
	QPixmap bullet(":/assets/laser-shot.png");
	bullet = bullet.scaled(BULLET_WIDTH, BULLET_HEIGHT);
	setPixmap(bullet);
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);
}

Bullet::Bullet(qreal posX, qreal posY) {
	QPixmap bullet(":/assets/laser-shot.png");
	bullet = bullet.scaled(BULLET_WIDTH, BULLET_HEIGHT);
	setPixmap(bullet);

	//play sound : pew pew
	QMediaPlayer *player = new QMediaPlayer();
	player->setMedia(QUrl("qrc:/sounds/laser-shot.mp3"));
	player->play();

	setPos(posX - BULLET_HALF_WIDTH, posY - BULLET_HEIGHT);
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

	setPos(pos().x(), pos().y() - 10);
	if (pos().y() + BULLET_HEIGHT  < -MAIN_WINDOW_HEIGHT) {
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
		if (typeid(*(colliding_items[i])) == typeid(Prop)) {
			scene()->removeItem(this);
			delete this;
			return (true);
		}
	}
	return (false);
}
