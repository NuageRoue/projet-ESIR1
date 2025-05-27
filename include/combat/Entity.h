#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Attack.h"

#include <vector>

class Entity {
    protected:
    double maxHP;
    double actualHP;
    unsigned int speed;
    unsigned int normalSpeed;
    std::vector<Attack*> attacks;
    std::string name;

    unsigned int level;
    double buff;

    public:
    Entity(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks);
    virtual ~Entity();

    //Entity(const Entity& that);
    //Entity& operator=(const Entity& that);

    const double & getMaxHP() const;
    const double & getActualHP() const;
    const unsigned int getSpeed() const;
	const unsigned int getLevel() const;
	const double getBuff() const;
	double &getBuff();
    const std::vector<Attack*> & getAttacks() const;
    const std::string & getName() const ;

    //virtual Attack * chooseAttack() const = 0;

    void decreaseHP(double dmg);

    //void attack(Entity *target, Attack *attack);
};


#endif //__ENTITY_H__
