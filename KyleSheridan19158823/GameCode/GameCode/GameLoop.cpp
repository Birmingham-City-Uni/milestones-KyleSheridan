#include "GameLoop.h"

GameLoop::GameLoop()
{

}


bool GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialise SDL: " << SDL_GetError();
		return false;
	}

	if (TTF_Init() < 0) {
		std::cout << "Could not initialise TTF: " << TTF_GetError();
		return false;
	}

	//create window
	window = SDL_CreateWindow("Game Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 768, SDL_WINDOW_SHOWN);

	if (!window) {
		std::cout << "Could not create window: " << SDL_GetError();
		return false;
	}
	
	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	if (!renderer) {
		std::cout << "Could not create renderer: " << SDL_GetError();
	}

	//create scenes
	title = new TitleScreen(this->renderer);
	test = new TestScene(this->renderer);

	//start on titlescreen
	//-----------------
	//CHANGE THIS
	currentScene = Scene::testScene;
	//-----------------

	switch (currentScene)
	{
	case Scene::titleScreen:
		title->init();
		break;
	case Scene::testScene:
		test->init();
		break;
	default:
		break;
	}

	return true;
}

bool GameLoop::input()
{
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
	}

	switch (currentScene)
	{
	case Scene::titleScreen:
		title->input();
		break;
	case Scene::testScene:
		test->input();
		break;
	default:
		break;
	}

	return true;
}

void GameLoop::update()
{

}

void GameLoop::draw()
{
	SDL_RenderClear(renderer);

	switch (currentScene)
	{
	case Scene::titleScreen:
		title->draw();
		break;
	case Scene::testScene:
		test->draw();
		break;
	default:
		break;
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clear()
{
	switch (currentScene)
	{
	case Scene::titleScreen:
		title->clear();
		break;
	case Scene::testScene:
		test->clear();
		break;
	default:
		break;
	}
}