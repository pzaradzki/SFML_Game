#pragma once

#include "GameState.h"
#include "Game.h"

class SplashscreenState : public GameState
{
public:
	
	SplashscreenState(sf::RenderWindow* window);
	virtual ~SplashscreenState();

	void handleInput(sf::Event* event) override;
	void update(float elapsedTime) override;
	void draw() override;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture titleTexture;
	sf::Sprite titleSprite;
};

