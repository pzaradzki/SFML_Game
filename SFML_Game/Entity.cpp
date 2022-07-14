#include "Entity.h"

Entity::Entity(sf::Texture* texture)
{
	entityTexture = texture;
	setTexture(*entityTexture);
}

Entity::~Entity()
{
}
