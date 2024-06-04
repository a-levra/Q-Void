#include "Game.hpp"
#include "Prop.hpp"

Game::Game(void) {
	createScene();
	player = new Player();

	enemySpwanerTimer = new QTimer();
	QObject::connect(enemySpwanerTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
	enemySpwanerTimer->start(2000);

	propSpwanerTimer = new QTimer();
	QObject::connect(propSpwanerTimer, SIGNAL(timeout()), this, SLOT(spawnProp()));
	propSpwanerTimer->start(1000);

	collisionCheckerTimer = new QTimer();
	QObject::connect(collisionCheckerTimer, SIGNAL(timeout()), this, SLOT(checkCollision()));
	collisionCheckerTimer->start(1);

	createScore();
	createDebugText();
	createAmmoText();
	playBackgroundMusic();
	loadBackground();
	createAndShowView();
}

void Game::loadBackground() {
	QBrush brush;
	brush.setTextureImage(QImage(":/assets/space_background.png"));
	scene->setBackgroundBrush(brush);
}

void Game::createAndShowView() const {
	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->show();
}

void Game::createScore() {
	score = new Score();
	score->setPos(score->x(), score->y() + 25);
	score->setScore(0);
}

void Game::createScene() {
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	setScene(scene);
	setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
}

void Game::playBackgroundMusic() const {
	QMediaPlayer *music = new QMediaPlayer();
	music->setMedia(QUrl("qrc:/sounds/pix-space-travel.mp3"));
	music->play();
}

Game::~Game(void) {}

//todo this is not consistent : sometimes we add items to the scene here, sometimes in the constructor
void Game::show() {
	scene->addItem(player);
	scene->addItem(score);
//	scene->addItem(player->getHealth());
}

void Game::setScene(QGraphicsScene *p_scene) {
	scene = p_scene;
}

void Game::setFixedSize(int width, int height) {
	scene->setSceneRect(0, 0, width, height);
}

void Game::spawnEnemy() {
	Enemy * enemy = new Enemy();
	scene->addItem(enemy);
}

void Game::spawnProp() {
	Prop * prop = new Prop();
	scene->addItem(prop);
}

void Game::updateScore() {
	score->increase();
}


void Game::createDebugText() {
	debugText = new QGraphicsTextItem();
	int fontId = QFontDatabase::addApplicationFont(":/fonts/SoccerScoreboard.otf");
	if (fontId == -1) {
		qDebug() << "Font not loaded";
	}
	else {
		qDebug() << "Font loaded";
	}
	debugText->setPlainText("Debug Text");
	debugText->setDefaultTextColor(Qt::white);
	debugText->setPos(20, MAIN_WINDOW_HEIGHT - 50);
	QFont font("Soccer Scoreboard");
	debugText->setFont(font);
	font.setPixelSize(50);
//	scene->addItem(debugText);


}

void Game::updateDebugText(qreal px, qreal py) {
	debugText->setPlainText("X: " + QString::number(px) + " Y: " + QString::number(py));
}

void Game::checkCollision() {
	QList<QGraphicsItem *> colliding_items = player->collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Prop)) {
			auto prop = dynamic_cast<Prop *>(colliding_items[i]);
			if (prop->getType() == GIFT) {
				player->setAmmo(10);
			}
			else
				player->collision();
			delete colliding_items[i];
			return;
		}
		else if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
			delete colliding_items[i];
			updateScore();
			player->collision();
			return;
		}

	}
}

void Game::createAmmoText() {
	ammoText = new QGraphicsTextItem*[10];
	for (int i = 0; i < 10; i++) {
		ammoText[i] = new QGraphicsTextItem();
		ammoText[i]->setPlainText("|");
		ammoText[i]->setDefaultTextColor(Qt::white);
		ammoText[i]->setFont(QFont("Soccer Scoreboard"));
		ammoText[i]->setScale(3);
		ammoText[i]->setPos(20 + i * 10, MAIN_WINDOW_HEIGHT - 100);
		scene->addItem(ammoText[i]);
	}
}

void Game::updateAmmoText(int ammo) {
	for (int i = 0; i < 10; i++) {
		if (i >= ammo)
			ammoText[i]->setOpacity(0.5);
		else
			ammoText[i]->setOpacity(1);
	}
}


