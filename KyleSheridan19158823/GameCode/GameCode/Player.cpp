#include "Player.h"

void Player::init()
{
	SDL_Surface* s = IMG_Load("assets/Player.png");
	texture = SDL_CreateTextureFromSurface(this->renderer, s);
	SDL_FreeSurface(s);

	position = { 64, 64, 64, 64 };
}

void Player::input()
{

}

void Player::update(bool keyDown[512])
{
	if (keyDown[SDL_SCANCODE_RIGHT]) {
		position.x += moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_LEFT]) {
		position.x -= moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_UP]) {
		position.y -= moveSpeed;
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		position.y += moveSpeed;
	}
}

void Player::draw()
{
	SDL_RenderCopy(this->renderer, this->texture, 0, &this->position);
}

void Player::clear()
{
	SDL_DestroyTexture(texture);
}