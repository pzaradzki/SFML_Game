#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture) : Entity(texture)
{
	int toNum = 800 - int(this->getGlobalBounds().width);
	float random = rand() % toNum;
	this->setPosition(random, 0.f);
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	this->move(0, 100.f * deltaTime);
}


