//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_CHEST_H
#define ADVENTUREGAME_CHEST_H

#include "Container.h"

class Chest : public Container {
public:
    Chest(std::string name, std::string description);
    ~Chest();
    std::string open();
};

#endif //ADVENTUREGAME_CHEST_H
