#include <graphics/texture/TextureManager.h>
#include <utils/Config.h>
#include <utils/Reader.h>

#include <entity/Map.h>

#include <iostream>

Map::Map(const Vector2F &position, const std::string &name, std::vector<std::vector<int>> map)
    : Entity(position, name, 0), m_map(map), m_unitX(0), m_unitY(0), m_textures()
{
    TextureManager &manager = TextureManager::getInstance();

    m_unitY = m_map.size();
    m_unitX = m_map.front().size();

    for (size_t plage = 0; plage < Config::specialTexture.size(); plage++)
    {
        const std::vector<std::string> &current = Config::specialTexture[plage];

        for (size_t i = 0; i < current.size(); i++)
        {
            const std::string &file = current[i];
            int index = plage * Config::mapTexturePlage + i;
            m_textures[index] = manager.loadTexture(file, name + std::to_string(index));

            std::cout << index << " : " << file << std::endl;
        }
    }

    for (size_t i = 0; i < Config::mapTextures.size(); i++)
    {
        const std::string &file = Config::mapTextures[i];
        m_textures[Config::startNormalPlage + i] =
            manager.loadTexture(file, name + std::to_string(Config::startNormalPlage + i));

        std::cout << Config::startNormalPlage + i << " : " << file << std::endl;
    }

    int type;
    for (unsigned int row = 0; row < m_unitY; ++row)
    {
        for (unsigned int column = 0; column < m_unitX; ++column)
        {
            const int value = m_map.at(row).at(column);
            if (value >= Config::specialTexture.size())
            {
                std::cout << value << " -> " << m_map.at(row).at(column) + Config::startNormalPlage - 1 << std::endl;
                m_map.at(row).at(column) += Config::startNormalPlage - 1;
            }
            else
            {
                const std::vector<std::string> &current = Config::specialTexture.at(value);
                type = value * Config::mapTexturePlage;

                type += random() & (current.size() - 1);
                std::cout << m_map.at(row).at(column) << " -> " << type << std::endl;
                m_map.at(row).at(column) = type;
            }
        }
    }
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

            renderer.drawTexture(m_textures[type]->getSDL(), nullptr, &destRect);
        }
    }
}