#include "TileMap.h"

void TileMap::init() 
{
	SDL_Surface* s = IMG_Load("assets/Tilemap.png");
	this->mapTileset = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);

	spawner = new WaveSpawner(renderer, player);
	spawner->init();

	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			//calc size
			SDL_Rect srcRect = { (MAP_DATA[y][x] % 5) * 32, (MAP_DATA[y][x] / 5) * 32, 32, 32 };
			//calc pos
			SDL_Rect destRect = { x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE };

			bool collidable = true;

			if (MAP_DATA[y][x] == 0) {
				collidable = false;

				map[y][x] = Tile{ srcRect, destRect, collidable };
			}
			else if (MAP_DATA[y][x] == 1) {
				spawner->addSpawnPoint(destRect);

				collidable = false;

				map[y][x] = Tile{ srcRect, destRect, collidable };
			}
			else {
				map[y][x] = Tile{ srcRect, destRect, collidable };

				collidableTiles.push_back(&map[y][x]);
			}

		}
	}
}

void TileMap::update() 
{
	for (Tile*& tile : collidableTiles) {
		if (isColliding(player, tile->destRect)) {
			player->wallCollide();
		}

		if (bm->wallCollide(tile->destRect)) {
			if (tile->destroyable) {
				destroyCrate(tile);
			}
		}
	}

	spawner->update();

	if (spawner->getEndWave()) {
		createCrate();
		spawner->resetEndWave();
	}

	for (PickUp*& pickup : pickUps) {
		pickup->update();

		if (pickup->getCollected()) {
			delete pickup;
			pickUps.erase(pickUps.begin() + (&pickup - &*(pickUps.begin())));
			return;
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
	for (PickUp*& pickup : pickUps) {
		pickup->draw();
	}

	spawner->draw();

}

void TileMap::clear() {}

bool TileMap::isColliding(Player* player, SDL_Rect rect)
{
	SDL_Rect nullRect;
	return SDL_IntersectRect(&player->getHitbox(), &rect, &nullRect);
}

void TileMap::createCrate()
{
	int randX;
	int randY;

	do {
		randX = (rand() % (MAP_SIZE_X - 2)) + 1;
		randY = (rand() % (MAP_SIZE_Y - 2)) + 1;

	} while (isColliding(player, map[randY][randX].destRect));

	map[randY][randX].srcRect = { (8 % 5) * 32, (8 / 5) * 32, 32, 32 };
	map[randY][randX].collidable = true;
	map[randY][randX].destroyable = true;

	collidableTiles.push_back(&map[randY][randX]);
}

void TileMap::destroyCrate(Tile* tile)
{
	tile->srcRect = { 0, 0, 32, 32 };

	tile->collidable = false;
	tile->destroyable = false;

	spawnPickUp(tile->destRect);

	collidableTiles.erase(remove(collidableTiles.begin(), collidableTiles.end(), tile), collidableTiles.end());
}

//spawn pick up with random type and add it to vector
void TileMap::spawnPickUp(SDL_Rect& rect)
{
	SDL_Rect pickUpRect = { rect.x + (rect.w / 4), rect.y + (rect.h / 4), rect.w / 2, rect.h / 2 };

	int randType = rand() % 5;

	PickUp* pickup = new PickUp(renderer, player, static_cast<PickUp::Type>(randType), pickUpRect);
	pickup->init();

	pickUps.push_back(pickup);
}