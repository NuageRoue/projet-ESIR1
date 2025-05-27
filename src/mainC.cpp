#include "combat/Entity.h"
#include <SDL.h>
#include <combat/AttackToLife.h>
#include <combat/CombatManager.h>
#include <combat/Enemy.h>
#include <combat/Player.h>
#include <combat/UI.h>
#include <vector>
#include <graphics/texture/TextureManager.h>
int main(int, char **)
{

	Renderer::initialize();




    // Création des attaques pour le joueur
    std::vector<Attack *> playerAttacks;
    playerAttacks.push_back(new AttackToLife(-1, "Attaque héros 1", 10));
    playerAttacks.push_back(new AttackToLife(1, "Attack héros 2", 15));
    playerAttacks.push_back(new AttackToLife(20, "Attack héros 3", 20));
    playerAttacks.push_back(new AttackToLife(25, "Attack héros 4", 2500));

    // Création d'un vecteur d'items vide pour le joueur
    std::vector<Item *> playerItems;


    // Création du joueur
    Player *player = new Player(100.0, 10, "Martin", playerAttacks, playerItems, "assets/entities/dragon.png");
//	EntityCombat*entity = new EntityCombat(100.0, 10, "Martin", playerAttacks, "assets/entities/dragon.png");
    // Création d'un vecteur de joueurs contenant un seul joueur
    std::vector<Player *> players;
    //players.push_back(player);

    // Création des attaques pour l'ennemi
    std::vector<Attack *> enemyAttacks;
    enemyAttacks.push_back(new AttackToLife(5, "Enemy Attack 1", 5));
    enemyAttacks.push_back(new AttackToLife(8, "Enemy Attack 2", 8));

    // Création de l'ennemi
    //Enemy *enemy = new Enemy(80.0, 8, "Niels >:(", 50.0, enemyAttacks, "assets/entities/dragon.png");
    // playerAttacks[3]->attack(player, enemy);
    //  Création d'un vecteur d'ennemis contenant un seul ennemi
    std::vector<Enemy *> enemies;
    //enemies.push_back(enemy);
    std::cout << ":)" << std::endl;
/*
    CombatManager manager(players, enemies);

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
        return -1;
    }

    bool run = true;
    SDL_Event event;

    while (run)
    {
        while (SDL_PollEvent(&event))
        {
            UI::processEvent(&event);
            if (event.type == SDL_QUIT)
                run = false;
        }
        manager.update();
        UI::displayUI(&manager);

        SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
        SDL_RenderClear(renderer);
        UI::render(renderer);
        SDL_RenderPresent(renderer);
    }

    UI::flushUI();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
*/
	Renderer::finalize();
	std::cout << "finito pipo" << std::endl;
    return 0;
}
