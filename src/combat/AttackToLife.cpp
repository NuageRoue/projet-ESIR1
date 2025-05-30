#include "combat/Attack.h"
#include <combat/AttackToLife.h>
#include <combat/Entity.h>
#include <iostream>
#include <string>

AttackToLife::AttackToLife(int _ppMax, std::string _name, unsigned int damage)
: Attack(_ppMax, _name), damage(damage)
{}

void AttackToLife::attack(EntityCombat *caster, EntityCombat *target)
{
	std::cout << "attacking" << std::endl;
	target->decreaseHP(damage);//(caster->getBuff() * (1 + 0.1 * caster->getLevel()) * damage);
	Attack::attack(caster,target);
}

std::string AttackToLife::attackMessage(EntityCombat *caster, EntityCombat *target)
{
	std::string test = caster->getName() + " inflige " + std::to_string(damage) + " a " + target->getName();
	return test;
}
