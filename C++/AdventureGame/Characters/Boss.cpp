//
// Created by Adrian on 2016-06-08.
//
#include "Boss.h"

Boss::Boss(std::string name, std::string vl, std::string vld) : Character("Boss", name, vl){
    _voiceLineDeath = vld;
}

Boss::~Boss() {
    dropItems();
}

float Boss::weakness(Character &src) {
    return 1;
}

void Boss::dropItems() {
    if(_inventory.size() > 0) {
        std::cout << _name << " dropped:" << std::endl;

        for (int i = 0; i < _inventory.size(); ++i) {
            _location->addItem(_inventory[i], _settingPosition);
            std::cout << _inventory[i]->_name << std::endl;
        }
    }
}
