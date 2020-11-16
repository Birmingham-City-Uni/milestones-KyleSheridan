#pragma once
#include "Background.h"
#include "UI.h"
#include "TileMap.h"

class TestScene {
public:
	TestScene(SDL_Renderer*);
	void init();
	void input();
	void update();
	void draw();
	void clear();

private:
	SDL_Renderer* renderer;

	SDL_Texture* t; //<--- move to player class

	Background* background;

	TileMap* tileMap;
};