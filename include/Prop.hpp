#ifndef Q_VOID_SRC_PROP_HPP_
# define Q_VOID_SRC_PROP_HPP_

#include "Q-Void.hpp"

class Prop : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	public:
		Prop();
		virtual ~Prop();
	public slots:
		void move();
	private:
		double speed;
};

#endif