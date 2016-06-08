//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_BEAST_H
#define ADVENTUREGAME_BEAST_H

#include "Character.h"

class Beast : public Character {

public:
    Beast();
    Beast(std::string str, std::string);
    ~Beast();
    float weakness(Character& src);
    std::vector<std::string> weapons();
};

#endif //ADVENTUREGAME_BEAST_H
