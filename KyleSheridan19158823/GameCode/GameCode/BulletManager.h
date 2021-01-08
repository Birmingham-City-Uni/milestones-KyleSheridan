#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <math.h>
#include <algorithm>

#include "Player.h"
#include "Enemy.h"
#include "ScoreManager.h"

#define PI 3.14159265
#define POOL_SIZE 50

using namespace std;

class BulletManager {
public:
	BulletManager(SDL_Renderer* renderer, Player* player, ScoreManager* sm) : renderer(renderer), player(player), sm(sm) {}
	void init();
	void input(bool*);
	void update(vector<Enemy*>);
	void draw();
	void clear();

	struct Bullet {
	public:
		int x, y, rotation, distance;
		bool active;

		Bullet() {
			x = 0;
			y = 0;
			rotation = 0;
			distance = 0;
			active = false;
		}

		void setActive(int x, int y, int rot, int dist) {
			this->x = x;
			this->y = y;
			this->rotation = rot;
			this->distance = dist;

			this->active = true;
		}
	};

	bool isColliding(Bullet*, Enemy*);
	bool wallCollide(SDL_Rect);
	

private:
	SDL_Renderer* renderer;
	SDL_Texture* bulletTexture;
	vector<Bullet*> bullets;

	Player* player;
	ScoreManager* sm;

	int MAX_DIST = 300;
	int SHOOT_TIMER_MS = 333;
	const int BULLET_VELOCITY = 15;
	unsigned int lastShot = 0;
};