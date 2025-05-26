#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <memory>
#include <set>
#include <string>
#include <unordered_map>

#include <entity/Entity.h>
#include <entity/Hero.h>
#include <entity/Map.h>

#include <game/Game.h>

class GameManager
{
  private:
    friend class Game;

  private:
    static std::unique_ptr<GameManager> m_singleton;

    std::set<char> *m_pressed;
    std::vector<std::unique_ptr<Entity>> m_entites; // set avec toutes les entites du jeu

    Hero *m_hero;
    Map *m_map;
    Vector2 m_ref;

  private:
    GameManager();

  public:
    ~GameManager() = default;

    // singletons
    static void initialize();
    static void finalize();
    static GameManager &getInstance();

    // update render
    void render();
    void update();

    // touche pressé uniquement ici
    std::set<char> &getKeyDown() const;
};

#endif