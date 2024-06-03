#ifndef Q_VOID_SRC_SCORE_HPP_
# define Q_VOID_SRC_SCORE_HPP_

#include "Q-Void.hpp"

class Score : public QGraphicsTextItem{
	public:
		Score();
		virtual ~Score();
		void increase();
		int getScore();
	private:
		int score;

};

#endif