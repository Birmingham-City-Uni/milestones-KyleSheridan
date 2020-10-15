#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Text {
public:
	static enum class alignX { LEFT, CENTRE, RIGHT };
	static enum class alignY { TOP, CENTRE, BOTTOM };

	Text(SDL_Renderer*, int);
	void draw(const char*, int, int);
	//overrides to make alignment easier
	void draw(const char*, alignX, int);
	void draw(const char*, int, alignY);
	void draw(const char*, alignX, alignY);

private:
	SDL_Renderer* renderer;

	TTF_Font* font;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect textRect;
	SDL_Color color = { 0, 0, 0 };
};
