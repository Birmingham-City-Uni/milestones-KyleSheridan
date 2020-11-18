#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player {
public:
	Player(SDL_Renderer* renderer) : renderer(renderer) {}

	void init();
	void input(bool* keyDown);
	void update();
	void draw();
	void clear();

	SDL_Rect getPosition() {
		return position;
	}

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect position;

	struct Velocity { int x, y; };

	Velocity v;

	int moveSpeed = 3;
	int rotation = 0;
};