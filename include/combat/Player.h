#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include "Item.h"

#include <vector>

class Enemy;
class Attack;

class Player : public Entity{
    protected:
    double xp;
    unsigned int level;
    double levelCap;
    std::vector<Item*> items;

    public:
    Player(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks, std::vector<Item*> _items
    );
    virtual ~Player();

    const double & getXP() const;
    const unsigned int & getLevel() const;
    const double getLevelCap() const;
    const std::vector<Item*> & getItems() const;

    Attack * chooseAttack() const override;
    void increaseXP(double xp);
    void addItems(std::vector<Item*> itemsToAdd);

};

#endif //__PLAYER_H__