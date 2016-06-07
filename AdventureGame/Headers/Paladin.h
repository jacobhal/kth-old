//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_PALADIN_H
#define ADVENTUREGAME_PALADIN_H

#include "Character.h"

class Paladin : public Character {

public:
    Paladin();
    Paladin(std::string str);
    ~Paladin();
    void weakness(Character& src);
    std::vector<std::string> weapons();
};

#endif //ADVENTUREGAME_PALADIN_H
