#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "UI.h"

#define I_FRAMES 400

using namespace std;

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

	SDL_Rect getHitbox() {
		return hitbox;
	}

	int getDamage() {
		return damage;
	}

	int getFireRate() {
		return fireRate;
	}

	int getRange() {
		return range;
	}

	bool getGameOver() {
		return gameOver;
	}

	void wallCollide() {
		position.x = lastPos.x;
		position.y = lastPos.y;

		//hitbox
		this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
		this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);
	}

	void takeDamage(int amount) {
		if (SDL_GetTicks() - lastHit > I_FRAMES) {
			health -= amount;

			lastHit = SDL_GetTicks();
		}
	}

	void increaseDamage() {
		damage += 5;
	}

	void increaseHealth() {
		maxHealth += 20;
		takeDamage(-20);
	}

	void increaseFireRate() {
		fireRate += 1;
	}

	void increaseRange() {
		range += 50;
	}

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	HealthBar* healthBar;

	SDL_Rect position;
	SDL_Rect hitbox;

	struct Velocity { int x, y; };

	Velocity v;

	int lastHit = 0;

	int damage = 10;
	int fireRate = 3;
	int range = 300;

	int maxHealth;
	int health;

	int moveSpeed = 3;
	int rotation = 0;

	SDL_Point lastPos;

	bool gameOver = false;
};