#ifndef ATTACK_LIFE
#define ATTACK_LIFE

#include "Attack.h"

class AttackToLife : public Attack
{
protected:
	unsigned int damage;
public:
	AttackToLife(int _ppMax, std::string _name, unsigned int damage);
	void attack(Entity *caster, Entity *target) override;
	std::string attackMessage(Entity *caster, Entity *target) override;

};

#endif
