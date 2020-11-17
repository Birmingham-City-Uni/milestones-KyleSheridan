#pragma once
#include "Background.h"
#include "UI.h"

class Scene {
public:
	Scene(SDL_Renderer* renderer) : renderer(renderer) {}

	virtual void init() = 0;
	bool input();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clear() = 0;

	bool getKeyDown(int keyCode) {
		if (keyCode > 0 && keyCode < 512) {
			return keyDown[keyCode];
		}

		return false;
	}

protected:
	SDL_Renderer* renderer;
	Background* background;
	SDL_Event e;

	bool keyDown[512];
};