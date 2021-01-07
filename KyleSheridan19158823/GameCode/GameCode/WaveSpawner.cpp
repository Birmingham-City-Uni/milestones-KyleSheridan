#include "WaveSpawner.h"

void WaveSpawner::init()
{
	waveText = new Text(renderer, 18);
	waveNumber = 0;
	waveString = "Wave: 0";

	enemiesRemaining = 0;
}

void WaveSpawner::update()
{
	if (enemies.size() == 0 && enemiesRemaining == 0) {
		newWave();
	}

	if (enemiesRemaining > 0 && SDL_GetTicks() - lastSpawnTime > SPAWN_WAIT) {
		int point = rand() % spawnPoints.size();

		enemiesRemaining--;
		Enemy* enemy = new Enemy(renderer, player);
		enemy->init(spawnPoints[point]);
		enemies.push_back(enemy);

		lastSpawnTime = SDL_GetTicks();
	}

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->update();
	}
}

void WaveSpawner::draw()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw();
	}
}