#include <iostream>
#include "Beast.h"

using std::cout;

Beast::Beast() : Character("beast") {
}
Beast::Beast(std::string str) : Character("beast") {
	_attackPhrase = str;
	int power = 40;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
Beast::~Beast() {
}
void Beast::weakness(Character& src) {
	_stats.hp = 70;
}
std::vector<std::string> Beast::weapons() {
	return {};
}
