#include <iostream>
#include "Paladin.h"

using std::cout;

Paladin::Paladin() : Character("Paladin") {
	int power = 45;
	_stats = {100, 80, 50, power};
	_maxWeight = power*3;
}
Paladin::Paladin(std::string str, std::string name) : Character("Paladin", name) {
	_attackPhrase = name + ": " + str;
	int power = 45;
	_stats = {100, 100, 80, 50, power};
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
std::vector<Equipment> Paladin::weapons() {
	Equipment twohmace("Two-handed mace", "A big ass 2h mace", 20, 20, 20);
	Equipment swordshield("One-handed sword and shield", "A basic sword and a shield", 18, 25, 15);
	return {twohmace, swordshield};
}

