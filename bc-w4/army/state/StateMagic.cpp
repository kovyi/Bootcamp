#include "StateMagic.h"

StateMagic::StateMagic(int mana) : mana(mana), manaLimit(mana) {
    std::cout << "StateMagic object initialized." << std::endl;
}

StateMagic::~StateMagic() {
    std::cout << "StateMagic object destroyed." << std::endl;
}

int StateMagic::getMana() const {
    return this->mana;
}

int StateMagic::getManaLimit() const {
    return this->manaLimit;
}

void StateMagic::addMana(int renewal) {
    int total = this->mana + renewal;
    
    if ( total > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = total;
}

void StateMagic::spendMana(int cost) {
    if ( cost > this->mana ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
}
