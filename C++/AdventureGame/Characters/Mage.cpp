#include <iostream>
#include "Mage.h"

using std::cout;

Mage::Mage() : Character("mage") {
}
Mage::Mage(std::string str) : Character("mage") {
	_attackPhrase = str;
	int power = 20;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
Mage::~Mage() {
}
void Mage::weakness(Character& src) {
	if(src.getClass() == "paladin") {
		_stats.strength = 10;
	}
	//_stats.hp = 70;
}
std::vector<std::string> Mage::weapons() {
	return {"Staff", "One-handed dagger and off-hand", "One-handed sword and off-hand"};
}

