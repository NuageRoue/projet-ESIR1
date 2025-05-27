#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <memory>

#include <game/Game.h>

#include <game/level/LevelBase.h>

class GameManager
{
  private:
    friend class Game;

  private:
    static std::unique_ptr<GameManager> m_singleton;

    std::unique_ptr<LevelBase> m_current;

  private:
    GameManager();

  public:
    ~GameManager() = default;

    // singleton no cp
    GameManager(const GameManager &) = delete;
    void operator=(const GameManager &) = delete;

    // singletons
    static void initialize();
    static void finalize();
    static GameManager &getInstance();
    static LevelBase &getLevel();

    // update render
    void render();
    void update();

    bool finalEnd() const;
};

#endif