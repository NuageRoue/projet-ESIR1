#include <game/GameManager.h>

#include <entity/Hero.h>
#include <entity/Map.h>

#include <algorithm>

std::unique_ptr<GameManager> GameManager::m_singleton = nullptr;

GameManager::GameManager() : m_entites(), m_pressed(nullptr)
{
    m_entites.insert(std::unique_ptr<Hero>(new Hero(Vector2(Constants::tile, Constants::tile) / 2, 2,
                                                    std::vector<std::string>{"./assets/tiles/liquidWater.png"})));
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
    std::for_each(m_entites.begin(), m_entites.end(), [](const std::unique_ptr<Entity> &entity) { entity->render(); });
}

void GameManager::update()
{
    std::for_each(m_entites.begin(), m_entites.end(), [](const std::unique_ptr<Entity> &entity) { entity->update(); });
}

std::set<char> &GameManager::getKeyDown() const
{
    return *m_pressed;
}