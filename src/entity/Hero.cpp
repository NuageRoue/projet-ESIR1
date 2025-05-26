#include <entity/Hero.h>

#include <game/GameManager.h>

const std::string Hero::nameHero = "hero";

Hero::Hero(const Vector2 &position, const unsigned int layer, const std::vector<std::string> textureFiles)
    : DrawEntity(position, Hero::nameHero, layer, textureFiles)
{
}

void Hero::update()
{
    for (char c : GameManager::getInstance().getKeyDown())
    {
        std::cout << c << std::endl;
    }
}
