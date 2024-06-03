#include "Score.hpp"

Score::Score(void) {
	this->score = 0;
	this->setPlainText(QString("Score: ") + QString::number(this->score));
	this->setDefaultTextColor(Qt::white);
	this->setFont(QFont("times", 16)); //todo change font ( disgusting )
}


Score::~Score(void) {}

void Score::increase() {
	this->score++;
	this->setPlainText(QString("Score: ") + QString::number(this->score));
}

