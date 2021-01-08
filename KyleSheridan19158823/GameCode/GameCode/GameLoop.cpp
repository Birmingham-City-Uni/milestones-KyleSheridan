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

	fps = new FPS();
	fps->init();

	//create scenes
	title = new TitleScreen(this->renderer);
	test = new TestScene(this->renderer, fps);

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
	bool running;

	switch (currentScene)
	{
	case Scene::titleScreen:
		title->input(); //<-----make bool and sort inheritance 
		break;
	case Scene::testScene:
		running = test->input();
		break;
	default:
		break;
	}

	return running;
}

void GameLoop::update()
{
	fps->update();

	/*
	char buf[100];
	snprintf(buf, 100, "Game Test - (fps: %u)", fps->getFPS());
	SDL_SetWindowTitle(window, buf);
	*/
	test->update();
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

	fps->clear();
	if (fps) {
		delete fps;
		fps = nullptr;
	}
}