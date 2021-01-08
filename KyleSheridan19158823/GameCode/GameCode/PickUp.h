#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>

#include "Player.h"

class PickUp {
public:
	static enum class Type { DAMAGE = 0, HEALTH, FIRERATE, RANGE, HEAL }; //enum for type of pick-up so dont have to make multiple scripts

	PickUp(SDL_Renderer* renderer, Player* player, Type type, SDL_Rect position) : renderer(renderer), player(player), type(type), position(position) {}

	void init();
	void update();
	void draw();

	void pickUpEffect();

	bool getCollected() {
		return collected;
	}

	struct CircleCollider {
		int x, y, radius;

		bool isColliding(int x, int y) {
			int dist = abs(sqrt(pow((x - this->x), 2) + pow((y - this->y), 2)));

			if (dist < radius) {
				return true;
			}
			return false;
		}
	};

private:
	SDL_Renderer* renderer;
	Player* player;

	SDL_Texture* texture;

	Type type;

	bool collected = false;

	SDL_Rect position;

	CircleCollider collider;
};