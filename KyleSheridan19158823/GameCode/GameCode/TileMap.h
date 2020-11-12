#pragma once
#include <SDL.h>
#include <SDL_image.h>

#define MAP_SIZE_X 12
#define MAP_SIZE_Y 9

#define MAP_TILE_SIZE 64

class TileMap {
public:
	TileMap(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}
	~TileMap() {}
	void init();
	void input();
	void update();
	void draw();
	void clear();


private:
	SDL_Renderer* renderer;
	SDL_Texture* mapTileset;

	const int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] = {
		{ 2, 3, 5, 6, 3, 3, 3, 3, 5, 6, 3, 4 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
		{ 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14 }
	};
};