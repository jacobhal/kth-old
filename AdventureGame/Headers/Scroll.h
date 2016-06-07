//
// Created by Jacob Hallman on 05/06/16.
//

#ifndef ADVENTUREGAME_SCROLL_H
#define ADVENTUREGAME_SCROLL_H

#include "../Headers/Item.h"

class Scroll : public Item {
public:
    Scroll(std::string name, std::string description);
    ~Scroll();
    std::string open();
    std::string use();
};

#endif //ADVENTUREGAME_SCROLL_H
