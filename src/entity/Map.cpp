#include <graphics/texture/TextureManager.h>
#include <utils/Config.h>
#include <utils/Reader.h>

#include <entity/Map.h>

Map::Map(const Vector2F &position, const std::string &name)
    : Entity(position, name, 0), m_map(), m_unitX(0), m_unitY(0), m_textures()
{
    {
        int index = 0;
        TextureManager &manager = TextureManager::getInstance();
        for (const std::string &file : Config::mapTextures)
        {
            ++index;
            m_textures.push_back(manager.loadTexture(file, name + std::to_string(index)));
        }
    }

    m_map = Reader::getData();

    m_unitY = m_map.size();
    m_unitX = m_map.front().size();
}

void Map::update()
{
}

int Map::getType(const Vector2I &v) const
{
    return m_map.at(v[1]).at(v[0]);
}

void Map::render(const Vector2F &ref)
{
    int type;
    Renderer &renderer = Renderer::getInstance();

    for (unsigned int row = 0; row < m_unitY; ++row)
    {
        for (unsigned int column = 0; column < m_unitX; ++column)
        {
            type = m_map.at(row).at(column);

            SDL_Rect destRect = {column * Config::tile + ref[0], row * Config::tile + ref[1], Config::tile,
                                 Config::tile};

            renderer.drawTexture(m_textures.at(type)->getSDL(), nullptr, &destRect);
        }
    }
}