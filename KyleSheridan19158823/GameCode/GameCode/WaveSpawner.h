#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

#include "Enemy.h"
#include "UI.h"

using namespace std;

#define SPAWN_WAIT 1000
#define POOL_SIZE 30

class WaveSpawner {
public:
	WaveSpawner(SDL_Renderer* renderer, Player* player) : renderer(renderer), player(player) {}

	void init();
	void update();
	void draw();
	void clear();

	void addSpawnPoint(SDL_Rect point) {
		spawnPoints.push_back(point);
	}

	void newWave() {
		waveNumber++;

		enemiesRemaining = (waveNumber * 3) + 9;

		enemyCount = enemiesRemaining;

		cout << waveNumber << endl;

		endWave = true;
	}

	bool getEndWave() {
		return endWave;
	}

	void resetEndWave() {
		endWave = false;
	}

	vector<Enemy*>& getEnemies() {
		return enemies;
	}

private:
	SDL_Renderer* renderer;
	Player* player;

	vector<SDL_Rect> spawnPoints;

	vector<Enemy*> enemies;

	int waveNumber;
	int enemiesRemaining;
	int enemyCount;
	unsigned int lastSpawnTime = 0;

	bool endWave = false;

	Text* waveText;
	string waveString;
};