#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Enemy {
public:
	Enemy(SDL_Renderer* renderer) : renderer(renderer) {}
	void init();
	void update();
	void draw();
	void clear();

private:

public:
	SDL_Rect hitbox;

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	SDL_Rect position;

	float rotation;
};