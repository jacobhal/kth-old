//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_PRIEST_H
#define ADVENTUREGAME_PRIEST_H

#include "Character.h"

class Priest : public Character {

public:
    Priest();
    Priest(std::string str);
    ~Priest();
    void weakness(Character& src);
    std::vector<std::string> weapons();
};

#endif //ADVENTUREGAME_PRIEST_H
