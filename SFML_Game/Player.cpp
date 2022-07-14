#include "Player.h"

Player::Player(sf::Texture* texture) : Entity(texture)
{
	jumpSpeed = 0;
	inJump = true;
	health = 100;
	setPosition(800 / 2, 600 - getGlobalBounds().height - 200);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (getPosition().x >= 0)
			move(-400.f * deltaTime, 0);
		if (getPosition().x < 0)
			setPosition(0, getPosition().y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (getPosition().x <= 800 - getGlobalBounds().width)
			move(400.f * deltaTime, 0);
		if (getPosition().x > 800 - getGlobalBounds().width)
			setPosition(800 - getGlobalBounds().width, getPosition().y);
	}
}

bool Player::checkCollide(sf::FloatRect& object)
{
	return getGlobalBounds().intersects(object);
}

bool Player::checkCollide(sf::FloatRect&& object)
{
	return getGlobalBounds().intersects(object);
}

void Player::jump()
{
	inJump = true;
	jumpSpeed = -9.f;
}

void Player::updateJump(float elapsedTime, sf::RectangleShape& collider)
{
	if (inJump)
	{
		move(0.f, jumpSpeed * 100.f * elapsedTime);
		jumpSpeed += 25.f * elapsedTime;

		while (collider.getGlobalBounds().intersects(getGlobalBounds())
			|| getPosition().y > 600)
		{
			move(0, -1);
			inJump = false;
			jumpSpeed = 0;
		}

	}
}
