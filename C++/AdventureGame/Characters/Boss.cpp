//
// Created by Adrian on 2016-06-08.
//
#include "Boss.h"

Boss::Boss(std::string name, std::string vl, std::string vld) : Character("Boss", name, vl){
    _voiceLineDeath = vld;
    _stats.hp = 200;
    _stats.maxhp = 200;
    _stats.strength = 30;
}

Boss::~Boss() {

}

void Boss::death() {
    std::cout << getVoiceLineDeath() << std::endl;
    dropItems();
}

std::string Boss::attack(Character & ch) {
    float modifier = weakness(ch);
    int damage = 0.5*(getStats().strength * modifier) * (rand() % 2 + 1);
    ch.getStats().hp - damage < 0 ? ch._stats.hp = 0 : ch._stats.hp -= damage;
    std::string txt = this->_name + " did " + std::to_string(damage) + " damage to " + ch._name + " who is now at " + std::to_string(ch.getStats().hp) + ".";
    return txt;
}

float Boss::weakness(Character &src) {
    return 1;
}

std::vector<Equipment> Boss::weapons() {

}

