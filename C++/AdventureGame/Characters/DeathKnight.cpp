#include <iostream>
#include "DeathKnight.h"

using std::cout;

DeathKnight::DeathKnight() : Character("Deathknight") {
	int power = 50;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
DeathKnight::DeathKnight(std::string str, std::string name) : Character("Deathknight", name) {
	_attackPhrase = str;
	int power = 50;
	_stats = {100, 70, 50, power};
	_maxWeight = power*3;
}
DeathKnight::~DeathKnight() {
}
float DeathKnight::weakness(Character& src) {
	float modifier = 1;
	if(src.getClass() == "mage") {
		modifier = 0.3;
	}

	return modifier;
}
std::vector<std::string> DeathKnight::weapons() {
	return {"Two-handed broadsword", "Two one-handed swords"};
}


