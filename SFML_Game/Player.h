#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	// Variables
	bool inJump;
	float jumpSpeed;

	// Constructors
	Player(sf::Texture* texture);
	~Player();

	// Functions
	void jump();
	void updateJump(float elapsedTime, sf::RectangleShape collider);
	void update(float deltaTime) override;
};

