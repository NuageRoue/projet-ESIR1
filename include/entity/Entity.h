#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>
#include <utils/Vector2.h>


class Entity
{

  private:
    Vector2 m_absolute; // center
    const std::string m_name;
    unsigned int m_layer;

  public:
    // constructeur et destructeur
    Entity(const Vector2 &position, const std::string &name, const unsigned int layer);
    virtual ~Entity() = default;

    // position
    void setPosition(const Vector2 &position);
    const Vector2 &getPosition() const;


    // virtual update / render
    virtual void update() = 0;
    virtual void render(const Vector2 &ref) = 0;

    unsigned int getLayer() const;
};

#endif //_ENTITY_H