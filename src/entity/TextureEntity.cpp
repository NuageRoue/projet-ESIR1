#include <game/GameManager.h>
#include <graphics/Renderer.h>
#include <graphics/texture/TextureManager.h>

#include <entity/TextureEntity.h>

TextureEntity::TextureEntity(const Vector2F &position, const std::string &name, const unsigned int layer,
                             const std::string &textureFile)
    : Entity(position, name, layer), m_texture(TextureManager::getInstance().loadTexture(textureFile, name + "Texture"))
{
}

void TextureEntity::render(const Vector2F &ref)
{
    Renderer::getInstance().drawTexture(m_texture, getPosition(), Vector2F(Config::tile, Config::tile), 0.0f);
}

#include <iostream>

void TextureEntity::update()
{
    setPosition(GameManager::getLevel().getPlayer().getPosition());
    std::cout << getPosition()[0] << ", " << getPosition()[1] << std::endl;
}

void TextureEntity::changeTexture(Texture *texture)
{
    m_texture = texture;
}