#include <iostream>
#include "Chest.h"

using std::cout;

Chest::Chest(std::string name, std::string description) {
	this->_name = name;
	this->_description = description;
	this->_weight = 40;
}
Chest::~Chest() {
}
std::string Chest::open() {
	return "";
}
