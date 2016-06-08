//
// Created by Adrian on 2016-06-08.
//
#include "Boss.h"

Boss::Boss(std::string name, std::string vl, std::string vld) : Character("Boss", name, vl){
    _voiceLineDeath = vld;
    _stats.hp = 200;
    _stats.strength = 30;
}

Boss::~Boss() {
    std::cout << getVoiceLineDeath() << std::endl;
    dropItems();
}

float Boss::weakness(Character &src) {
    return 1;
}

std::vector<Equipment*> Boss::weapons() {

}

