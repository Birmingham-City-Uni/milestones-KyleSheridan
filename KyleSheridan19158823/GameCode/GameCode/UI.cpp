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