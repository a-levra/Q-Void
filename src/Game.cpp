#include "Game.hpp"
#include "Score.hpp"

Game::Game(void) {

	// Create the scene
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	setScene(scene);
	setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);

	// Create the player
	player = new Player();

	// Create the score
	score = new Score();

	// Create the enemy
	timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
	timer->start(2000);

	// Play background music
//	QMediaPlayer *music = new QMediaPlayer();
//	music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
//	music->play();

	//in order for the window to appear, we need to add the scene to a view  :
	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->show();
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


