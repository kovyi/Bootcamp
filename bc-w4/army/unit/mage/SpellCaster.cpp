#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana, TypeOfMage mageType)
    : Unit(title, hitPoints, damage),
        stateMagic(new StateMagic(mana)), mageType(mageType) {}

SpellCaster::~SpellCaster() {
    delete this->magicAbility;
    delete this->stateMagic;
}

int SpellCaster::getMana() const {
    return this->stateMagic->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->stateMagic->getManaLimit();
}

TypeOfMage SpellCaster::getMageType() const {
    return this->mageType;
}

const char* SpellCaster::getActiveSpellName() const {
    return this->magicAbility->getSpellName();
}

void SpellCaster::counterAttack(Unit* enemy) {
    if ( this->magicAbility->getSpell()->getSpellType() == attacking ) {
        this->magicAbility->counterAttack(enemy);
    } else {
        this->ability->counterAttack(enemy);
    }
}

void SpellCaster::addMana(int renewal) {
    this->stateMagic->addMana(renewal);
}

void SpellCaster::spendMana(int cost) {
    this->stateMagic->spendMana(cost);
}

void SpellCaster::changeSpell(const char* spellName) {
    std::map<std::string, Spell*>::iterator spellBookIt;
    spellBookIt = this->spellBook.find(spellName);
    
    if ( spellBookIt == spellBook.end() ) {
        throw NoSuchSpellException();
    }
    this->magicAbility->changeSpell(spellBookIt->second);
}

void SpellCaster::cast(Unit* target) {
    this->magicAbility->cast(target);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << spellCaster.getTitle() << ' ' << spellCaster.getHitPoints();
    out << '(' << spellCaster.getHitPointsLimit() << ')' << " HP/";
    out << spellCaster.getDamage() << " DMG/";
    out << spellCaster.getMana();
    out << '(' << spellCaster.getManaLimit() << ')' << " MANA";
}
