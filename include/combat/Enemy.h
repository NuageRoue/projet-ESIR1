#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"
#include "Item.h"

#include <tuple>
#include <vector>
#include <iostream>

class Player;
class Attack;

class Enemy : public Entity{
    protected:
    double lootXP;
    std::vector<std::tuple<Item*, double>> lootTable;

    public:
    Enemy(double _maxHP, unsigned int _speed, std::string _name, double _lootXP, std::vector<Attack*> _attacks);
    virtual ~Enemy() = default;

    Attack * chooseAttack() const;

    std::vector<Item*> chooseItem() const;

    const double &getXP() const;
    const std::vector<std::tuple<Item*, double>> &getLootTable() const;

};

#endif //__ENEMY_H__