#include "Enemy.h"

void Enemy::init()
{
	SDL_Surface* s = IMG_Load("assets/Alien1.png");
	texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	this->position = { 576, 256, 64, 64 };
	this->rotation = 0;

	this->hitbox = { 0, 0, 32, 20 };

	this->health = maxHealth;

	//health bar
	healthBar = new HealthBar(renderer, position.x, position.y - 10);
	healthBar->init();
}

void Enemy::update()
{
	//hitbox
	this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
	this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);

	healthBar->update(position.x, position.y, (static_cast<float> (health) / maxHealth));
}

void Enemy::draw()
{
	SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);

	healthBar->draw();
}

void Enemy::clear()
{
	SDL_DestroyTexture(this->texture);

	healthBar->clear();
}