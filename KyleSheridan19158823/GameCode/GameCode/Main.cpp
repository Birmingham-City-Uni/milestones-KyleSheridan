#include "GameLoop.h"

GameLoop* gameLoop;

int main(int argc, char* args[]) {
	//construct a gameloop object
	gameLoop = new GameLoop();
	if (!gameLoop->init()) {
		return 1;
	}
	
	while (gameLoop->input()) {
		gameLoop->update();
		gameLoop->draw();
	}

	gameLoop->clear();

	return 0;
}