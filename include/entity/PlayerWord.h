#ifndef __PLAYER__H
#define __PLAYER__H

#include <entity/TextureEntity.h>

class PlayerWord : public TextureEntity
{
  private:
    Vector2I m_grid;

  public:
    PlayerWord(const Vector2F &position);

    ~PlayerWord() override = default;

    void update() override;
    void render(const Vector2F &ref) override;

    const Vector2I &getGrid() const;
};

#endif