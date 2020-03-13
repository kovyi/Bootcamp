#pragma once
#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../../ability/DefaultAbility.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const char* title, int hitPoints, int damage, int mana);
        virtual ~Wizard();
};

#endif // WIZARD_H
