#ifndef Q_VOID__GAME_HPP_
# define Q_VOID__GAME_HPP_

#include "Q-Void.hpp"

class Game : public QObject{
	Q_OBJECT

	public:
		Game();
		virtual ~Game();
		void show();
		void updateScore();
	public slots:
		void spawnEnemy();
		void spawnProp();
	private:
		QGraphicsScene * scene;
		Player * player;
		QTimer * enemySpwanerTimer;
		QTimer * propSpwanerTimer;
		QList<Enemy *> enemies;
		QList<Bullet *> bullets;
		Score* score;
//		void gameOver();
//		void restartGame();
//		void clearScene();
		void setScene(QGraphicsScene *p_scene);
		void setFixedSize(int width, int height);
		void playBackgroundMusic() const;
		void createScene();
		void createScore();
		void createAndShowView() const;
		void loadBackground();
};

#endif