
#include <entity/Entity.h>
#include <graphics/Renderer.h>

Entity::Entity(const Vector2 &position, const std::string &name, const unsigned int layer)
    : m_name(name), m_layer(layer), m_absolute(position)
{
}

void Entity::setPosition(const Vector2 &position)
{
    m_absolute = position;
}

const Vector2 &Entity::getPosition() const
{
    return m_absolute;
}

unsigned int Entity::getLayer() const
{
    return m_layer;
}