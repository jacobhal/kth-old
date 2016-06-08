#include <iostream>
#include "Mage.h"

using std::cout;

Mage::Mage() : Character("Mage") {
	int power = 20;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
Mage::Mage(std::string str, std::string name) : Character("Mage", name) {
	_attackPhrase = str;
	int power = 20;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
Mage::~Mage() {
}
float Mage::weakness(Character& src) {
	float modifier = 1;
	if(src.getClass() == "mage") {
		modifier = 0.3;
	}

	return modifier;}
std::vector<std::string> Mage::weapons() {
	return {"Staff", "One-handed dagger and off-hand", "One-handed sword and off-hand"};
}

