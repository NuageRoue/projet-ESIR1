#include "combat/Player.h"
#include "combat/Enemy.h"

#include <iostream>
#include <cassert>

Player::Player(double _maxHP, unsigned int _speed, std::string _name, std::vector<Attack*> _attacks, std::vector<Item*> _items)
:Entity(_maxHP, _speed, _name, _attacks), items(_items)
{}

Player::~Player()
{
    for(int i = 0; i < items.size(); i++)
    {
        delete items[i];
    }
}

const std::vector<Item*> &Player::getItems() const
{
    return items;
}

Attack * Player::chooseAttack() const 
{
    std::cout << "Veuillez choisir le numéro d'une attaque parmi les attaques suivantes :\n";
    for(int i = 0; i<attacks.size(); i++)
    {
        if (attacks[i]->canAttack())
        {
            std::cout << i << " : " << attacks[i]->getName() << ", PP : " << attacks[i]->getPPActual() << std::endl;
        }
    }
    int attaqueChoisie;
    do
    {
        std::cin >> attaqueChoisie;
    } while (!attacks[attaqueChoisie]->canAttack());
    
    return attacks[attaqueChoisie];
}