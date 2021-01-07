#include "WaveSpawner.h"

void WaveSpawner::init()
{
	waveText = new Text(renderer, 32);
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
		Enemy* enemy = new Enemy(renderer, player, waveNumber);
		enemy->init(spawnPoints[point]);
		enemies.push_back(enemy);

		lastSpawnTime = SDL_GetTicks();
	}

	waveString = "Wave: " + std::to_string(waveNumber);

	for (Enemy*& enemy : enemies) {
		enemy->update();

		if (enemy->getHealth() <= 0) {
			enemy->clear();
			delete enemy;
			enemies.erase(enemies.begin() + (&enemy - &*(enemies.begin())));
			return;
		}
	}
}

void WaveSpawner::draw()
{
	for (Enemy*& enemy : enemies) {
		enemy->draw();
	}

	waveText->draw(waveString.c_str(), Text::alignX::LEFT, Text::alignY::TOP);
}