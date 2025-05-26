#ifndef _GAME_H
#define _GAME_H


#include <game/GameManager.h>
#include <utils/Timer.h>

#include <set>

class Game
{

  private:
    enum class GameState
    {
        PLAY,
        EXIT
    };
    GameState m_gameState; // Etat du jeu


    // std::shared_ptr<Map> m_map;		//Carte du jeu

    

  public:
    // Constructeur initialiser fenetre
    Game();

    virtual ~Game();

    // lancer le jeu
    void run();

  private:
    void initGame();

    void loadGame(const std::string &filename);

    // boucle du jeu
    void gameLoop();

    // mise a jour
    void update();

    void render();

    // fin du jeu
    void endGame();
};

#endif //_GAME_H