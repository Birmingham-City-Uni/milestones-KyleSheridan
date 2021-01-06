#include "BulletManager.h"

void BulletManager::init()
{
	SDL_Surface* surface = IMG_Load("assets/Bullet.png");
	bulletTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	bullets.reserve(POOL_SIZE);
	for (int i = 0; i < POOL_SIZE; i++) {
		bullets.push_back(new Bullet());
	}
}

void BulletManager::input(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_RIGHT]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			for (int i = 0; i < bullets.size(); i++) {
				if (!bullets[i]->active) {
					bullets[i]->setActive(player->getPosition().x + 22, player->getPosition().y + 22, 90, 0);
					lastShot = SDL_GetTicks();
					return;
				}
			}
		}
	}
	if (keyDown[SDL_SCANCODE_LEFT]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			for (int i = 0; i < bullets.size(); i++) {
				if (!bullets[i]->active) {
					bullets[i]->setActive(player->getPosition().x + 22, player->getPosition().y + 22, -90, 0);
					lastShot = SDL_GetTicks();
					return;
				}
			}	
		}
	}
	if (keyDown[SDL_SCANCODE_UP]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			for (int i = 0; i < bullets.size(); i++) {
				if (!bullets[i]->active) {
					bullets[i]->setActive(player->getPosition().x + 22, player->getPosition().y + 22, 0, 0);
					lastShot = SDL_GetTicks();
					return;
				}
			}
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		if (SDL_GetTicks() - lastShot > SHOOT_TIMER_MS) {
			for (int i = 0; i < bullets.size(); i++) {
				if (!bullets[i]->active) {
					bullets[i]->setActive(player->getPosition().x + 22, player->getPosition().y + 22, 180, 0);
					lastShot = SDL_GetTicks();
					return;
				}
			}
		}
	}
}

void BulletManager::update(Enemy* enemy) //Change parameter to array or vector
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->active) {
			if (bullets[i]->rotation == 90) {
				bullets[i]->x += BULLET_VELOCITY;
			}
			if (bullets[i]->rotation == -90) {
				bullets[i]->x -= BULLET_VELOCITY;
			}
			if (bullets[i]->rotation == 0) {
				bullets[i]->y -= BULLET_VELOCITY;
			}
			if (bullets[i]->rotation == 180) {
				bullets[i]->y += BULLET_VELOCITY;
			}
			bullets[i]->distance += BULLET_VELOCITY;

			if (isColliding(bullets[i], enemy)) {
				bullets[i]->active = false;
				sm->increaseScore(10);
				enemy->takeDamage(10);
			}

			if (bullets[i]->distance > MAX_DIST) {
				bullets[i]->active = false;
			}
		}
	}
}

void BulletManager::draw()
{
	SDL_Point center = { 10, 10 };
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->active) {
			SDL_Rect dest = { bullets[i]->x, bullets[i]->y, 20, 20 };
			SDL_RenderCopyEx(this->renderer, this->bulletTexture, 0, &dest, bullets[i]->rotation, &center, SDL_FLIP_NONE);
		}
	}
}

void BulletManager::clear() 
{
	SDL_DestroyTexture(bulletTexture);
}

bool BulletManager::isColliding(Bullet* bul, Enemy* enemy)
{
	SDL_Rect bulletRect = { bul->x, bul->y, 20, 20 };
	SDL_Rect nullRect;
	return SDL_IntersectRect(&bulletRect, &enemy->hitbox, &nullRect);
}

void BulletManager::wallCollide(SDL_Rect rect) 
{
	for (int i = 0; i < POOL_SIZE; i++) {
		if (bullets[i]->active) {
			SDL_Rect bulletRect = { bullets[i]->x, bullets[i]->y, 20, 20 };
			SDL_Rect nullRect;
			if (SDL_IntersectRect(&bulletRect, &rect, &nullRect)) {
				bullets[i]->active = false;
			}
		}
	}
}