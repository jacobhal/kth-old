#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <string>
#include <vector>
#include <iostream>

#include "Item.h"
#include "Setting.h"
#include "Useable.h"
#include "Container.h"

class Setting;
class Useable;
class Container;

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
	std::string					_voiceLine;
	std::string 				_name;

	virtual ~Character(); // Even pure virtual destructors must be defined

	std::string getClass() {
		return _class;
	}

	Stats getStats() {
		return _stats;
	}




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
	void useItem(Useable *item);
	void openItem(Container *item);
	// TODO Fixa
	Item* getItemByName(std::string n);

	// Setting methods
	Setting* currentArea() const;
	void setLocation(Setting & setting);

	// Character methods
	std::string talkTo(Character & ch) const;
	std::string attack(Character & ch);
	int fight(Character & ch);

	virtual std::vector<std::string> weapons() =0;

	virtual float weakness(Character& src) =0; // Define the certain threats to a given class
protected:
	Character(std::string s, std::string s2 = "noname", std::string s3 = "*shrug*") : _class(s), _name(s2), _voiceLine(s3) {};
private:
    const std::string _class;

};
#endif