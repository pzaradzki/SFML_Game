#include "Game.h"

// Initialization
void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned int framerate_limit = 60;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	gameStates[Splashscreen] = new SplashscreenState(window);
	gameStates[Menu] = new MainMenuState(window);
	gameStates[Playing] = new PlayingState(window);
	this->setState(Splashscreen);
}

// Constructors / Destructors
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	auto itr = gameStates.begin();
	while (itr != gameStates.end()) 
	{
		delete itr->second;
		itr++;
	}
}

void Game::setState(State s)
{
	this->state = s;
}

// Functions
void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		currentState->handleInput(&sfEvent);
	}
	
}

void Game::update()
{
	this->currentState = gameStates[state];
	this->updateDt();
	this->updateSFMLEvents();
	currentState->update(dt);
}

void Game::render()
{
	this->window->clear();
	currentState->draw();
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

Game::State Game::state = Game::Splashscreen;