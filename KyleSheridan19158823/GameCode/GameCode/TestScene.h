#pragma once
#include "Scene.h"
#include "Background.h"
#include "UI.h"
#include "TileMap.h"
#include "Player.h"

class TestScene : public Scene {
public:
	TestScene(SDL_Renderer* renderer) : Scene(renderer) {};
	void init();
	void update();
	void draw();
	void clear();

private:
	TileMap* tileMap;

	Player* player;
};