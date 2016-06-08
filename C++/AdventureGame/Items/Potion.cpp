//
// Created by Jacob Hallman on 07/06/16.
//

#include <iostream>
#include "Potion.h"
#include "Character.h"

using std::cout;

Potion::Potion(std::string name, std::string description) {
    this->_name = name;
    this->_description = description;
    this->_weight = 10;
}
Potion::~Potion() {
}
std::string Potion::use(Character* c) {
    int prehp = c->getStats().hp;
    c->_stats.hp + 50 > 100 ? c->_stats.hp = 100 : c->_stats.hp += 50;
    return "Healed for " + std::to_string(c->getStats().hp - prehp) + ".";
}

