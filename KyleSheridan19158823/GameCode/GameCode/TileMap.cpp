#include "TileMap.h"

void TileMap::init() 
{
	SDL_Surface* s = IMG_Load("assets/Tilemap.png");
	this->mapTileset = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);

	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			//calc size
			SDL_Rect srcRect = { (MAP_DATA[y][x] % 5) * 32, (MAP_DATA[y][x] / 5) * 32, 32, 32 };
			//calc pos
			SDL_Rect destRect = { x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE };
			//SDL_RenderCopy(renderer, mapTileset, &srcRect, &destRect);

			bool collidable = true;

			if (MAP_DATA[y][x] == 0 || MAP_DATA[y][x] == 1)
				collidable = false;

			map[y][x] = Tile{ srcRect, destRect, collidable };
		}
	}
}

void TileMap::input() {}

void TileMap::update() 
{
	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++) {
			if (map[y][x].collidable) {
				if (isColliding(player, map[y][x].destRect)) {
					player->wallCollide();
				}

				bm->wallCollide(map[y][x].destRect);
			}
		}
	}
}

void TileMap::draw()
{
	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++) {
			SDL_RenderCopy(renderer, mapTileset, &map[y][x].srcRect, &map[y][x].destRect);
		}
	}
}

void TileMap::clear() {}

bool TileMap::isColliding(Player* player, SDL_Rect rect)
{
	SDL_Rect nullRect;
	return SDL_IntersectRect(&player->getPosition(), &rect, &nullRect);
}