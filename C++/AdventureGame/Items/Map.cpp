#include <iostream>
#include "Map.h"
#include "Character.h"

using std::cout;

Map::Map(std::string name, std::string description) {
	this->_name = name;
	this->_description = description;
	this->_weight = 40;
}
Map::~Map() {
}
std::string Map::use(Character* c) {
	return "";
}
