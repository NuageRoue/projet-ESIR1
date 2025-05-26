#ifndef _HERO_H
#define _HERO_H

#include <entity/DrawEntity.h>
#include <utils/Vector2.h>

/// Classe représentant un personnage du jeu
class Hero : public DrawEntity
{
  public:
    static const std::string nameHero;

  public:
    /// Constructeur du héros
    Hero(const Vector2 &position, const unsigned int layer, const std::vector<std::string> textureFiles);
    virtual ~Hero() = default;

    void update() override;
};

#endif //_HERO_H