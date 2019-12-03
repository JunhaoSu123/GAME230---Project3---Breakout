#include "entity.h"

sf::Vector2f Entity::scroll(0, 0);

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0;
}

void Entity::Load(std::string filename)
{
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);
}

bool Entity::Update(sf::RenderWindow* window)
{
	this->move(this->velocity);
	return true;
}
void Entity::Collision(Entity* entity)
{
}

bool Entity::CheckCollision(Entity* entity)
{
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

float offset = 10;

bool Entity::CollisionSide(Entity* entity, COLLISION_DIRECTION side)
{
	float x = this->getPosition().x - offset;
	float y = this->getPosition().y + this->getGlobalBounds().height / 2;

	switch (side)
	{
	case COL_TOP:
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y - offset;
		break;
	case COL_BOTTOM:
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y + this->getGlobalBounds().height + offset;
		break;
	case COL_LEFT:
		break;
	case COL_RIGHT:
		x += this->getGlobalBounds().width + (offset * 2);
		break;
	}

	return entity->getGlobalBounds().contains(sf::Vector2f(x, y));
}

int Entity::GroupID()
{
	return this->groupId;
}

int Entity::Active()
{
	return this->active;
}

void Entity::Destroy()
{
	this->active = 0;
}

Entity::~Entity()
{
	delete this->texture;
}