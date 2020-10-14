#pragma once

#include <SDL.h>
#include <iostream>

#include "Background.h"

class GameLoop {
public:
	//constructor
	GameLoop();
	//initialisation
	bool init();
	//process input
	bool input();
	//update
	void update();
	//draw
	void draw();
	//clear
	void clear();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event e;

	Background* background;

	bool keyDown[512];
};