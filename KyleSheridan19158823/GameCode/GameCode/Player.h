#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player {
public:
	Player(SDL_Renderer* renderer) : renderer(renderer) {}

	void init();
	void input();
	void update(bool keyDown[512]);
	void draw();
	void clear();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect position;

	int moveSpeed = 3;
};