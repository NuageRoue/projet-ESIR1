#ifndef _HERO_H
#define _HERO_H

#include <entity/DrawEntity.h>
#include <utils/Vector2.h>

/// Classe représentant un personnage du jeu
class Hero : public DrawEntity
{

  public:
    /// Constructeur du héros
    Hero(const Vector2 &position, const Vector2 &size, const std::string &filename, const std::string &nameEntity);
    virtual ~Hero();

    void update() override;
    void render() override;
};

#endif //_HERO_H