#include <iostream>
#include "Paladin.h"

using std::cout;

Paladin::Paladin() : Character("Paladin") {
	int power = 45;
	_stats = {100, 80, 50, power};
	_maxWeight = power*3;
}
Paladin::Paladin(std::string str, std::string name) : Character("Paladin", name) {
	_attackPhrase = str;
	int power = 45;
	_stats = {100, 80, 50, power};
	_maxWeight = power*3;
}
Paladin::~Paladin() {
}
float Paladin::weakness(Character& src) {
	float modifier = 1;
	if(src.getClass() == "mage") {
		modifier = 0.3;
	}

	return modifier;
}
std::vector<std::string> Paladin::weapons() {
	return {"Two-handed mace", "One-handed sword and shield"};
}

