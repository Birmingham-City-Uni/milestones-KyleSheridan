#include "BulletManager.h"

void BulletManager::init()
{
	SDL_Surface* surface = IMG_Load("assets/Bullet.png");
	bulletTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void BulletManager::input(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_RIGHT]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			bullets.push_back(Bullet{ player->getPosition().x + 22, player->getPosition().y + 22, 90, 0 });
			lastShot = SDL_GetTicks();
		}
	}
	if (keyDown[SDL_SCANCODE_LEFT]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			bullets.push_back(Bullet{ player->getPosition().x + 22, player->getPosition().y + 22, -90, 0 });
			lastShot = SDL_GetTicks();
		}
	}
	if (keyDown[SDL_SCANCODE_UP]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			bullets.push_back(Bullet{ player->getPosition().x + 22, player->getPosition().y + 22, 0, 0 });
			lastShot = SDL_GetTicks();
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			bullets.push_back(Bullet{ player->getPosition().x + 22, player->getPosition().y + 22, 180, 0 });
			lastShot = SDL_GetTicks();
		}
	}
}

void BulletManager::update()
{
	for (auto& b : bullets) {
		if (b.rotation == 90) {
			b.x += BULLET_VELOCITY;
		}
		if (b.rotation == -90) {
			b.x -= BULLET_VELOCITY;
		}
		if (b.rotation == 0) {
			b.y -= BULLET_VELOCITY;
		}
		if (b.rotation == 180) {
			b.y += BULLET_VELOCITY;
		}
		b.distance += BULLET_VELOCITY;
	}

	auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.distance > 500; });
	bullets.erase(remove, bullets.end());
}

void BulletManager::draw()
{
	SDL_Point center = { 10, 10 };
	for (auto& b : bullets) {
		SDL_Rect dest = { b.x, b.y, 20, 20 };
		SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
	}
}

void BulletManager::clear() 
{
	SDL_DestroyTexture(bulletTexture);
}