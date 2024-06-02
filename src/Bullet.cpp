#include "../include/Bullet.hpp"

Bullet::Bullet(void) {
	setRect(0,0,10,50);
}

Bullet::Bullet(const Bullet &other) { *this = other; }

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(const Bullet &other) {
	if (this != &other) {

	}
	return (*this);
}