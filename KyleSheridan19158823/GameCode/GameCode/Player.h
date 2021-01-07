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

	SDL_Rect getHitbox() {
		return hitbox;
	}

	void wallCollide() {
		position.x = lastPos.x;
		position.y = lastPos.y;

		//hitbox
		this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
		this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);
	}

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect position;
	SDL_Rect hitbox;

	FPS* fps;

	struct Velocity { int x, y; };

	Velocity v;

	int moveSpeed = 3;
	int rotation = 0;

	SDL_Point lastPos;
};