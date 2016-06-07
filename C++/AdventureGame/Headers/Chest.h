//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_CHEST_H
#define ADVENTUREGAME_CHEST_H

#include "../Headers/Item.h"

class Chest : public Item {
public:
    Chest(std::string name, std::string description);
    ~Chest();
    std::string open();
    std::string use();
};

#endif //ADVENTUREGAME_CHEST_H
