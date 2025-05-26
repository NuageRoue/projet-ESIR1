#include <cassert>
#include <iostream>

#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>

std::unique_ptr<TextureManager> TextureManager::m_singleton = nullptr;

void TextureManager::initialize()
{
    std::cout << "Initialize Texture manager" << std::endl;
    m_singleton = std::unique_ptr<TextureManager>(new TextureManager());
}

void TextureManager::finalize()
{
    m_singleton = nullptr;
}

Texture *TextureManager::loadTexture(const std::string &filename, const std::string &value)
{
    auto txt = getTexture(value);
    if (txt != nullptr)
    {
        return txt;
    }

    // Create and load the texture
    std::unique_ptr<Texture> texture(new Texture(filename));

    Texture *result = texture.get();

    // Store the texture
    m_loaded[value] = std::move(texture);

    return result;
}

Texture *TextureManager::getTexture(const std::string &value) const
{
    auto it = m_loaded.find(value);
    if (it != m_loaded.end())
    {
        return it->second.get();
    }
    return nullptr;
}

void TextureManager::removeTexture(const std::string &value)
{
    m_loaded.erase(value);
}

void TextureManager::removeAllTexture()
{
    m_loaded.clear();
}

TextureManager::TextureManager() : m_loaded()
{
}

TextureManager::~TextureManager()
{
    removeAllTexture();
}

TextureManager &TextureManager::getInstance()
{
    return *m_singleton.get();
}
