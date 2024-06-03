#ifndef Q_VOID_SRC_SCORE_HPP_
# define Q_VOID_SRC_SCORE_HPP_

#include "Q-Void.hpp"

class Score : public QGraphicsTextItem{
	public:
		Score();
		virtual ~Score();
		void increase();
		int getScore();
		void setScore(int newScore);
	private:
		QGraphicsTextItem * scoreText;
		int score;

};

#endif