#include "GameLoop.h"

GameLoop::GameLoop()
{

}


bool GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialise: " << SDL_GetError();
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

	//create Background
	background = new Background(this->renderer);
	background->init();

	return true;
}

bool GameLoop::input()
{
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}

void GameLoop::update()
{

}

void GameLoop::draw()
{
	SDL_RenderClear(renderer);

	//process drawing for classes
	background->draw();

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clear()
{
	background->clear();
	if (background) {
		delete background;
		background = nullptr;;
	}
}