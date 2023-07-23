#include <iostream>
#include <Game.h>
#include <stdlib.h>
#include <time.h>

int main() {

	// seed randomization
	srand(time(NULL));

	Game game;

	while (game.gameRunning() && !game.getEndGame()) {
		game.update();
		game.render();
	}

	return 0;
}