//
// Created by Adrian on 2016-06-08.
//

#ifndef CPPLAB3_BOSS_H
#define CPPLAB3_BOSS_H
#include "Character.h"

class Boss : public Character {
protected:
    std::vector<Item*>  _lootTable;
    std::string         _voiceLineDeath;

public:
    Boss(std::string name, std::string vl, std::string vld);
    virtual ~Boss();

    float weakness(Character & src);
    void dropItems();

};

#endif //CPPLAB3_BOSS_H
