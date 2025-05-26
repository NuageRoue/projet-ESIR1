
#include <entity/Entity.h>
#include <graphics/Renderer.h>

Entity::Entity(const Vector2Grid &position, const std::string &name, const unsigned int layer)
    : m_grid(position), m_name(name), m_layer(layer), m_absolute(0,0)
{
}

void Entity::setPosition(const Vector2Grid &position)
{
    m_grid = position;
}

void Entity::setAbsolute(const Vector2 &position) const{
    m_absolute = position;
}

const Vector2Grid &Entity::getPosition() const
{
    return m_position;
}

const Vector2 &Entity::getAbsolute() const{
    return m_absolute;
}

unsigned int Entity::getLayer() const
{
    return m_layer;
}