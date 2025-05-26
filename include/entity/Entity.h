#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>
#include <utils/Vector2.h>
#include <utils/Vector2Grid.h>

class Entity
{

  private:
    Vector2 m_absolute; // center
    Vector2Grid m_grid;
    const std::string m_name;
    unsigned int m_layer;

  public:
    // constructeur et destructeur
    Entity(const Vector2Grid &position, const std::string &name, const unsigned int layer);
    virtual ~Entity() = default;

    // position
    void setPosition(const Vector2Grid &position);
    const Vector2Grid &getPosition() const;

    void setAbsolute(const Vector2 &position);
    const Vector2 &getAbsolute() const;

    // virtual update / render
    virtual void update() = 0;
    virtual void render(const Vector2 &ref) = 0;

    unsigned int getLayer() const;
};

#endif //_ENTITY_H