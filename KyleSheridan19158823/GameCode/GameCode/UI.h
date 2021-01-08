#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cmath>

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

class HealthBar {
public:
	HealthBar(SDL_Renderer* renderer, int x, int y, int w = 64, int h = 20);
	void init();
	void update(int, int, float);
	void draw();
	void clear();

	int lerp(int a, int b, float t = 0.5);

	void resetCounter() {
		counter = 20;
	}

private:
	SDL_Renderer* renderer;
	
	SDL_Texture* healthBarTextureGrey;
	SDL_Texture* healthBarTextureRed;
	SDL_Texture* healthBarTextureWhite;

	SDL_Rect healthBarRectGrey;
	SDL_Rect healthBarRectRed;
	SDL_Rect healthBarRectWhite;

	int counter = 20;
};
