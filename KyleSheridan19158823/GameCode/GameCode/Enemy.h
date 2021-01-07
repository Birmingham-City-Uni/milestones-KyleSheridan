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
	Enemy(SDL_Renderer* renderer, Player* player, int level) : renderer(renderer), player(player) 
	{
		maxHealth = (level * 10) + 40;
		damage = (level * 3 + 6);
	}
	void init(SDL_Rect);
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

	struct Vector { float x, y; };

	Vector findDirection(int, int, int, int);

	int findAngle()
	{
		return static_cast<int>(std::atan2f(player->getPosition().y - position.y, player->getPosition().x - position.x) * 180.0f / float(M_PI)) + 90.0f;
	}

private:

public:
	SDL_Rect hitbox;

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Texture* texture2;

	Player* player;

	SDL_Rect position;

	HealthBar* healthBar;

	float rotation;

	float movespeed = 2;

	int maxHealth;
	int damage;

	int health;

	bool anim = true;
	unsigned int lastAnimFrame = 0;
};