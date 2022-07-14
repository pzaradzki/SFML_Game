#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow* window) 
	: GameState(window), floor(sf::Vector2f(window->getSize().x, 61.f))
{
	backgroundTexture.loadFromFile("Images/background.png");
	enemyTexture.loadFromFile("Images/enemy2.png");
	playerTexture.loadFromFile("Images/ball.png");

	backgroundSprite.setTexture(backgroundTexture);
	floor.setPosition(0.f, window->getSize().y - floor.getSize().y);

	player = new Player(&playerTexture);
}

PlayingState::~PlayingState()
{
	delete player;
}

void PlayingState::handleInput(sf::Event* event)
{
	// Checks that any key is pressed
	if (event->type == sf::Event::KeyPressed)
		// If 'W' key is pressed and player is not in jumping phase
		if (event->key.code == sf::Keyboard::W && !player->inJump)
			// Start player to jump
			player->jump();
}

void PlayingState::update(float elapsedTime)
{
	// Updates player position while moving
	player->update(elapsedTime);

	// Updates player position while jumping
	player->updateJump(elapsedTime, floor);

	// Spawn new Enemy entity
	spawnEnemy(elapsedTime);

	// Updates positions of all Enemy entities
	for (auto& enemy : enemies)
	{
		enemy.update(elapsedTime);
	}

	// Checks if position of oldest Enemy entity is off the screen
	// If true remove it from list
	if (enemies.back().getPosition().y > 600)
	{
		enemies.pop_back();
	}
}

void PlayingState::draw()
{
	// Draw background sprite
	window->draw(backgroundSprite);
	// Draw player sprite
	window->draw(*player);
	// Drwa all Enemies sprites
	if (!enemies.empty())
	{
		for (auto& enemy : enemies)
		{
			window->draw(enemy);
		}
	}
}

void PlayingState::spawnEnemy(float elapsedTime)
{
	static float time = 0;
	time += elapsedTime;

	if (enemies.size() < 10 && time > 1)
	{
		enemies.push_front(Enemy(&enemyTexture));
		time = 0;
	}
}
