#include "TestScene.h"

void TestScene::init()
{
	//create Background
	background = new Background(this->renderer);
	background->init();

	//create Player
	player = new Player(this->renderer);
	player->init();

	//create ScoreManager
	scoreManager = new ScoreManager(this->renderer);
	scoreManager->init();
	
	//create BulletManager
	bm = new BulletManager(this->renderer, this->player, this->scoreManager);
	bm->init();

	//create TileMap
	tileMap = new TileMap(this->renderer, this->player, this->bm);
	tileMap->init();
}

bool TestScene::input()
{
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.scancode) {
				keyDown[e.key.keysym.scancode] = false;
			}
		}
	}

	player->input(keyDown);
	bm->input(keyDown);

	return true;
}

void TestScene::update()
{
	player->update();
	bm->update(tileMap->getWaveSpawner()->getEnemies());
	scoreManager->update();
	tileMap->update();

	if (player->getGameOver() && !gameOverOnce) {
		gameOver = new GameOver(renderer, scoreManager->getScore());
		gameOver->init();

		gameOverOnce = true;
	}
}

void TestScene::draw()
{
	background->draw();
	tileMap->draw();
	bm->draw();
	player->draw();
	scoreManager->draw();

	if (player->getGameOver()) {
		gameOver->draw();
	}
}

void TestScene::clear()
{
	background->clear();
	if (background) {
		delete background;
		background = nullptr;;
	}

	tileMap->clear();
	if (tileMap) {
		delete tileMap;
		tileMap = nullptr;
	}
	
	player->clear();
	if (player) {
		delete player;
		player = nullptr;
	}

	bm->clear();
	if (bm) {
		delete bm;
		bm = nullptr;
	}

	scoreManager->clear();
	if (scoreManager) {
		delete scoreManager;
		scoreManager = nullptr;
	}
}