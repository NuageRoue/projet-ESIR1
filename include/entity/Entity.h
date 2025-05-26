#ifndef _ENTITY_H
#define _ENTITY_H

#include <utils/Vector2.h>

class Entity
{

  private:
    Vector2 m_position; // Position de l'entité dans le monde
    Vector2 m_size;     // Taille (width-height) de l'entiee

  public:
    /// Constructeur de l'entité.
    Entity(const Vector2 &position, const Vector2 &size, const std::string &nameEntity);

    virtual ~Entity();

    void setPosition(const Vector2 &position);
    const Vector2 &getPosition();

    /// Met à jour les caractéristiques de l'entité.
    virtual void update() = 0;

    /// Affichage de l'entité dans la fenêtre du jeu.
    virtual void render() = 0;
};

#endif //_ENTITY_H