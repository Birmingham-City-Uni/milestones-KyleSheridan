#pragma once
#include "Background.h"
#include "UI.h"

class TitleScreen {
public:
	TitleScreen(SDL_Renderer*);
	void init();
	void input();
	void update();
	void draw();
	void clear();

private:
	SDL_Renderer* renderer;

	Background* background;

	Text* title;
};