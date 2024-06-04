#ifndef Q_VOID__ENEMY_HPP_
# define Q_VOID__ENEMY_HPP_

#include "Q-Void.hpp"


class Enemy : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	public:
		Enemy();
		virtual ~Enemy();
	public slots:
		void move();
};

#endif