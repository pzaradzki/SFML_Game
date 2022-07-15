#pragma once
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include <list>

class PlayingState : public GameState
{
public:
	// Variables
	sf::Sprite backgroundSprite;

	sf::Texture backgroundTexture;
	sf::Texture enemyTexture;
	sf::Texture playerTexture;

	sf::SoundBuffer collectSoundBuffer;
	sf::Sound collectSound;

	sf::Music backgroundMusic;

	sf::Font font;
	sf::Text score;
	int actualScore;

	Player* player;
	std::list<Enemy> enemies;

	sf::RectangleShape floor;

	// Constructors
	PlayingState(sf::RenderWindow* window);
	virtual ~PlayingState();

	// Functions
	void handleInput(sf::Event* event) override;
	void update(float elapsedTime) override;
	void draw() override;
	void spawnEnemy(float elapsedTime);

};

