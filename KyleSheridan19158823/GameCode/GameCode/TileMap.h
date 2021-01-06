#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Player.h"
#include "BulletManager.h"

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
	};

private:
	SDL_Renderer* renderer;
	SDL_Texture* mapTileset;

	Player* player;
	BulletManager* bm;

	const int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] = {
		{ 2,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  5,  6,  3,  3,  4  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 15, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  16 },
		{ 20, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  21 },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9  },
		{ 12, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 10, 11, 13, 13, 14 }
	};

	Tile map[MAP_SIZE_Y][MAP_SIZE_X];
};