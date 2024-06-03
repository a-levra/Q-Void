
#include "Q-Void.hpp"
#include "Game.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Game * game = new Game();
	game->show();

    //the following make the window quit ..
    // delete(scene);
    // delete(rect);
    return a.exec();
}
