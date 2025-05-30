#include "combat/Enemy.h"
#include "combat/Entity.h"
#include "combat/Player.h"

#include <cstdlib>
#include <iostream>
#include <tuple>

Enemy::Enemy(double _maxHP, unsigned int _speed, std::string _name, double _lootXP, std::vector<Attack*> _attacks, std::string _texturePath)
:EntityCombat(_maxHP, _speed, _name, _attacks, _texturePath), lootXP(_lootXP)
{}

Attack * Enemy::chooseAttack() const{
    int randomNum = rand() % attacks.size();
    return attacks[randomNum];
}

std::vector<Item*> Enemy::chooseItem() const{
    std::vector<Item*> lootedItems;
    for (int i = 0; i<lootTable.size(); i++)
    {
        //on choisi un double aléatoire entre 0 et 1
        double randForItem = ((double) rand() / (RAND_MAX));
        if (std::get<1>(lootTable[i]) >= randForItem)
        {
            lootedItems.push_back(std::get<0>(lootTable[i]));
        }
    }
    return lootedItems;   
}

const double &Enemy::getXP() const
{
    return lootXP;
}

const std::vector<std::tuple<Item*, double>> &Enemy::getLootTable() const
{
    return lootTable;
}
