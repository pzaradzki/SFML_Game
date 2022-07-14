#pragma once
#include "SFML/Graphics.hpp"
class Entity : public sf::Sprite
{
private:
	sf::Texture* entityTexture;

public:
	Entity(sf::Texture* texture);
	virtual ~Entity();
	virtual void update(float deltaTime) = 0;
};

