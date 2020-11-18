#include "Enemy.h"

void Enemy::init()
{
	SDL_Surface* s = IMG_Load("assets/Alien1.png");
	texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	this->position = { 576, 256, 64, 64 };
	this->rotation = 0;

	this->hitbox = { 0, 0, 32, 20 };
}

void Enemy::update()
{
	this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
	this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);
}

void Enemy::draw()
{
	SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);
}

void Enemy::clear()
{
	SDL_DestroyTexture(this->texture);
}