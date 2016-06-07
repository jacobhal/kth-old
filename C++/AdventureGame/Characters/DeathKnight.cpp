#include <iostream>
#include "DeathKnight.h"

using std::cout;

DeathKnight::DeathKnight() : Character("deathknight") {
}
DeathKnight::DeathKnight(std::string str) : Character("deathknight") {
	_attackPhrase = str;
	int power = 50;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
DeathKnight::~DeathKnight() {
}
void DeathKnight::weakness(Character& src) {
	_stats.hp = 70;
}
std::vector<std::string> DeathKnight::weapons() {
	return {"Two-handed broadsword", "Two one-handed swords"};
}


