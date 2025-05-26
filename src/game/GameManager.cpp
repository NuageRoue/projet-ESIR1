#include <game/GameManager.h>

#include <entity/Hero.h>
#include <entity/Map.h>

#include <algorithm>

std::unique_ptr<GameManager> GameManager::m_singleton = nullptr;

GameManager::GameManager() : m_entites(), m_pressed(nullptr), m_hero(nullptr), m_map(nullptr), m_ref(Vector2(0, 0))
{
    auto hero = std::unique_ptr<Hero>(new Hero(Vector2(Constants::tile, Constants::tile) / 2, 2,
                                               std::vector<std::string>{"./assets/tiles/liquidWater.png"}));
    m_hero = (Hero *)hero.get();

    m_entites.push_back(std::move(hero));

    auto map = std::unique_ptr<Map>(new Map(Vector2(0, 0), "map"));

    m_map = (Map *)map.get();

    m_entites.push_back(std::move(map));
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
    const Vector2 ref = -m_hero->getPosition();

    std::sort(m_entites.begin(), m_entites.end(),
              [](const std::unique_ptr<Entity> &a, const std::unique_ptr<Entity> &b) {
                  return a->getLayer() < b->getLayer();
              });

    std::for_each(m_entites.begin(), m_entites.end(),
                  [&ref](const std::unique_ptr<Entity> &entity) { entity->render(ref); });
}

void GameManager::update()
{
    std::for_each(m_entites.begin(), m_entites.end(), [](const std::unique_ptr<Entity> &entity) { entity->update(); });
}

std::set<char> &GameManager::getKeyDown() const
{
    return *m_pressed;
}