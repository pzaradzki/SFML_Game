#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow* window) 
	: GameState(window), floor(sf::Vector2f(window->getSize().x, 61.f))
{
	backgroundTexture.loadFromFile("Images/background.png");
	enemyTexture.loadFromFile("Images/banana.png");
	playerTexture.loadFromFile("Images/jarmo.png");
	font.loadFromFile("Fonts/Atarian/SF Atarian System.ttf");
	
	collectSoundBuffer.loadFromFile("Sounds/collect.wav");
	collectSound.setBuffer(collectSoundBuffer);

	backgroundMusic.openFromFile("Sounds/crime.wav");
	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(50.0f);

	actualScore = 0;
	score.setFont(font);
	score.setString("Score: " + std::to_string(actualScore));
	score.setPosition(20, 10);

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
	// Start music
	if (backgroundMusic.getStatus() != sf::SoundSource::Playing)
		backgroundMusic.play();

	// Updates player position while moving
	player->update(elapsedTime);

	// Updates player position while jumping
	player->updateJump(elapsedTime, floor);

	// Spawn new Enemy entity
	spawnEnemy(elapsedTime);

	
	if (!enemies.empty())
	{
		// Checks if position of oldest Enemy entity is off the screen
		// If true remove it from list
		if (enemies.back().getPosition().y > 600)
		{
			enemies.pop_back();
		}

		auto iter = enemies.begin();
		for (auto& enemy : enemies)
		{
			// Updates positions of all Enemy entities
			enemy.update(elapsedTime);

			if (player->checkCollide(enemy.getGlobalBounds()))
			{
				collectSound.play();
				actualScore += 1;
				if (iter != enemies.end())
					enemies.erase(iter);
					std::advance(iter, 1);
			}
			else
			{
				if (iter != enemies.end())
					std::advance(iter, 1);
			}
		}
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
	score.setString("Score: " + std::to_string(actualScore));
	window->draw(score);
}

void PlayingState::spawnEnemy(float elapsedTime)
{
	static float time = 0;
	time += elapsedTime;

	if (enemies.size() < 10 && time > 0.5)
	{
		enemies.push_front(Enemy(&enemyTexture));
		time = 0;
	}
}
