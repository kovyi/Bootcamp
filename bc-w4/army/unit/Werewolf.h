#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

enum werewolfState { werewolf, wolf };

class Werewolf : public Unit {
    private:
        werewolfState currentState;
        int wolfExtraHp;
        int wolfExtraDmg;
    public:
        Werewolf(const char* title, int hitPoints, int damage);
        virtual ~Werewolf();
        
        virtual void takeMagicDamage(int dmg);
        void transform();
};

#endif //WEREWOLF_H