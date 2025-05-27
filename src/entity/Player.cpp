#include <algorithm>

#include <entity/Player.h>

#include <game/EventHandler.h>
#include <game/GameManager.h>

Player::Player(const Vector2F &position)
    : TextureEntity(position, Config::playerTag, Config::playerLayer, Config::playerTexture)
{
}

void Player::update()
{
    Vector2F delta;

    for (const char &key : EventHandler::getInstance().getActive())
    {
        switch (key)
        {
        case 'z': {
            delta = Vector2F(0, -1);
            break;
        }
        case 'q': {
            delta = Vector2F(-1, 0);
            break;
        }
        case 's': {
            delta = Vector2F(0, 1);
            break;
        }
        case 'd': {
            delta = Vector2F(1, 0);
            break;
        }

        default:
            break;
        }
    }

    const Vector2F next = getPosition() + delta * Config::tile;
    delta = next;
    Vector2I grid = (delta / Config::tile).floor();
    std::cout << grid[0] << ", " << grid[1] << std::endl;
    int type = GameManager::getLevel().getMap().getType(grid);

    if (std::find(Config::mapCollision.begin(), Config::mapCollision.end(), type) == Config::mapCollision.end())
    {
        setPosition(next);
    }
}

void Player::render(const Vector2F &ref)
{
    const Vector2F last = getPosition();

    setPosition(last + ref);

    TextureEntity::render(ref);

    setPosition(last);
}
