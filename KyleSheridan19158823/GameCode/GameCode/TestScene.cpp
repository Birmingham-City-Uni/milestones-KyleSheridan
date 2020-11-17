#include "TestScene.h"

void TestScene::init()
{
	//create Background
	background = new Background(this->renderer);
	background->init();

	//create TileMap
	tileMap = new TileMap(this->renderer);
	tileMap->init();

	
	//create Player
	player = new Player(this->renderer);
	player->init();
}

void TestScene::update()
{
	player->update(keyDown);
}

void TestScene::draw()
{
	background->draw();
	tileMap->draw();
	player->draw();
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
	/*
	player->clear();
	if (player) {
		delete player;
		player = nullptr;
	}*/
}