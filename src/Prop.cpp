#include <QGraphicsRotation>
#include "Prop.hpp"

Prop::Prop(void) {

	int propId = rand() % 7;
	QPixmap prop;
	switch (propId) {
		case 0:
			prop = QPixmap(":/assets/asteroid.png");
			break;
		case 1:
			prop = QPixmap(":/assets/asteroid2.png");
			break;
		case 2:
			prop = QPixmap(":/assets/asteroid2.png");
			break;
		case 3:
			prop = QPixmap(":/assets/asteroid.png");
			break;
		case 4:
			prop = QPixmap(":/assets/planet-magma.png");
			break;
		case 5:
			prop = QPixmap(":/assets/asteroid.png");
			break;
		case 6:
			prop = QPixmap(":/assets/gift.png");
			type = GIFT;
			break;

	}
	if (type == GIFT) {
		prop = prop.scaled(100, 100);
		speed = 0.1;
	}
	else {
		double scale = (rand() % 10 + 1) *0.1;
		prop = prop.scaled(50 * scale, 50 * scale);
		speed = (1 / scale + 1) * 0.1;
	}


	setPixmap(prop);
	setPos(rand() % MAIN_WINDOW_WIDTH, -MAIN_WINDOW_HEIGHT / 2);



	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(1);
}


Prop::~Prop(void) {}

void Prop::move() {
	setPos(x(), y() + speed);
	if (pos().y() > MAIN_WINDOW_HEIGHT) { //todo check if good formula
		scene()->removeItem(this);
		delete this;
	}
}

char Prop::getType() {
	return type;
}
