#include <entity/DrawEntity.h>

#include <utils/Config.h>

DrawEntity::DrawEntity(const Vector2 &position, const std::string &name, const unsigned int layer,
                       const std::vector<std::string> textureFiles)
    : Entity(position, name, layer), m_textureFiles(textureFiles), m_textures()
{
    TextureManager &textureManager = *TextureManager::getInstance();
    const std::string textureName = "Texture" + name;
    int index = 0;
    for (const std::string &file : m_textureFiles)
    {
        m_textures.push_back(textureManager.loadTexture(file, textureName + std::to_string(index++)));
    }
}

void DrawEntity::render(const Vector2 &ref)
{
    Renderer &render = *Renderer::getInstance();

    const Vector2 position = getPosition() * Config::unit;
    const Vector2 taille = Vector2(1, 1) * Config::unit;

    for (const std::shared_ptr<Texture> texture : m_textures)
    {
        render.drawTexture(texture.get(), position, taille, 0.0f);
    }
}

void DrawEntity::update()
{
}

const std::vector<std::shared_ptr<Texture>> &DrawEntity::getTexture() const
{
    return m_textures;
}