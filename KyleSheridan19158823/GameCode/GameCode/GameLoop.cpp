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

	//start on titlescreen
	currentScene = titleScreen;

	switch (currentScene)
	{
	case titleScreen:
		title->init();
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
	case titleScreen:
		title->input();
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
	case titleScreen:
		title->draw();
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
	case titleScreen:
		title->clear();
		break;
	default:
		break;
	}
}