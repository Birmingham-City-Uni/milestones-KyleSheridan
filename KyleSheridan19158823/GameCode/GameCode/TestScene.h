#pragma once
#include "Scene.h"
#include "Background.h"
#include "UI.h"
#include "TileMap.h"
#include "Player.h"
#include "BulletManager.h"
#include "Enemy.h"
#include "ScoreManager.h"
#include "GameOver.h"

class TestScene : public Scene {
public:
	TestScene(SDL_Renderer* renderer, FPS* fps) : Scene(renderer, fps) {};
	void init();
	bool input();
	void update();
	void draw();
	void clear();

private:
	TileMap* tileMap;
	Player* player;
	BulletManager* bm;
	Enemy* enemy;
	ScoreManager* scoreManager;

	GameOver* gameOver;
};