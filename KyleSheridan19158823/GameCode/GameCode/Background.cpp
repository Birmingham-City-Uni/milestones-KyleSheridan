#include "Background.h"

Background::Background(SDL_Renderer* renderer) 
{
	this->renderer = renderer;
}

void Background::init() 
{
	SDL_Surface* surface = IMG_Load("assets/Space.jpg");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}

void Background::update()
{

}

void Background::draw()
{
	SDL_RenderCopy(this->renderer, this->texture, 0, NULL);
}

void Background::clear()
{
	SDL_DestroyTexture(texture);
}