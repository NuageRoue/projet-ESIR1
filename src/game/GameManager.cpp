#include <game/GameManager.h>

#include <entity/Hero.h>
#include <entity/Map.h>

#include <algorithm>

std::unique_ptr<GameManager> GameManager::m_singleton = nullptr;

GameManager::GameManager() : m_entites(), m_keyDown(nullptr)
{
    m_entites["hero"] =
        std::unique_ptr<Hero>(new Hero(Vector2(0, 0), Vector2(1, 1), "./assets/tiles/liquidWater.png", "textureHero"));
    m_entites["map"] = std::unique_ptr<Map>(new Map(Vector2(0, 0), "map"));
}

void GameManager::initialize()
{
    m_singleton = std::unique_ptr<GameManager>(new GameManager());
}
void GameManager::finalize()
{
    m_singleton = nullptr;
}
GameManager &GameManager::getInstance()
{
    return *m_singleton;
}

void GameManager::render()
{

    std::for_each(m_entites.begin(), m_entites.end(),
                  [](std::pair<const std::string, std::unique_ptr<Entity>> &s) { s.second->render(); });
}

void GameManager::update()
{
    std::for_each(m_entites.begin(), m_entites.end(),
                  [](std::pair<const std::string, std::unique_ptr<Entity>> &s) { s.second->update(); });
}

std::set<char> &GameManager::getKeyDown() const
{
    return *m_keyDown;
}