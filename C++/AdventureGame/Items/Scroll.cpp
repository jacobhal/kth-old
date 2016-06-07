#include <iostream>
#include "Scroll.h"

using std::cout;

Scroll::Scroll(std::string name, std::string description) {
	this->_name = name;
	this->_description = description;
	this->_weight = 40;
}
Scroll::~Scroll() {
}
std::string Scroll::use() {
	return "";
}
