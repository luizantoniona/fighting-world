#include "Entity.h"

BEGIN_NAMESPACE_COMPONENT

Entity::Entity(const sf::Vector2f& position)
{
    _sprite.setPosition(position);
}

void Entity::draw(sf::RenderWindow& window) const
{
    window.draw(_sprite);
}

sf::Vector2f Entity::position() const
{
    return _sprite.getPosition();
}

END_NAMESPACE_COMPONENT