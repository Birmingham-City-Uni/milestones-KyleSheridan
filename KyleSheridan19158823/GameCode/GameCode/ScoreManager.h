#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

#include "UI.h"

class ScoreManager {
public:
	
	
	ScoreManager(SDL_Renderer* renderer) : renderer(renderer) {}
	void init();
	void update();
	void draw();
	void clear();

	void increaseScore(int amount) {
		score += amount;
	}
	
	int getScore() {
		return score;
	}

private:
	SDL_Renderer* renderer;
	Text* scoreText;

	int score;

	std::string scoreString;
};