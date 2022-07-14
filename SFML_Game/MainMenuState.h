#pragma once

#include "GameState.h"
#include "Game.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(sf::RenderWindow* window);
	virtual ~MainMenuState();

	void handleInput(sf::Event* event) override;
	void update(float elapsedTime) override;
	void draw() override;

	bool buttonClicked();

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture btnStartTexture;
	sf::Sprite btnStartSprite;

	sf::Texture titleTexture;
	sf::Sprite titleSprite;
};

