#include "TestScene.h"

TestScene::TestScene(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void TestScene::init()
{
	//create Background
	background = new Background(this->renderer);
	background->init();

	//create TileMap
	tileMap = new TileMap(this->renderer);
	tileMap->init();
}

void TestScene::input()
{

}

void TestScene::update()
{

}

void TestScene::draw()
{
	background->draw();
	tileMap->draw();
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
}