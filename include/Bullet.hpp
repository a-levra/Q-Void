#ifndef Q_VOID__BULLET_HPP_
# define Q_VOID__BULLET_HPP_

#include "Q-Void.hpp"

class Bullet : public QObject, public QGraphicsRectItem{
	Q_OBJECT
	public:
		Bullet();
		Bullet(qreal posX, qreal posY);
		Bullet(const Bullet &other);
		virtual ~Bullet();

		Bullet &operator=(const Bullet &other);
	public slots:
		void move();
		bool check_collision();
};

#endif