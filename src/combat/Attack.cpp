#include "combat/Attack.h"

Attack::Attack(double _attackDmg, int _ppMax, std::string _name)
: attackDmg(_attackDmg), ppMax(_ppMax), ppActual(_ppMax), name(_name)
{}

Attack::Attack(const Attack &that)
{
    attackDmg = that.getAttackDmg();
    ppMax = that.getPPMax();
    ppActual = that.getPPActual();
    name = that.getName();
}

Attack &Attack::operator=(const Attack &that)
{
    if (this != &that)
    {
        attackDmg = that.getAttackDmg();
        ppMax = that.getPPMax();
        ppActual = that.getPPActual();
        name = that.getName();
    }
    return *this;
}

const double &Attack::getAttackDmg() const
{
    return attackDmg;
}

const int Attack::getPPMax() const
{
    return ppMax;
}

const int Attack::getPPActual() const
{
    return ppActual;
}

const std::string &Attack::getName() const
{
    return name;
}
bool Attack::canAttack()
{
    return getPPActual() != 0;
}

void Attack::decreasePP()
{
    --ppActual;
}
