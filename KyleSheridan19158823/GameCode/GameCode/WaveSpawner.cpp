#include "WaveSpawner.h"

void WaveSpawner::init()
{
	waveText = new Text(renderer, 32);
	waveNumber = 0;
	waveString = "Wave: 0";

	enemiesRemaining = 0;

	enemies.reserve(POOL_SIZE);
	for (int i = 0; i < POOL_SIZE; i++) {
		Enemy* enemy = new Enemy(renderer, player);
		enemy->init();

		enemies.push_back(enemy);
	}
}

void WaveSpawner::update()
{
	if (enemyCount == 0 && enemiesRemaining == 0) {
		newWave();
	}

	if (enemiesRemaining > 0 && SDL_GetTicks() - lastSpawnTime > SPAWN_WAIT) {
		int point = rand() % spawnPoints.size();

		enemiesRemaining--;

		for (Enemy*& enemy : enemies) {
			if (!enemy->getActive()) {
				enemy->setAvtive(spawnPoints[point], (rand() % waveNumber) + 1);

				lastSpawnTime = SDL_GetTicks();
				
				return;
			}
		}

		
	}

	waveString = "Wave: " + std::to_string(waveNumber);

	for (Enemy*& enemy : enemies) {
		if (enemy->getActive()) {
			enemy->update();

			if (enemy->getHealth() <= 0) {
				enemy->setUnactive();

				enemyCount--;
			}
		}
	}
}

void WaveSpawner::draw()
{
	for (Enemy*& enemy : enemies) {
		if (enemy->getActive()) {
			enemy->draw();
		}
	}

	waveText->draw(waveString.c_str(), Text::alignX::LEFT, Text::alignY::TOP);
}