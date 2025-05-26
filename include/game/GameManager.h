#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <memory>
#include <set>
#include <string>
#include <unordered_map>

#include <game/Game.h>

#include <game/level/LevelBase.h>

class GameManager
{
  private:
    friend class Game;

  private:
    static std::unique_ptr<GameManager> m_singleton;

    std::set<char> *m_pressed;
    std::unique_ptr<LevelBase> m_current;

  private:
    GameManager();

  public:
    ~GameManager() = default;

    // singletons
    static void initialize();
    static void finalize();
    static GameManager &getInstance();
    static LevelBase &getLevel();

    // update render
    void render();
    void update();

    // touche pressé uniquement ici
    std::set<char> &getKeyDown() const;
};

#endif