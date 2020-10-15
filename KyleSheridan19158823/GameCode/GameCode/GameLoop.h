#pragma once

#include <iostream>

#include "TitleScreen.h"

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

	TitleScreen* title;

	enum scene { titleScreen };

	scene currentScene;

	bool keyDown[512];
};