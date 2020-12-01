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
	SDL_Surface* healthBarSurface = IMG_Load("assets/HealthBarGrey.png");
	healthBarTextureGrey = SDL_CreateTextureFromSurface(renderer, healthBarSurface);
	SDL_FreeSurface(healthBarSurface);
	
	SDL_Surface* healthBarSurface2 = IMG_Load("assets/HealthBarRed.png");
	healthBarTextureRed = SDL_CreateTextureFromSurface(renderer, healthBarSurface2);
	SDL_FreeSurface(healthBarSurface2);

	this->healthBarRect = { this->position.x, this->position.y - 16, 64, 20 };
	this->healthBarAmountRect = { this->position.x, this->position.y - 16, 64, 20 };
}

void Enemy::update()
{
	//hitbox
	this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
	this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);

	//health bar
	this->healthBarRect.x = position.x;
	this->healthBarRect.y = position.y - 16;
	
	this->healthBarAmountRect.x = position.x;
	this->healthBarAmountRect.y = position.y - 16;

	this->healthBarAmountRect.w = static_cast <int> (floor(position.w * ((float)health / (float)maxHealth)));
}

void Enemy::draw()
{
	SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);
	SDL_RenderCopy(this->renderer, this->healthBarTextureGrey, NULL, &healthBarRect);
	SDL_RenderCopy(this->renderer, this->healthBarTextureRed, NULL, &healthBarAmountRect);
}

void Enemy::clear()
{
	SDL_DestroyTexture(this->texture);
}