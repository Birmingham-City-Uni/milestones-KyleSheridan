#pragma once

#include <iostream>

#include "TitleScreen.h"
#include "TestScene.h"
#include "FPS.h"

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

	bool getKeyDown(int keycode) {
		if (keycode > 0 && keycode < 512) {
			return keyDown[keycode];
		}
		return false;
	}

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event e;

	TitleScreen* title;
	TestScene* test;

	FPS* fps;

	enum class Scene { titleScreen, testScene };

	Scene currentScene;

	bool keyDown[512];
};