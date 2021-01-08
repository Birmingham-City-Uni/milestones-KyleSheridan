#include "UI.h"

Text::Text(SDL_Renderer* renderer, int size) {
	this->renderer = renderer;

	font = TTF_OpenFont("assets/Roboto-Black.ttf", size);
	if (font == nullptr) {
		std::cout << "No font loaded!" << std::endl;
	}
	
}

void Text::draw(const char* text, int x = 0, int y = 0)
{
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	textRect = { x, y, surface->w, surface->h };

	SDL_FreeSurface(surface);

	SDL_RenderCopy(this->renderer, this->texture, 0, &textRect);

	SDL_DestroyTexture(texture);
}

void Text::draw(const char* text, alignX x, int y = 0) 
{
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	textRect = { 0, y, surface->w, surface->h };

	//check x align
	switch (x)
	{
	case alignX::LEFT:
		textRect.x = 0;
		break;
	case alignX::CENTRE:
		textRect.x = 640 - (surface->w / 2);
		break;
	case alignX::RIGHT:
		textRect.x = 1280 - surface->w;
		break;
	default:
		break;
	}

	SDL_FreeSurface(surface);

	SDL_RenderCopy(this->renderer, this->texture, 0, &textRect);

	SDL_DestroyTexture(texture);
}

void Text::draw(const char* text, int x, alignY y)
{
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	textRect = { x, 0, surface->w, surface->h };

	//check x align
	switch (y)
	{
	case alignY::TOP:
		textRect.y = 0;
		break;
	case alignY::CENTRE:
		textRect.y = 384 - (surface->h / 2);
		break;
	case alignY::BOTTOM:
		textRect.y = 768 - surface->h;
		break;
	default:
		break;
	}

	SDL_FreeSurface(surface);

	SDL_RenderCopy(this->renderer, this->texture, 0, &textRect);

	SDL_DestroyTexture(texture);
}

void Text::draw(const char* text, alignX x, alignY y)
{
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	textRect = { 0, 0, surface->w, surface->h };

	//check x align
	switch (x)
	{
	case alignX::LEFT:
		textRect.x = 0;
		break;
	case alignX::CENTRE:
		textRect.x = 640 - (surface->w / 2);
		break;
	case alignX::RIGHT:
		textRect.x = 1280 - surface->w;
		break;
	default:
		break;
	}

	//check x align
	switch (y)
	{
	case alignY::TOP:
		textRect.y = 0;
		break;
	case alignY::CENTRE:
		textRect.y = 384 - (surface->h / 2);
		break;
	case alignY::BOTTOM:
		textRect.y = 768 - surface->h;
		break;
	default:
		break;
	}

	SDL_FreeSurface(surface);

	SDL_RenderCopy(this->renderer, this->texture, 0, &textRect);

	SDL_DestroyTexture(texture);
}

HealthBar::HealthBar(SDL_Renderer* renderer, int x, int y, int w, int h) : renderer(renderer) 
{
	healthBarRectGrey = { x, y, w, h };
}

void HealthBar::init() 
{
	//health bar
	SDL_Surface* healthBarSurface = IMG_Load("assets/HealthBarGrey.png");
	healthBarTextureGrey = SDL_CreateTextureFromSurface(renderer, healthBarSurface);
	SDL_FreeSurface(healthBarSurface);

	SDL_Surface* healthBarSurface2 = IMG_Load("assets/HealthBarWhite.png");
	healthBarTextureWhite = SDL_CreateTextureFromSurface(renderer, healthBarSurface2);
	SDL_FreeSurface(healthBarSurface2);

	SDL_Surface* healthBarSurface3 = IMG_Load("assets/HealthBarRed.png");
	healthBarTextureRed = SDL_CreateTextureFromSurface(renderer, healthBarSurface3);
	SDL_FreeSurface(healthBarSurface3);

	this->healthBarRectWhite = {
		healthBarRectGrey.x + 1,
		healthBarRectGrey.y + 2,
		healthBarRectGrey.w - 2,
		healthBarRectGrey.h - 4
	};

	this->healthBarRectRed = {
		healthBarRectGrey.x + 1,
		healthBarRectGrey.y + 2,
		healthBarRectGrey.w - 2,
		healthBarRectGrey.h - 4
	};
}

void HealthBar::update(int x, int y, float amount)
{
	this->healthBarRectGrey.x = x;
	this->healthBarRectGrey.y = y;

	this->healthBarRectWhite.x = x + 1;
	this->healthBarRectWhite.y = y + 2;

	this->healthBarRectRed.x = x + 1;
	this->healthBarRectRed.y = y + 2;

	this->healthBarRectRed.w = static_cast<int>(std::floor(this->healthBarRectGrey.w - 2) * amount);

	if (counter > 0) {
		counter--;
	}
	else {
		this->healthBarRectWhite.w = lerp(this->healthBarRectWhite.w, this->healthBarRectRed.w, 0.7);
	}

}

void HealthBar::draw()
{
	SDL_RenderCopyEx(this->renderer, this->healthBarTextureGrey, NULL, &healthBarRectGrey, NULL, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(this->renderer, this->healthBarTextureWhite, NULL, &healthBarRectWhite, NULL, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(this->renderer, this->healthBarTextureRed, NULL, &healthBarRectRed, NULL, NULL, SDL_FLIP_NONE);
}

void HealthBar::clear()
{

}

int HealthBar::lerp(int a, int b, float t)
{
	return a + t * (b - a);
}
