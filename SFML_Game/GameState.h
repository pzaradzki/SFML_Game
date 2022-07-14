#pragma once

//Core
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <thread>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

//SFML
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>


class GameState
{
public:
	sf::RenderWindow* window;

	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	virtual void handleInput(sf::Event *event) = 0;
	virtual void update(float elapsedTime) = 0;
	virtual void draw() = 0;
};

