#include "ScoreManager.h"

void ScoreManager::init() 
{
	scoreText = new Text(renderer, 32);

	score = 0;

	scoreString = "Score: 0";
}

void ScoreManager::update()
{
	scoreString = "Score: " + std::to_string(score);
}

void ScoreManager::draw()
{
	scoreText->draw(scoreString.c_str(), Text::alignX::RIGHT, Text::alignY::TOP);
}

void ScoreManager::clear()
{

}