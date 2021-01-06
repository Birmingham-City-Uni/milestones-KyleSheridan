#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>

#include "UI.h"
#include "Player.h"

#define ANIM_WAIT 300

class Enemy {
public:
	Enemy(SDL_Renderer* renderer) : renderer(renderer) {}
	void init();
	void update();
	void draw();
	void clear();

	void takeDamage(int amount) {
		health -= amount;
		healthBar->resetCounter();
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
	SDL_Texture* texture2;

	SDL_Rect position;

	HealthBar* healthBar;

	float rotation;

	int maxHealth = 50;

	int health;

	bool anim = true;
	unsigned int lastAnimFrame = 0;
};