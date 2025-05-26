#ifndef __MAP_H
#define __MAP_H

#include <entity/DrawEntity.h>
#include <memory>
#include <utils/Reader.h>
#include <unordered_map>

class Map : public Entity
{
  private:
    unsigned int m_sizeX; // Taille de la carte
    unsigned int m_sizeY;
    std::vector<std::vector<int>> m_map;
    std::unordered_map<int, std::shared_ptr<Texture>> m_texture;

  public:
    /// Constructeur du héros
    Map(const Vector2 &position, const std::string &name);
    ~Map() override = default;

    void update() override;
    void render() override;
};

#endif