#ifndef __MAP_H
#define __MAP_H

#include <graphics/texture/Texture.h>

#include <entity/Entity.h>

#include <memory>
#include <unordered_map>

class Map : public Entity
{
  private:
    unsigned int m_unitX; // Taille de la carte
    unsigned int m_unitY;

    std::vector<std::vector<int>> m_map;
    std::unordered_map<int, Texture *> m_textures;

  public:
    /// Constructeur du héros
    Map(const Vector2F &position, const std::string &name, std::vector<std::vector<int>> map);
    ~Map() override = default;

    void update() override;
    void render(const Vector2F &ref) override;

    int getType(const Vector2I &v) const;
    Vector2F getTaille();
};

#endif