#include <iostream>

#include <game/level/LevelTest.h>

#include <game/GameManager.h>

std::unique_ptr<GameManager> GameManager::m_singleton = nullptr;

GameManager::GameManager() : m_current(nullptr)
{
    m_current = std::unique_ptr<LevelBase>(new LevelTest());
}

void GameManager::initialize()
{
    std::cout << "Initialize Game manager" << std::endl;
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
    if (getLevel().getEndMap().m_fin){
        m_current = getLevel().getNextLevel();
    }
}
