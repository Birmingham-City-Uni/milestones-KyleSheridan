#pragma once

#include <SDL.h>
#include <string>
#include "Background.h"
#include "UI.h"

using namespace std;

class GameOver {
public:
	GameOver(SDL_Renderer* renderer, int score) : renderer(renderer), score(score) {}
	void init();
	void draw();

private:
	SDL_Renderer* renderer;
	
	Background* background;

	int score;

	Text* gameOver;
	Text* scoreText;
};