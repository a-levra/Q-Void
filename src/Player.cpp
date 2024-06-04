#include "Player.h"
#include "Game.hpp"

extern Game *game;

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

	ammo = 10;

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
			if (ammo > 0) {
				ammo--;
				game->updateAmmoText(ammo);
				Bullet * bullet = new Bullet(x() + PLAYER_WIDTH / 2, y());
				scene()->addItem(bullet);
			}
			else {
				QMediaPlayer *player = new QMediaPlayer();
				player->setMedia(QUrl("qrc:/sounds/empty-ammo.mp3"));
				player->setVolume(10);
				player->play();
			}

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
	if (checkCollision()) {
		return;
	}
	setPos(x, y);
	this->px = x;
	this->py = y;
	game->updateDebugText(x, y);
}

void Player::updateMovements() {
	if (this->movements & LEFT) {
		TrySetPos(x()-0.5, y());
	}
	if (this->movements & RIGHT) {
		TrySetPos(x()+0.5, y());
	}
	if (this->movements & UP) {
		TrySetPos(x(), y()-0.5);
	}
	if (this->movements & DOWN) {
		TrySetPos(x(), y()+0.5);
	}
}

bool Player::checkCollision() {
	QList<QGraphicsItem *> colliding_items = collidingItems();
	for (int i = 0; i < colliding_items.size(); i++) {
		if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
			delete colliding_items[i];
			collision();
			return true;
		}
	}
	return false;
}

void Player::collision() {

	//red effect
	QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
	effect->setColor(Qt::red);
	setGraphicsEffect(effect);

	//blink effect
		setOpacity(0.7);
		QTimer::singleShot(1500, this, [=]() {
							   setOpacity(1); setGraphicsEffect(nullptr);
						   }
		);



//	}


//	health->decrement();
//	if (health->getHealth() == 0) {
//		scene()->removeItem(this);
//		delete this;
//	}a
}

void Player::getPos(qreal &x, qreal &y) {
	x = this->px;
	y = this->py;
}

void Player::setAmmo(int i) {
	ammo = i;
	game->updateAmmoText(ammo);
	QMediaPlayer *player = new QMediaPlayer();
	player->setMedia(QUrl("qrc:/sounds/gift.mp3"));
	player->setVolume(20);
	player->play();
}

//int Player::decrementHealth() {
//	health->decrement();
//	return health->getHealth();
//}
//
//Health* Player::getHealth() {
//	return health;
//}

