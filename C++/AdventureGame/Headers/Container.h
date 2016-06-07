//
// Created by Jacob Hallman on 07/06/16.
//

#ifndef ADVENTUREGAME_CONTAINER_H
#define ADVENTUREGAME_CONTAINER_H

#include "Item.h"

class Container : public Item {
    virtual std::string open() =0;
};

#endif //ADVENTUREGAME_CONTAINER_H
