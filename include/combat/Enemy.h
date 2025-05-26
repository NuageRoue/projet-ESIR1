#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"

#include <vector>
#include <iostream>

class Player;
class Attack;

class Enemy : public Entity{
    protected:
    
    public:
    Enemy(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks);
    virtual ~Enemy() = default;

    Attack * chooseAttack() const;

};

#endif //__ENEMY_H__