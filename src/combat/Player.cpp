#include "combat/Player.h"
#include "combat/Enemy.h"
#include <iostream>
#include <cassert>

Player::Player(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks, std::vector<Item*> _items, std::string _texturePath)
:EntityCombat(_maxHP, _speed, _name, _attacks, _texturePath), items(_items), xp(0), level(1), levelCap(100)
{}

Player::~Player()
{
    for(int i = 0; i < items.size(); i++)
    {
        delete items[i];
    }
}

const double &Player::getXP() const
{
    return xp;
}

const unsigned int &Player::getLevel() const
{
    return level;
}

const double Player::getLevelCap() const
{
    return levelCap;
}

const std::vector<Item *> &Player::getItems() const
{
    return items;
}


void Player::increaseXP(double gainedXP)
{
    if(xp+gainedXP >= levelCap)
    {
        xp = levelCap - xp+gainedXP;
        ++level;
        levelCap += 100;
        std::cout << "Bien joué, vous êtes passé niveau " << level << std::endl;
    } else {
        xp += gainedXP;
    }
}

void Player::addItems(std::vector<Item*> itemsToAdd){
    items.insert(itemsToAdd.begin(), itemsToAdd.end(), itemsToAdd.begin());
}
