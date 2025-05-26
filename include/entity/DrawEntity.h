#ifndef _DRAW_ENTITY_H
#define _DRAW_ENTITY_H

#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>

#include <entity/Entity.h>

#include <memory>

class DrawEntity : public Entity
{
  private:
    const std::vector<std::string> m_textureFiles;
    std::vector<std::shared_ptr<Texture>> m_textures; // Texture associé à l'entité

  public:
    // Constructeur et destructeur
    DrawEntity(const Vector2 &position, const std::string &name, const unsigned int layer,
               const std::vector<std::string> textureFiles);

    ~DrawEntity() override = default;

    // update et render
    void render() override;
    void update() override;
};

#endif