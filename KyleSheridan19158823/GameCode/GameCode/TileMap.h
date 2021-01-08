#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <math.h>

#include "Player.h"
#include "BulletManager.h"
#include "WaveSpawner.h"
#include "PickUp.h"

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 12

#define MAP_TILE_SIZE 64

class TileMap {
public:
	TileMap(SDL_Renderer* renderer, Player* player, BulletManager* bm) : renderer(renderer), player(player), bm(bm) {}
	~TileMap() {}

	void init();
	void input();
	void update();
	void draw();
	void clear();

	bool isColliding(Player*, SDL_Rect);
	//bool isColliding(Bullet)
	
	struct Tile {
		SDL_Rect srcRect;
		SDL_Rect destRect;
		bool collidable;
		bool destroyable;
	};

	void createCrate();
	void destroyCrate(Tile*);
	
	void spawnPickUp(SDL_Rect&);

	WaveSpawner* getWaveSpawner() {
		return spawner;
	}


private:
	SDL_Renderer* renderer;
	SDL_Texture* mapTileset;

	WaveSpawner* spawner;

	Player* player;
	BulletManager* bm;

	vector<PickUp*> pickUps;

	const int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] = {
		{ 2,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  4  },
		{ 7,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 15, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  16 },
		{ 20, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  21 },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0,  9  },
		{ 12, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 14 }
	};

	Tile map[MAP_SIZE_Y][MAP_SIZE_X];
};