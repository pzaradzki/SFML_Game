#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	// Variables

	// Constructors
	Enemy(sf::Texture* texture);
	~Enemy();

	// Functions
	void update(float deltaTime) override;
};

