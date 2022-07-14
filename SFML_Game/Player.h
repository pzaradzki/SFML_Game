#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	// Variables
	bool inJump;
	float jumpSpeed;
	int health;

	// Constructors
	Player(sf::Texture* texture);
	~Player();

	// Functions
	void jump();
	void updateJump(float elapsedTime, sf::RectangleShape& collider);
	void update(float deltaTime) override;
	bool checkCollide(sf::FloatRect& object);
	bool checkCollide(sf::FloatRect&& object);
};

