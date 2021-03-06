#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"
#include "../state/Observable.h"
#include "../state/Observer.h"

#include <iostream>
#include <set>

class Ability;

class Unit : public Observable {
    protected:
        State* state;
        Ability* ability;
        std::set<Observer*> observers;
    public:
        Unit(const char* title, int hitPoints, int damage);
        virtual ~Unit();
        
        void ensureIsAlive();
        
        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        
        virtual void addHitPoints(int hp);
        void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        
        virtual void counterAttack(Unit* enemy);
        virtual void attack(Unit* enemy);
        
        void attach(Observer* observer) override;
        void notify() override;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
