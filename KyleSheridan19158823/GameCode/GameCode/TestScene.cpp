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


	//Move to Player class -----------
	SDL_Surface* s = IMG_Load("assets/Player.png");
	t = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);
	//------------------------------
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

	//Move to Player class -----------
	SDL_Rect rect = { 64, 64, 64, 64 };

	SDL_RenderCopy(this->renderer, this->t, 0, &rect);
	//------------------------------
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