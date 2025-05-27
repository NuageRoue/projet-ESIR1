
#include "combat/Entity.h"
#include <graphics/texture/Texture.h>
#include <graphics/texture/TextureManager.h>

#include <cassert>

EntityCombat::EntityCombat(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack *> _attacks,
                           std::string _texturePath)
    : maxHP(_maxHP), actualHP(_maxHP), speed(_speed), name(_name), attacks(_attacks), normalSpeed(_speed),
      texture(TextureManager::getInstance().loadTexture(_texturePath, "Texture " + _texturePath))
{
}

EntityCombat::~EntityCombat()
{
    for (int i = 0; i < attacks.size(); i++)
    {
        delete attacks[i];
    }
}

/*EntityCombat::EntityCombat(const EntityCombat &that)
{
    maxHP = that.getMaxHP();
    actualHP = that.getActualHP();
    speed = that.getSpeed();
    attacks = std::vector<Attack*>();
    for(int i = 0; i<that.getAttacks().size(); i++){
        attacks[i] = that.getAttacks()[i];
    }
}

EntityCombat& EntityCombat::operator=(const EntityCombat& that)
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

const double &EntityCombat::getMaxHP() const
{
    return maxHP;
}

const double &EntityCombat::getActualHP() const
{
    return actualHP;
}

const unsigned int EntityCombat::getSpeed() const
{
    return speed;
}

const std::string &EntityCombat::getName() const
{
    return name;
}

const std::vector<Attack *> &EntityCombat::getAttacks() const
{
    return attacks;
}

void EntityCombat::decreaseHP(double dmg)
{
    std::cout << "decreasing hp" << std::endl;
    assert(getActualHP() > 0);
    actualHP = (actualHP - dmg > 0) ? actualHP - dmg : 0;

    /*if(actualHP - dmg >= 0)
    {
        actualHP -= dmg;
    } else {
        actualHP = 0;
    }*/
}

const double EntityCombat::getBuff() const
{
    return buff;
}
double &EntityCombat::getBuff()
{
    return buff;
}

const unsigned int EntityCombat::getLevel() const
{
    return level;
}

/*void EntityCombat::attack(EntityCombat *target, Attack *attack)
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
