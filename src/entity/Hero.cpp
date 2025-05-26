#include <entity/Hero.h>

#include <game/GameManager.h>

Hero::Hero(const Vector2 &position, const Vector2 &size, const std::string &filename, const std::string &nameEntity)
    : DrawEntity(position, size, filename, nameEntity)
{
}

void Hero::update()
{
    for (char c : GameManager::getInstance().getKeyDown())
    {
        std::cout << c << std::endl;
    }
}

void Hero::render()
{
    DrawEntity::render();
}