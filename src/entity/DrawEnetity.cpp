#include <entity/DrawEntity.h>

#include <utils/config.h>

DrawEntity::DrawEntity(const Vector2 &position, const Vector2 &size, const std::string &filename,
                       const std::string &nameEntity)
    : Entity(position, size, nameEntity), m_nameEntity(nameEntity)
{
    loadTexture(filename, m_nameEntity);
}

void DrawEntity::loadTexture(const std::string &filename, const std::string &nameEntity)
{
    m_nameEntity = nameEntity;
    m_texture = TextureManager::getInstance()->loadTexture(filename, m_nameEntity);
}

void DrawEntity::render()
{
    Renderer::getInstance()->drawTexture(m_texture.get(), getPosition() + Vector2(1, 1) * (Constants::tile / 2),
                                         Vector2(Constants::tile, Constants::tile), 0.f);
}

void DrawEntity::update()
{
}