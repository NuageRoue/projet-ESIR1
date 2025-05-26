#include <graphics/texture/TextureManager.h>
#include <graphics/texture/Texture.h>
#include <cassert>

std::unique_ptr<TextureManager> TextureManager::m_singleton = nullptr;

void TextureManager::initialize(){
    m_singleton = std::unique_ptr<TextureManager>(new TextureManager());
}

void TextureManager::finalize(){
    m_singleton = nullptr;
}

std::shared_ptr<Texture> TextureManager::loadTexture(const std::string &filename, const std::string &value)
{
    // Check if the key is already loaded
    auto it = m_textureEntities.find(value);
    if (it != m_textureEntities.end())
    {
        return it->second;
    }

    // Create and load the texture
    std::shared_ptr<Texture> texture = std::make_shared<Texture>(filename);

    // Store the texture
    m_textureEntities[value] = texture;

    return texture;
}

Texture *TextureManager::get(const std::string &value) const
{
    auto it = m_textureEntities.find(value);
    if (it != m_textureEntities.end())
    {
        return it->second.get();
    }
    return nullptr;
}

void TextureManager::removeTexture(const std::string &value)
{
    m_textureEntities.erase(value);
}

void TextureManager::removeAllTexture()
{
    m_textures.clear();
    m_textureEntities.clear();
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    removeAllTexture();
}

TextureManager *TextureManager::getInstance()
{
    return m_singleton.get();
}
