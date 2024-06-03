#include "Game.hpp"

Game::Game(void) {
	createScene();
	player = new Player();
	timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
	timer->start(2000);

	createScore();
	playBackgroundMusic();
	createAndShowView();
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
	music->setMedia(QUrl("qrc:/sounds/1.mp3"));
	music->play();
}

Game::~Game(void) {}

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

void Game::updateScore() {
	score->increase();
}


