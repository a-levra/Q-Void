#ifndef Q_VOID__BULLET_HPP_
# define Q_VOID__BULLET_HPP_

#include <QGraphicsRectItem>

class Bullet : public QGraphicsRectItem
	public:
		Bullet();
		Bullet(const Bullet &other);
		virtual ~Bullet();

		Bullet &operator=(const Bullet &other);
};

#endif