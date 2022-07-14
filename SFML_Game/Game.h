#pragma once
#include "SplashscreenState.h"
#include "PlayingState.h"
#include "MainMenuState.h"

class Game
{
public:
	// Variables
	enum State { Uninitialized, Splashscreen, Menu, Playing, Exiting };

	// Current game state
	static State state;

private:
	// To avoid changing state during frame
	GameState* currentState;

	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;
	std::map<State, GameState*> gameStates;

	// Inizialization
	void initWindow();
	void initStates();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void setState(State s);
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};



