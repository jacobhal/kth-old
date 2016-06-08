#ifndef _ITEM_H
#define _ITEM_H
#include <string>
#include <vector>
#include <iostream>

class Item {
public:
	virtual ~Item() {};
	std::string _name;
	std::string _description;
	int _settingPosition;
	int _weight;
	friend bool operator== (const Item &i1, const Item &i2) { return i1._name == i2._name; }

	friend std::ostream& operator<<(std::ostream& os, const Item& it) {
		os << it._name << ": " << it._description;
		return os;
	}
};
#endif