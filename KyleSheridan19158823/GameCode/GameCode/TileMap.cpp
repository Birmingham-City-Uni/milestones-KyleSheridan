#include "TileMap.h"

void TileMap::init() 
{
	SDL_Surface* s = IMG_Load("../Assets/Tilemap.png");
	this->mapTileset = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);
}

void TileMap::input() {}

void TileMap::update() {}

void TileMap::draw()
{
	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			//calc size
			SDL_Rect srcRect = { (MAP_DATA[y][x] % 5) * 32, (MAP_DATA[y][x] / 5) * 32, 32, 32 };
			//calc pos
			SDL_Rect destRect = { x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE };
			SDL_RenderCopy(renderer, mapTileset, &srcRect, &destRect);
		}
	}
}

void TileMap::clear() {}