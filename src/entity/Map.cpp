#include <entity/Map.h>

#include <utils/config.h>

Map::Map(const Vector2 &position, const std::string &nameEntity) : Entity(position, 1, nameEntity), m_map(), m_texture()
{
    m_map = Reader::getData();

    m_sizeY = m_map.size();
    m_sizeX = m_map.front().size();

    TextureManager &t = *TextureManager::getInstance();

    std::string texture = "mapTexture";

    m_texture[0] = t.loadTexture("assets/tiles/GRASS.png", texture + std::to_string(0));
    m_texture[1] = t.loadTexture("assets/tiles/BRICK2.png", texture + std::to_string(1));
    m_texture[2] = t.loadTexture("assets/tiles/WATER.png", texture + std::to_string(2));
    m_texture[3] = t.loadTexture("assets/tiles/LAVA.png", texture + std::to_string(3));
}

void Map::update()
{
}

void Map::render()
{
    int type;

    for (unsigned int row = 0; row < m_sizeY; ++row)
    {
        for (unsigned int column = 0; column < m_sizeX; ++column)
        {
            type = m_map.at(row).at(column);

            SDL_Rect destRect = {column * Constants::tile, row * Constants::tile, Constants::tile, Constants::tile};

            Renderer::getInstance()->drawTexture(m_texture.find(type)->second->get(), nullptr, &destRect);
        }
    }
}