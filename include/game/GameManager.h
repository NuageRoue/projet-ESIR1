#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <memory>
#include <set>
#include <string>
#include <unordered_map>

#include <entity/Entity.h>

#include <game/Game.h>

class GameManager
{
  private:
    static std::unique_ptr<GameManager> m_singleton;

    friend class Game;

    std::set<char> *m_keyDown;
    std::unordered_map<std::string, std::unique_ptr<Entity>> m_entites; // set avec toutes les entites du jeu

  private:
    GameManager();

  public:
    ~GameManager() = default;
    static void initialize();
    static void finalize();
    static GameManager &getInstance();
    void render();
    void update();
    std::set<char> &getKeyDown() const;
};

#endif