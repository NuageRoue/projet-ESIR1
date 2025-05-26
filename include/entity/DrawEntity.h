#ifndef _DRAW_ENTITY_H
#define _DRAW_ENTITY_H

#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>

#include <entity/Entity.h>

#include <memory>

class DrawEntity : public Entity
{
  private:
    std::string m_nameEntity;           // Nom de l'entité dans la liste
    std::shared_ptr<Texture> m_texture; // Texture associé à l'entité

  public:
    DrawEntity(const Vector2 &position, const Vector2 &size, const std::string &filename,
               const std::string &nameEntity);

    ~DrawEntity() = default;

    void render() override;
    void update() override;

    /// Permet de charger la texutre et de l'associer à l'entité.
    void loadTexture(const std::string &filename, const std::string &nameEntity);
};

#endif