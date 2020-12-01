#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>

class Enemy {
public:
	Enemy(SDL_Renderer* renderer) : renderer(renderer) {}
	void init();
	void update();
	void draw();
	void clear();

	void takeDamage(int amount) {
		health -= amount;
	}

	int getHealth() {
		return health;
	}

private:

public:
	SDL_Rect hitbox;

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	SDL_Rect position;

	float rotation;

	int maxHealth = 50;

	int health;


	//health bar
	SDL_Texture* healthBarTextureGrey;
	SDL_Texture* healthBarTextureRed;
	SDL_Rect healthBarRect;
	SDL_Rect healthBarAmountRect;
};