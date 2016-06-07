//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_MAGE_H
#define ADVENTUREGAME_MAGE_H

#include "Character.h"

class Mage : public Character {

public:
    Mage();
    Mage(std::string str);
    ~Mage();
    void weakness(Character& src);
    std::vector<std::string> weapons();
};

#endif //ADVENTUREGAME_MAGE_H
