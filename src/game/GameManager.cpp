#include <game/GameManager.h>

#include <entity/Hero.h>
#include <entity/Map.h>

#include <algorithm>

#include <game/level/Level1.h>

std::unique_ptr<GameManager> GameManager::m_singleton = nullptr;

GameManager::GameManager() : m_pressed(nullptr), m_current(nullptr)
{

    m_current = std::unique_ptr<LevelBase>(new Level1());
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

LevelBase &GameManager::getLevel()
{
    return *(m_singleton->m_current);
}

void GameManager::render()
{
    m_current->render();
}

void GameManager::update()
{
    m_current->update();
}

std::set<char> &GameManager::getKeyDown() const
{
    return *m_pressed;
}