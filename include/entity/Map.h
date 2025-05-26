#ifndef __MAP_H
#define __MAP_H

#include <entity/DrawEntity.h>
#include <memory>
#include <unordered_map>
#include <utils/Reader.h>

class Map : public DrawEntity
{
  private:
    unsigned int m_unitX; // Taille de la carte
    unsigned int m_unitY;

    std::vector<std::vector<int>> m_map;

  public:
    /// Constructeur du héros
    Map(const Vector2 &position, const std::string &name);
    ~Map() override = default;

    void update() override;
    void render(const Vector2 &ref) override;
};

#endif