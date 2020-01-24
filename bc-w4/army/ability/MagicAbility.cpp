#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner, Spell* spell) : owner(owner), spell(spell) {
    std::cout << "MagicAbility object initialized." << std::endl;
}

MagicAbility::~MagicAbility() {
    delete this->spell;
    std::cout << "MagicAbility object destroyed." << std::endl;
}

const Spell* MagicAbility::getSpell() const {
    return this->spell;
}

const char* MagicAbility::getSpellName() const {
    return this->spell->getSpellName();
}

void MagicAbility::changeSpell(Spell* newSpell) {
    delete this->spell;
    this->spell = newSpell;
}

void MagicAbility::cast(Unit* target) {
    this->owner->ensureIsAlive();
    
    this->spell->action(target);
    this->owner->spendMana(this->spell->getCost());
}

void MagicAbility::counterAttack(Unit* enemy) {
    int actionPoints = this->spell->getActionPoints();
    
    if ( this->owner->getMageType() == healer ) {
        actionPoints /= 2;
    }
    
    enemy->takeMagicDamage( actionPoints / 2);
    this->owner->spendMana(this->spell->getCost() / 2);
}
