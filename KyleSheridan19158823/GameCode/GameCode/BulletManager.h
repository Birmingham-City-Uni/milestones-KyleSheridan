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

using namespace std;

class BulletManager {
public:
	BulletManager(SDL_Renderer* renderer, Player* player, ScoreManager* sm) : renderer(renderer), player(player), sm(sm) {}
	void init();
	void input(bool*);
	void update(Enemy*);
	void draw();
	void clear();

	struct Bullet {
		int x, y, rotation, distance;
	};

	bool isColliding(Bullet, Enemy*);

	

private:
	SDL_Renderer* renderer;
	SDL_Texture* bulletTexture;
	vector<Bullet> bullets;

	Player* player;
	ScoreManager* sm;

	const int SHOOT_TIMER_MS = 300;
	const int BULLET_VELOCITY = 15;
	unsigned int lastShot = 0;
};