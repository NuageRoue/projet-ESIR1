#ifndef ATTACK_LIFE
#define ATTACK_LIFE

#include "Attack.h"
#include "combat/Entity.h"

class AttackToLife : public Attack
{
protected:
	unsigned int damage;
public:
	AttackToLife(int _ppMax, std::string _name, unsigned int damage);
	void attack(EntityCombat *caster, EntityCombat *target) override;
	std::string attackMessage(EntityCombat *caster, EntityCombat *target) override;

};

#endif
