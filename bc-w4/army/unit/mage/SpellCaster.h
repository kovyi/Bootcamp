#pragma once
#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include <map>
#include <string>

#include "../Unit.h"
#include "../../ability/DefaultAbility.h"
#include "../../state/StateMagic.h"
#include "../../ability/MagicAbility.h"
#include "../../spell/Spell.h"
#include "../../spell/HealFriend.h"
#include "../../spell/SurgeOfLightning.h"
#include "../../exceptions.h"

class MagicAbility;

enum TypeOfMage { healer, attacker };

class SpellCaster : public Unit {
    protected:
        StateMagic* stateMagic;
        MagicAbility* magicAbility;
        TypeOfMage mageType;
        std::map<std::string, Spell*> spellBook;
        std::map<std::string, Spell*>::iterator spellBookIt;
    public:
        SpellCaster(const char* title, int hitPoints, int damage, int mana, TypeOfMage mageType);
        virtual ~SpellCaster();
        
        int getMana() const;
        int getManaLimit() const;
        TypeOfMage getMageType() const;
        const char* getActiveSpellName() const;
        
        void addMana(int renewal);
        void spendMana(int cost);
        
        void changeSpell(const char* spellName);
        void cast(Unit* target);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif //SPELL_CASTER_H
