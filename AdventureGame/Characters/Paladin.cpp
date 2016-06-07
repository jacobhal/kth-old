#include <iostream>
#include "Paladin.h"

using std::cout;

Paladin::Paladin() : Character("Paladin") {
}
Paladin::Paladin(std::string str) : Character("Paladin") {
	_attackPhrase = str;
	int power = 45;
	_stats = {100, 80, 50, power};
	_maxWeight = power*3;
}
Paladin::~Paladin() {
}
void Paladin::weakness(Character& src) {
	_stats.hp = 70;
}
std::vector<std::string> Paladin::weapons() {
	return {"Two-handed mace", "One-handed sword and shield"};
}

