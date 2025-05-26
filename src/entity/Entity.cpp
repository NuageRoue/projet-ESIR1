
#include <entity/Entity.h>
#include <graphics/Renderer.h>

Entity::Entity(const Vector2 &position, const Vector2 &size, const std::string &nameEntity)
    : m_position(position), m_size(size)
{
}

Entity::~Entity()
{
}

void Entity::setPosition(const Vector2 &position)
{
    m_position = position;
}

const Vector2 &Entity::getPosition()
{
    return m_position;
}
