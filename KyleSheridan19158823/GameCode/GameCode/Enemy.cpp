#include "Enemy.h"

void Enemy::init()
{
	SDL_Surface* s = IMG_Load("assets/Alien1.png");
	texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	s = IMG_Load("assets/Alien1_animation.png");
	texture2 = SDL_CreateTextureFromSurface(renderer, s);
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
	Vector direct = findDirection(position.x, position.y, player->getPosition().x, player->getPosition().y);

	SDL_Rect nullRect;

	if (!SDL_IntersectRect(&hitbox, &player->getHitbox(), &nullRect)) {
		if(direct.x == 0 && direct.y == 0){
			movespeed = 1.4142;
		}

		position.x += direct.x * movespeed;
		position.y += direct.y * movespeed;
	}

	movespeed = 2;

	//hitbox
	this->hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
	this->hitbox.y = position.y + 0.5 * (position.h - hitbox.h);

	rotation = findAngle();

	healthBar->update(position.x, position.y, (static_cast<float> (health) / maxHealth));

	if (anim && SDL_GetTicks() - lastAnimFrame > ANIM_WAIT) {
		anim = false;
		lastAnimFrame = SDL_GetTicks();
	}
	else if(!anim && SDL_GetTicks() - lastAnimFrame > ANIM_WAIT){
		anim = true;
		lastAnimFrame = SDL_GetTicks();
	}
}

void Enemy::draw()
{
	anim ? SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE) 
		: SDL_RenderCopyEx(this->renderer, this->texture2, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);

	healthBar->draw();
}

void Enemy::clear()
{
	SDL_DestroyTexture(this->texture);

	healthBar->clear();
}

Enemy::Vector Enemy::findDirection(int x1, int y1, int x2, int y2)
{
	float distX = x2 - x1;
	float distY = y2 - y1;

	float dist = sqrt((distX * distX) + (distY * distY));

	return Vector{ distX / dist, distY / dist };
}