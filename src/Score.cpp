#include "Score.hpp"

Score::Score(void) {
	int fontId = QFontDatabase::addApplicationFont(":/fonts/SoccerScoreboard.otf");
	if (fontId == -1) {
		qDebug() << "Font not loaded";
	}
	else {
		qDebug() << "Font loaded";
	}
	this->score = 0;
	this->setPlainText(QString("Score: ") + QString::number(this->score));
	this->setDefaultTextColor(Qt::white);
	QFont font("Soccer Scoreboard");
	font.setPixelSize(400);

	// Set the opacity
	QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
	opacityEffect->setOpacity(0.05); // Set the desired opacity (0.0 to 1.0)
	this->setGraphicsEffect(opacityEffect);

	this->setFont(font);

}

Score::~Score(void) {}

void Score::increase() {
	this->score++;
	this->setPlainText( QString::number(this->score));
}

int Score::getScore() {
	return this->score;
}

void Score::setScore(int newScore) {
	this->score = newScore;
	this->setPlainText( QString::number(this->score));
}
