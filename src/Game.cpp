#include "Game.hpp"

Game::Game(void) {

	// Create the scene
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	setScene(scene);
	setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);

	player = new Player();

	timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
	timer->start(2000);

	score = new Score();
	score->setPos(score->x(), score->y() + 25);
	score->setScore(0);
	scene->addItem(score);

	playBackgroundMusic();

	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->show();
}

void Game::playBackgroundMusic() const {
	QMediaPlayer *music = new QMediaPlayer();
	music->setMedia(QUrl("qrc:/sounds/1.mp3"));
	if (!music->isAudioAvailable()) {
		qDebug() << "Media not found"; //todo handle properly
	}
	music->play();
}

Game::~Game(void) {}

void Game::show() {
	scene->addItem(player);
//	scene->addItem(score);
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

void Game::updateScore() {
	score->increase();
}


