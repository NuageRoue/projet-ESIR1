#ifndef __PLAYER__H
#define __PLAYER__H

#include <entity/TextureEntity.h>

class Player : public TextureEntity
{
  public:
    Player(const Vector2F &position);

    ~Player() override = default;

    void update() override;
    void render(const Vector2F &ref) override;

    Vector2I getGridVector() const;
};

#endif