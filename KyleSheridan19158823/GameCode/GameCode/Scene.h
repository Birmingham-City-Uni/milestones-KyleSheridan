#pragma once
#include "Background.h"
#include "UI.h"
#include "FPS.h"

class Scene {
public:
	Scene(SDL_Renderer* renderer, FPS* fps) : renderer(renderer), fps(fps) {}

	virtual void init() = 0;
	virtual bool input() = 0;
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

	FPS* fps;

	bool keyDown[512];


	//will implement tilemap scrolling 
	int xOffset = 0;
	int yOffset = 0;

	int xThreshold;
	int yThreshold;
};