
#include "Q-Void.hpp"
#include "Game.hpp"

Game *game;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	game = new Game();
	game->show();

    //the following make the window quit ..
    // delete(scene);
    // delete(rect);
    return a.exec();
}
