//
// Created by Jacob Hallman on 07/06/16.
//

#ifndef ADVENTUREGAME_USEABLE_H
#define ADVENTUREGAME_USEABLE_H

#include "Item.h"

class Useable : public Item {
    virtual std::string use() =0;
};

#endif //ADVENTUREGAME_USEABLE_H
