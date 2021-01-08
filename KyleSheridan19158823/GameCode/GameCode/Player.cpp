#include "Player.h"

void Player::init()
{
	SDL_Surface* s = IMG_Load("assets/Player.png");
	texture = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);

	position = { 64, 64, 64, 64 };

	hitbox = { 0,0,32,32 };

	maxHealth = 100;
	health = maxHealth;

	//health bar
	healthBar = new HealthBar(renderer, 10, 700, 300, 64);
	healthBar->init();
}

void Player::input(bool* keyDown)
{
	v = { 0,0 };

	if (keyDown[SDL_SCANCODE_D]) {
		v.x = moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_A]) {
		v.x = -moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_W]) {
		v.y = -moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_S]) {
		v.y = moveSpeed;
	}

	if (keyDown[SDL_SCANCODE_RIGHT]) {
		rotation = 90;
	}
	if (keyDown[SDL_SCANCODE_LEFT]) {
		rotation = -90;
	}
	if (keyDown[SDL_SCANCODE_UP]) {
		rotation = 0;
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		rotation = 180;
	}
}

void Player::update()
{
	if (health > maxHealth) {
		health = maxHealth;
	}

	lastPos = { position.x, position.y };
	
	position.x += v.x;
	position.y += v.y;

	//hitbox
	hitbox.x = position.x + 0.5 * (position.w - hitbox.w);
	hitbox.y = position.y + 0.5 * (position.h - hitbox.h);

	healthBar->update(10, 700, (static_cast<float> (health) / maxHealth));
}

void Player::draw()
{
	SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);

	healthBar->draw();
}

void Player::clear()
{
	SDL_DestroyTexture(texture);
}