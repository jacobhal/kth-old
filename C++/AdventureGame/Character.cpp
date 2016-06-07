//
// Created by Jacob Hallman on 05/06/16.
//

#include <string>
#include <vector>
#include <iostream>

#include "Item.h"
#include "Setting.h"
#include "Character.h"

class Setting;

Character::~Character() {}; // Even pure virtual destructors must be defined


// Item methods
/*
bool hasItem(std::string name) const {
    if(std::find(inventory.begin(), inventory.end(), [&name] (const Item* p) -> bool { return p->name == name; })){
        return true;
    } else {
         return false;
    }
};
*/
bool Character::hasItem(std::string name) const{
    for(int i = 0; i < _inventory.size(); ++i) {
        if(_inventory[i]->_name == name)
            return true;
    }
    return false;
}
void Character::addItem(Item *item) {
    if(!hasItem(item->_name)) {
        _inventory.push_back(item);
    }
}
void Character::removeItem(Item *item){
    _inventory.erase(std::remove(_inventory.begin(), _inventory.end(), item), _inventory.end());
}
// TODO Fixa
Item* Character::getItemByName(std::string n) const {
    auto it = std::find_if(_inventory.begin(), _inventory.end(), [&n] (const Item* p) -> bool { return p->_name == n; });

    if(it != _inventory.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

// Setting methods
Setting* Character::currentArea() const {
    return _location;
}
void Character::setLocation(Setting & setting) {
    _location = &setting;
}

