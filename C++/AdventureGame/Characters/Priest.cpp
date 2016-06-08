#include <iostream>
#include "Priest.h"

using std::cout;

Priest::Priest() : Character("Priest") {
	int power = 30;
	_stats = {100, 50, 50, power};
	_maxWeight = power*3;
}
Priest::Priest(std::string str, std::string name) : Character("Priest", name) {
	_attackPhrase = str;
	int power = 30;
	_stats = {100, 50, 50, power};
	_maxWeight = power*3;
}
Priest::~Priest() {
}
float Priest::weakness(Character& src) {
	float modifier = 1;
	if(src.getClass() == "mage") {
		modifier = 0.3;
	}

	return modifier;
}
std::vector<Equipment*> Priest::weapons() {
	Equipment *staff = new Equipment("Staff", "A basic staff", 10, 20, 10);
	Equipment *daggeroh = new Equipment("One-handed dagger and off-hand", "A shitty dagger and some off-hand", 10, 10, 15);
	return {staff, daggeroh};
}

