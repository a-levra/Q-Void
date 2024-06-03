#ifndef Q_VOID_PLAYER_H
#define Q_VOID_PLAYER_H

#include "Q-Void.hpp"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100
//movements
#define UP 0x01
#define DOWN 0x02
#define LEFT 0x04
#define RIGHT 0x08


class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
	void TrySetPos(qreal x, qreal y);
//	int decrementHealth();
//	Health* getHealth();
public slots:
	void updateMovements();
private:
//		Health* health;
		char movements;

};

#endif // Q_VOID_PLAYER_H
