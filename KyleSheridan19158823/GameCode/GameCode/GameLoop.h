#pragma once

#include <SDL.h>

class GameLoop {
public:
	//constructor
	GameLoop();
	//initialisation
	bool init();
	//process input
	void input(SDL_Event);
	//update
	void update();
	//draw
	void draw();
	//clear
	void clear();

private:

};