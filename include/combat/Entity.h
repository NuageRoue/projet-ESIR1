#ifndef __EntityCombat_H__
#define __EntityCombat_H__

#include "Attack.h"
#include <graphics/texture/Texture.h>

#include <vector>

class EntityCombat {
    protected:
    double maxHP;
    double actualHP;
    unsigned int speed;
    unsigned int normalSpeed;
    std::vector<Attack*> attacks;
    std::string name;
    Texture *texture;


    unsigned int level;
    double buff;

    public:
    EntityCombat(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks, std::string _texturePath);
    virtual ~EntityCombat();

    //EntityCombat(const EntityCombat& that);
    //EntityCombat& operator=(const EntityCombat& that);

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

    //void attack(EntityCombat *target, Attack *attack);
};


#endif //__EntityCombat_H__
