#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "Enemy.h"
#include "UI.h"

using namespace std;

#define SPAWN_WAIT 1000

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

		cout << waveNumber << endl;
	}

	vector<Enemy*> getEnemies() {
		return enemies;
	}

private:
	SDL_Renderer* renderer;
	Player* player;

	vector<SDL_Rect> spawnPoints;

	vector<Enemy*> enemies;

	int waveNumber;
	int enemiesRemaining;
	unsigned int lastSpawnTime = 0;

	Text* waveText;
	string waveString;
};