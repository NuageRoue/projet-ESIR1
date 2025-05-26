#include <entity/Map.h>

#include <utils/config.h>

Map::Map(const Vector2 &position, const std::string &name)
    : DrawEntity(
          position, name, 0,
          {"assets/tiles/GRASS.png", "assets/tiles/BRICK2.png", "assets/tiles/WATER.png", "assets/tiles/LAVA.png"}),
      m_map(), m_unitX(0), m_unitY(0)
{
    m_map = Reader::getData();

    m_unitY = m_map.size();
    m_unitX = m_map.front().size();
}

void Map::update()
{
}

void Map::render(const Vector2 &ref)
{
    int type;

    for (unsigned int row = 0; row < m_unitY; ++row)
    {
        for (unsigned int column = 0; column < m_unitX; ++column)
        {
            type = m_map.at(row).at(column);

            SDL_Rect destRect = {column * Constants::tile + ref[0], row * Constants::tile + ref[1], Constants::tile, Constants::tile};

            Renderer::getInstance()->drawTexture(getTexture().at(type)->get(), nullptr, &destRect);
        }
    }
}