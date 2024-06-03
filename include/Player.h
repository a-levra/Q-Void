#ifndef Q_VOID_PLAYER_H
#define Q_VOID_PLAYER_H

#include "Q-Void.hpp"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event) override;
	void TrySetPos(qreal x, qreal y);
//	int decrementHealth();
//	Health* getHealth();
	private:
//		Health* health;

};

#endif // Q_VOID_PLAYER_H
