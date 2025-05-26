#include <iostream>
#include "combat/Attack.h"
#include "combat/Enemy.h"
#include "combat/Entity.h"
#include "combat/Item.h"
#include "combat/Player.h"

#include <vector>

int main()
{
    std::vector<Item*> items;

    Attack * questionS = new Attack(20, 3, "Comment tu t'appelles ?");
    Attack * interjectionB = new Attack(15, -1, "Nan mais !");
    Attack *  insulte = new Attack(5, -1, "Insulte");
    Attack *  souffle = new Attack(10, 2, "Soufflement du nez");

    std::vector<Attack*> attacksPlayer;
    attacksPlayer.push_back(insulte);
    attacksPlayer.push_back(souffle);
    std::vector<Attack*> attacksEnemy;
    attacksEnemy.push_back(questionS);
    attacksEnemy.push_back(interjectionB);

    Player player(20.0, 50, "MARTIN", attacksPlayer, items);
    Enemy enemy(15.0, 30, "NIELS", 100, attacksEnemy);

    

    while(player.getActualHP() > 0 && enemy.getActualHP() > 0)
    {
        std::vector<Entity*> priorityList;
        if (player.getSpeed()>=enemy.getSpeed())
        {
            priorityList.push_back(&player);
            priorityList.push_back(&enemy);
        }else{
            priorityList.push_back(&enemy);
            priorityList.push_back(&player);
        }
        Attack * actualAttack;

        std::cout << priorityList[1]->getName() << " a " << priorityList[1]->getActualHP() << "HP" << std::endl;
        actualAttack = priorityList[0]->chooseAttack();
        priorityList[0]->attack(priorityList[1],actualAttack);
        std::cout << priorityList[0]->getName() <<" a fait " << actualAttack->getAttackDmg() << " dégâts a " 
        << priorityList[1]->getName() << " avec " << actualAttack->getName() << std::endl;
        std::cout << priorityList[1]->getName() << " a " << priorityList[1]->getActualHP() << "HP" << std::endl;
        std::cout << "________________________________________" << std::endl;

        if (priorityList[1]->getActualHP() <= 0) {break;}

        std::cout << priorityList[0]->getName() << " a " << priorityList[0]->getActualHP() << "HP" << std::endl;
        actualAttack = priorityList[1]->chooseAttack();
        priorityList[1]->attack(priorityList[0],actualAttack);
        std::cout << priorityList[1]->getName() <<" a fait " << actualAttack->getAttackDmg() << " dégâts a " 
        << priorityList[0]->getName() << " avec " << actualAttack->getName() << std::endl;
        std::cout << priorityList[0]->getName() << " a " << priorityList[0]->getActualHP() << "HP" << std::endl;
        std::cout << "________________________________________" << std::endl;
    }
    //vous avez gagné
    if (player.getActualHP() > 0)
    {
        std::cout << "Bravo ! Vous avez vaincu " << enemy.getName() << " !" << std::endl;
        std::cout << "Vous avez gagné " << enemy.getXP() << " XP." << std::endl;
        player.increaseXP(enemy.getXP());
    }else{
        std::cout << enemy.getName() << " vous a vaincu :(" << std::endl;
    }
    
}