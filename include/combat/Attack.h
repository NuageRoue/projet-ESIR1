#ifndef __ATTACK_H__
#define __ATTACK_H__

#include <iostream>
#include <string>
class EntityCombat;


class Attack{
    protected:
        int ppMax;
        int ppActual;
        std::string name;
    public:
        Attack(int _ppMax, std::string _name);
        virtual ~Attack() = default;

        //Attack(const Attack& that);
        //Attack& operator=(const Attack& that);

        //getters
        //const double & getAttackDmg() const;
        

	virtual void attack(EntityCombat *caster, EntityCombat *target);

	const int getPPMax() const;
        const int getPPActual() const;
        const std::string & getName() const;

        bool canAttack();
        void decreasePP();
	
	virtual std::string attackMessage(EntityCombat *caster, EntityCombat *target) = 0;

};

#endif //__ATTACK_H__
