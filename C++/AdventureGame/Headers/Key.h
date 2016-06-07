//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_KEY_H
#define ADVENTUREGAME_KEY_H

#include "../Headers/Item.h"

class Key : public Item {
public:
    Key(std::string name, std::string description);
    ~Key();
    std::string open();
    std::string use();
};

#endif //ADVENTUREGAME_KEY_H
