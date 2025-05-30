#include <algorithm>
#include <limits>

#include <graphics/texture/TextureManager.h>

#include <entity/PlayerWord.h>

#include <game/EventHandler.h>
#include <game/GameManager.h>

PlayerWord::PlayerWord(const Vector2F &position)
    : TextureEntity(position, Config::playerTag, Config::playerLayer, Config::playerTexture), m_rotation(M_PI * 3)
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

        case 'R': {
            delta = Vector2F(0, -1);
            break;
        }
        case 'P': {
            delta = Vector2F(-1, 0);
            break;
        }
        case 'Q': {
            delta = Vector2F(0, 1);
            break;
        }
        case 'O': {
            delta = Vector2F(1, 0);
            break;
        }

        default:
            break;
        }
    }

    if (delta != Vector2F(0, 0))
    {
        
        if (delta[0] == -1)
        {
            changeTexture(TextureManager::getInstance().loadTexture(Config::playerTexture,
                                                                    std::string(Config::playerTexture) + "Texture"));
        }
        else if (delta[0] == 1)
        {
            changeTexture(TextureManager::getInstance().loadTexture(Config::playerTexture2,
                                                                    std::string(Config::playerTexture2) + "Texture"));
        }

        const Vector2F next = getPosition() + delta * Config::tile;
        delta = next;
        m_grid = (delta / Config::tile).floor();
        int type = GameManager::getLevel().getMap().getType(m_grid);

        // verif si on peut se deplacer
        if (std::find(Config::mapCollision.begin(), Config::mapCollision.end(), type) == Config::mapCollision.end())
        {
            m_rotation = -m_rotation;
            const Vector2F temp = getPosition();
            setPosition(next);

            const int rand = random() & 100;
            if (rand > 80)
            {
                GameManager::getInstance().setFighting(true);
            }
        }
    }
}

void PlayerWord::render(const Vector2F &ref)
{
    const Vector2F last = getPosition();

    setPosition(last + ref); // mais wesh

    Renderer::getInstance().drawTexture(getTexture(), getPosition(), Vector2F(Config::tile, Config::tile), m_rotation);

    setPosition(last);
}

const Vector2I &PlayerWord::getGrid() const
{
    return m_grid;
}