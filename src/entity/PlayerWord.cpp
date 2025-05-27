#include <algorithm>
#include <limits>

#include <entity/PlayerWord.h>

#include <game/EventHandler.h>
#include <game/GameManager.h>

PlayerWord::PlayerWord(const Vector2F &position)
    : TextureEntity(position, Config::playerTag, Config::playerLayer, Config::playerTexture)
{
}

void PlayerWord::update()
{
    Vector2F delta(0, 0);

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

    if (delta != Vector2F(0, 0))
    {
        const Vector2F next = getPosition() + delta * Config::tile;
        delta = next;
        m_grid = (delta / Config::tile).floor();
        int type = GameManager::getLevel().getMap().getType(m_grid);

        // verif si on peut se deplacer
        if (std::find(Config::mapCollision.begin(), Config::mapCollision.end(), type) == Config::mapCollision.end())
        {
            const Vector2F temp = getPosition();
            setPosition(next);

            const int rand = random() & 100;
            if (rand > 80)
            {
                std::cout << "Combat !" << std::endl;
            }
        }
    }
}

void PlayerWord::render(const Vector2F &ref)
{
    const Vector2F last = getPosition();

    setPosition(last + ref); // mais wesh

    TextureEntity::render(ref);

    setPosition(last);
}

const Vector2I &PlayerWord::getGrid() const
{
    return m_grid;
}