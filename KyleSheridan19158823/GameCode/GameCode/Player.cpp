#include "Player.h"

void Player::init()
{
	SDL_Surface* s = IMG_Load("assets/Player.png");
	texture = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);

	position = { 64, 64, 64, 64 };
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
	lastPos = { position.x, position.y };
	
	position.x += v.x;
	position.y += v.y;
}

void Player::draw()
{
	//SDL_Point center = { 32,32 };
	SDL_RenderCopyEx(this->renderer, this->texture, 0, &this->position, this->rotation, NULL, SDL_FLIP_NONE);
}

void Player::clear()
{
	SDL_DestroyTexture(texture);
}