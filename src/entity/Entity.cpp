
#include <entity/Entity.h>
#include <graphics/Renderer.h>

Entity::Entity(const Vector2 &position, const std::string &name, const unsigned int layer)
    : m_position(position), m_name(name), m_layer(layer)
{
}

void Entity::setPosition(const Vector2 &position)
{
    m_position = position;
}

const Vector2 &Entity::getPosition() const
{
    return m_position;
}
