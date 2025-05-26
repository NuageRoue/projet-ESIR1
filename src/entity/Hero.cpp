#include <entity/Hero.h>

#include <game/GameManager.h>

const std::string Hero::nameHero = "hero";

Hero::Hero(const Vector2 &position, const unsigned int layer, const std::vector<std::string> textureFiles)
    : DrawEntity(position, Hero::nameHero, layer, textureFiles)
{
}

void Hero::update()
{
    Vector2 delta;

    for (char c : GameManager::getInstance().getKeyDown())
    {

        switch (c)
        {
        case 'z': {
            delta = Vector2(0, -1);
            break;
        }
        case 'q': {
            delta = Vector2(-1, 0);
            break;
        }
        case 's': {
            delta = Vector2(0, 1);
            break;
        }
        case 'd': {
            delta = Vector2(1, 0);
            break;
        }

        default:
            break;
        }

        // std::cout << c << std::endl;
    }

    setPosition(getPosition() + delta * Constants::tile);
}
