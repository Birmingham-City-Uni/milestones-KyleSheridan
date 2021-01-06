#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "FPS.h"

class Player {
public:
	Player(SDL_Renderer* renderer, FPS* fps) : renderer(renderer), fps(fps) {}

	void init();
	void input(bool* keyDown);
	void update();
	void draw();
	void clear();

	SDL_Rect getPosition() {
		return position;
	}

	void wallCollide() {
		position.x = lastPos.x;
		position.y = lastPos.y;

		std::cout << "works" << std::endl;
	}

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect position;

	FPS* fps;

	struct Velocity { int x, y; };

	Velocity v;

	int moveSpeed = 3;
	int rotation = 0;

	SDL_Point lastPos;
};