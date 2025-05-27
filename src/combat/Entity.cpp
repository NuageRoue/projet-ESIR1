#include "combat/Entity.h"

#include <cassert>

Entity::Entity(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks)
: maxHP(_maxHP), actualHP(_maxHP), speed(_speed), name(_name), attacks(_attacks), normalSpeed(_speed)
{}

Entity::~Entity()
{
    for(int i = 0; i < attacks.size(); i++)
    {
        delete attacks[i];
    }
}

/*Entity::Entity(const Entity &that)
{
    maxHP = that.getMaxHP();
    actualHP = that.getActualHP();
    speed = that.getSpeed();
    attacks = std::vector<Attack*>();
    for(int i = 0; i<that.getAttacks().size(); i++){
        attacks[i] = that.getAttacks()[i];
    }
}

Entity& Entity::operator=(const Entity& that)
{
    if (this != &that)
    {
        maxHP = that.getMaxHP();
        actualHP = that.getActualHP();
        speed = that.getSpeed();
        attacks = std::vector<Attack*>();
        for(int i = 0; i<that.getAttacks().size(); i++){
            attacks[i] = that.getAttacks()[i];
        }
    }
    return *this;
}*/

const double &Entity::getMaxHP() const
{
    return maxHP;
}

const double &Entity::getActualHP() const
{
    return actualHP;
}

const unsigned int Entity::getSpeed() const
{
    return speed;
}

const std::string &Entity::getName() const 
{
    return name;
}

const std::vector<Attack*> &Entity::getAttacks() const
{
    return attacks;
}

void Entity::decreaseHP(double dmg)
{
    std::cout << "decreasing hp" << std::endl;
    assert(getActualHP()>0);
    actualHP -= dmg;
    /*if(actualHP - dmg >= 0)
    {
        actualHP -= dmg;
    } else {
        actualHP = 0;
    }*/
}

const double Entity::getBuff() const
{
	return buff;
}
double &Entity::getBuff()
{
	return buff;
}

const unsigned int Entity::getLevel() const
{
	return level;
}

/*void Entity::attack(Entity *target, Attack *attack)
{
    double dmg;
    if (attack->canAttack())
    {
        dmg = attack->getAttackDmg();
        target->decreaseHP(dmg);
        if (attack->getPPActual() > 0)
        {
            attack->decreasePP();
        }
    }
}*/
