#include "ScoreManager.h"

void ScoreManager::init() 
{
	scoreText = new Text(renderer, 18);

	score = 0;

	scoreString = "Score: 0";
}

void ScoreManager::update()
{
	scoreString = "Score: " + std::to_string(score);
}

void ScoreManager::draw()
{
	scoreText->draw(scoreString.c_str(), Text::alignX::LEFT, Text::alignY::TOP);
}

void ScoreManager::clear()
{

}