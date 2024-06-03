#ifndef Q_VOID__ENEMY_HPP_
# define Q_VOID__ENEMY_HPP_

#include "Q-Void.hpp"

#define ENEMY_WIDTH 50
#define ENEMY_HEIGHT 50

class Enemy : public QObject, public QGraphicsRectItem{
	Q_OBJECT
	public:
		Enemy();
		virtual ~Enemy();

	public slots:
		void move();
};

#endif