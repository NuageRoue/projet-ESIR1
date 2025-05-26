#ifndef __GAME__H
#define __GAME__H

#include <utils/Timer.h>

#include <set>

class Game
{

  private:
    enum class GameState
    {
        PLAY,
        PAUSE,
        EXIT
    };
    GameState m_gameState; // Etat du jeu

  public:
    Game();

    ~Game() = default;

    void run();

  private:
    void initGame();

    // boucle du jeu
    void gameLoop();

    // fin du jeu
    void endGame();
};

#endif //_GAME_H