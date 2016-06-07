#include <iostream>
#include "Priest.h"

using std::cout;

Priest::Priest() : Character("priest") {
}
Priest::Priest(std::string str) : Character("priest") {
	_attackPhrase = str;
	int power = 30;
	_stats = {100, 50, 50, power};
	_maxWeight = power*3;
}
Priest::~Priest() {
}
void Priest::weakness(Character& src) {
	_stats.hp = 70;
}
std::vector<std::string> Priest::weapons() {
	return {"Staff", "One-handed dagger and off-hand"};
}

