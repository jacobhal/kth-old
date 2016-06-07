//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_MAP_H
#define ADVENTUREGAME_MAP_H

#include "../Headers/Item.h"

class Map : public Item {
public:
    Map(std::string name, std::string description);
    ~Map();
    std::string open();
    std::string use();
};

#endif //ADVENTUREGAME_MAP_H
