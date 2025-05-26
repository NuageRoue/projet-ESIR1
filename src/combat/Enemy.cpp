#include "combat/Enemy.h"
#include "combat/Entity.h"
#include "combat/Player.h"

#include <cstdlib>
#include <iostream>

Enemy::Enemy(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks)
:Entity(_maxHP, _speed, _name, _attacks)
{}

Attack * Enemy::chooseAttack() const{
    int randomNum = rand() % attacks.size();
    return attacks[randomNum];
}

