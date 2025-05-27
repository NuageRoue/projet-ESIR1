#ifndef __TEXTURE_ENTITY_H
#define __TEXTURE_ENTITY_H

#include <graphics/texture/Texture.h>

#include <entity/Entity.h>

#include <memory>

class TextureEntity : public Entity
{
  private:
    Texture *m_texture;

  public:
    // Constructeur et destructeur
    TextureEntity(const Vector2F &position, const std::string &name, const unsigned int layer,
                  const std::string &textureFile);

    ~TextureEntity() override = default;

    // update et render
    void render(const Vector2F &ref) override;
    void update() override;

    void changeTexture(Texture *texture);
};

#endif