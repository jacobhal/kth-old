#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <string>
#include <vector>
#include <iostream>

#include "Item.h"
#include "Setting.h"

class Setting;

struct Stats {
	int hp;
	int weight;
	int height;
	int strength;
};

class Character {
public:
	
	Setting*                    _location;
    std::vector<Item*>          _inventory;
	Stats 						_stats;
	std::string					_attackPhrase;
	int 						_maxWeight;
	int 						_settingPosition;

	virtual ~Character(); // Even pure virtual destructors must be defined

	// Item methods
	/*
	bool hasItem(std::string name) const {
		if(std::find(inventory.begin(), inventory.end(), [&name] (const Item* p) -> bool { return p->name == name; })){
	    	return true;
		} else {
		 	return false;
		}
	};
	*/
	bool hasItem(std::string name) const;
	void addItem(Item *item);
	void removeItem(Item *item);
	// TODO Fixa
	Item* getItemByName(std::string n) const;

	// Setting methods
	Setting* currentArea() const;
	void setLocation(Setting & setting);

	virtual std::vector<std::string> weapons() =0;

	virtual void weakness(Character& src) =0; // Define the certain threats to a given class
protected:
	Character(std::string s) : _class(s) {};
private:
    const std::string _class;

};
#endif