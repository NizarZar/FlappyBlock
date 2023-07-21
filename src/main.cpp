#include <iostream>
#include <Game.h>

int main() {

	Game game;

	while (game.gameRunning() && !game.getEndGame()) {
		game.update();
		game.render();
	}

	return 0;
}