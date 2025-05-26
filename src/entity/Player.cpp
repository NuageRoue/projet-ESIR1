#include <entity/Player.h>

#include <game/EventHandler.h>

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

    setPosition(getPosition() + delta * Config::tile);
}

void Player::render(const Vector2F &ref)
{
    const Vector2F last = getPosition();

    setPosition(last + ref);

    TextureEntity::render(ref);

    setPosition(last);
}

Vector2I Player::getGridVector() const
{
    Vector2F pos = getPosition();
    return Vector2I(pos[0], pos[1]);
}
