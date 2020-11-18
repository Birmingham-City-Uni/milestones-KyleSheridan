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

void BulletManager::update(Enemy* enemy) //Change parameter to array or vector
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].rotation == 90) {
			bullets[i].x += BULLET_VELOCITY;
		}
		if (bullets[i].rotation == -90) {
			bullets[i].x -= BULLET_VELOCITY;
		}
		if (bullets[i].rotation == 0) {
			bullets[i].y -= BULLET_VELOCITY;
		}
		if (bullets[i].rotation == 180) {
			bullets[i].y += BULLET_VELOCITY;
		}
		bullets[i].distance += BULLET_VELOCITY;

		if (isColliding(bullets[i], enemy)) {
			bullets.erase(bullets.begin() + i);
			sm->increaseScore(10);
		}
	}

	auto remove = remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return b.distance > 500; });
	bullets.erase(remove, bullets.end());
}

void BulletManager::draw()
{
	SDL_Point center = { 10, 10 };
	for (auto& b : bullets) {
		SDL_Rect dest = { b.x, b.y, 20, 20 };
		SDL_RenderCopyEx(this->renderer, this->bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
	}
}

void BulletManager::clear() 
{
	SDL_DestroyTexture(bulletTexture);
}

bool BulletManager::isColliding(Bullet bul, Enemy* enemy)
{
	SDL_Rect bulletRect = { bul.x, bul.y, 20, 20 };
	SDL_Rect nullRect;
	return SDL_IntersectRect(&bulletRect, &enemy->hitbox, &nullRect);
}