#ifndef Q_VOID_SRC_PROP_HPP_
# define Q_VOID_SRC_PROP_HPP_

#include "Q-Void.hpp"

//types
#define GIFT 0x01

class Prop : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	public:
		Prop();
		virtual ~Prop();
		char getType();
	public slots:
		void move();
	private:
		double speed;
		char type;
};

#endif