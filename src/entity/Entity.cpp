
#include <entity/Entity.h>
#include <graphics/Renderer.h>

Entity::Entity(const Vector2F &position, const std::string &name, const unsigned int layer)
    : m_center(position), m_name(name), m_layer(layer)
{
}

void Entity::setPosition(const Vector2F &position)
{
    m_center = position;
}

const Vector2F &Entity::getPosition() const
{
    return m_center;
}

unsigned int Entity::getLayer() const
{
    return m_layer;
}