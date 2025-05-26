#ifndef __ATTACK_H__
#define __ATTACK_H__

#include <iostream>

class Attack{
    protected:
        double attackDmg;
        int ppMax;
        int ppActual;
        std::string name;

    public:
        Attack(double _attackDmg, int _ppMax, std::string _name);
        virtual ~Attack() = default;

        Attack(const Attack& that);
        Attack& operator=(const Attack& that);

        //getters
        const double & getAttackDmg() const;
        const int getPPMax() const;
        const int getPPActual() const;
        const std::string & getName() const;

        bool canAttack();
        void decreasePP();


};

#endif //__ATTACK_H__
