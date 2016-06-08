#include <iostream>
#include "Key.h"
#include "Character.h"

using std::cout;

Key::Key(std::string name, std::string description) {
	this->_name = name;
	this->_description = description;
	this->_weight = 40;
}
Key::~Key() {
}
std::string Key::use(Character *c) {
	c->_location->_isLocked = {0,0,0,0};
	return "";
}