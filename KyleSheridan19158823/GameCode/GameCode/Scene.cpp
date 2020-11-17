#include "Scene.h"

void Scene::init()
{

}

bool Scene::input()
{
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.scancode) {
				keyDown[e.key.keysym.scancode] = false;
			}
		}
	}

	return true;
}

void Scene::update()
{

}

void Scene::draw()
{

}

void Scene::clear()
{

}