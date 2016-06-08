#include "Headers/GameEngine.h"
#include "Setting.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <regex>
#include <sstream>

#define RESET   ""
#define BOLDRED ""      /* Bold Red */
#define MAGENTA ""      /* Magenta */
#define BOLDYELLOW  ""      /* Bold Yellow */
#define BOLDGREEN   ""      /* Bold Green */
#include "Useable.h"
#include "Container.h"
using std::cout;

/* Helper functions */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    // read from steam ss to item until delimiter is found
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
// Create a new vector and split the given string
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

bool checkSize(std::vector<std::string> v, int size) {
	return v.size() == size;
}
void writeError(std::string msg, std::string format) {
	std::cout << format << msg << RESET << "\n";
}

/* ---------------- */

GameEngine::GameEngine(Setting *setting, Character *player, std::vector<Item*> items) {
	_items = items;
	_currentSetting = setting;
	_player = player;
	_player->setLocation(*setting);
	_isRunning = true;
	_availableCommands = {
		"go", 
		"help",
		"pick",
		"map",
		"attack",
	    "wave",
		"drop",
		"examine",
		"open",
		"use",
		"backpack",
		"look",
		"quit",
	};
	// Fill descriptions map
	_descriptions["go"] = "'go' can be used to navigate around the world. Possible directions are north, south, east or west. Check your map to see in which directions you can move.";
	_descriptions["help"] = "'help' lists all available commands.";
	_descriptions["pick"] = "'pick' picks up an item and adds it to your backpack if there is enough space. Example: pick map";
	_descriptions["map"] = "'map' checks in which directions you can currently move and describes your current position.";
	_descriptions["attack"] = "'attack' attacks other characters located in the same area.";
	_descriptions["wave"] = "'wave' greets other nearby character. Example: wave Thrall";
	_descriptions["drop"] = "'drop' drops a specified item from your backpack.";
	_descriptions["examine"] = "'examine' examines an item to reveal its purpose.";
	_descriptions["open"] = "'open' opens a container in your backpack.";
	_descriptions["use"] = "'use' uses an item in your backpack. Example: use key (if you are in a zone with a locked door)";
	_descriptions["backpack"] = "'backpack' checks the content of your backpack. That is if you are clever enough to keep it.";
	_descriptions["look"] = "'look' lets you check your surroundings to see if any items or NPCs are to be found. Possible directions are: north, south, east and west. Example: look west";
	_descriptions["quit"] = "'quit' ends the game.";
	
	_lookup["north"] = 1;
	_lookup["west"] = 2;
	_lookup["south"] = 3;
	_lookup["east"] = 4;
	// Run the game
	run();
}

void GameEngine::init() {
	// TODO: Make preparations
}
void GameEngine::run(){
	bool hasOption = 0;
	std::regex help("[a-zA-Z]* -h");
	init();
	while(_isRunning)
    {
        std::string command;
        // Do regex to see if option has been given
        cout << MAGENTA;
        std::getline(std::cin, command);
        if(regex_match(command, help)) {
        	hasOption = 1;
        } else {
        	hasOption = 0;
        }
        cout << RESET;
        if(!command.empty()) {
        	userCommand(command, hasOption);
        }
    }
}
void GameEngine::userCommand(std::string command, bool hasOption = 0){

	// Split the user command by space
	std::vector<std::string> userInput = split(command, ' ');
	command = userInput[0];
	std::string keyword = "";
	if(checkSize(userInput, 2)) {
		keyword = userInput[1];
	}

	if(command == "go") {
		if(hasOption) { 
			cout << _descriptions["go"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(_player->_location->hasRoute(keyword)) {
					auto it = _player->_location->move(_player, keyword);
					if(it != NULL) {
						_player->_location = it;
					}
					cout << BOLDYELLOW << "New location \n" << RESET << _player->_location->_description << "\n";
				} else {
					cout << "There's no route in that direction!\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "help") {
		if(hasOption) { 
			cout << _descriptions["help"] << "\n";
		} else {
			help();
		} 
	} else if (command == "pick") {
		if(hasOption) { 
			cout << _descriptions["pick"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(_player->_location->hasItem(keyword)) {
					_player->addItem(getItemByName(keyword));
					_player->_location->removeItem(getItemByName(keyword));
					cout << BOLDGREEN << "Picked up " << getItemByName(keyword)->_name << "\n";
				} else {
					cout << "That item is not to be found here!\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "map") {
		if(hasOption) { 
			cout << _descriptions["map"] << "\n";
		} else {
			if(checkSize(userInput, 1)) {
				if(_player->hasItem("map")) {
					cout << BOLDYELLOW << "Current position \n" << RESET;
					cout << _player->_location->_description << "\n";
					cout << BOLDYELLOW << "Available directions \n" << RESET;
					for(auto elem : _player->_location->getRoutes()) {
						cout << elem << "\n";
					}
				} else {
					cout << "You don't possess a map:(\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "attack") {
		if(hasOption) { 
			cout << _descriptions["attack"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(_player->_location->hasCharacter(keyword)) {
					if(_player->fight(*_player->_location->getCharacterByName(keyword))) {
						_player->_location->removeCharacter(_player->_location->getCharacterByName(keyword));
					} else {
						std::cout << "Game over..." << std::endl;
						_isRunning = false;
					}
				} else {
					writeError("Character does not exists in this zone (" + _player->_location->_name + ").", BOLDRED);
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "wave") {
		if(hasOption) { 
			cout << _descriptions["wave"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {

			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "drop") {
		if(hasOption) { 
			cout << _descriptions["drop"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(_player->hasItem(keyword)) {
					_player->removeItem(getItemByName(keyword));
					srand(time(NULL));
					int random = rand() % 4 + 1;
					_player->_location->addItem(getItemByName(keyword), random);
					cout << "You have dropped your " << keyword << "\n";
				} else {
					cout << "You can't drop something you don't have...\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "examine") {
		if(hasOption) { 
			cout << _descriptions["examine"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				std::cout << getItemByName(keyword)->_description << std::endl;
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "open") {
		if(hasOption) { 
			cout << _descriptions["open"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(Container* ptr = dynamic_cast<Container*>(getItemByName(keyword))) {
					_player->openItem(ptr);
				}

			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "use") {
		if(hasOption) {
			cout << _descriptions["use"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				if(_player->hasItem(keyword)) {
					if(Useable* ptr = dynamic_cast<Useable*>(getItemByName(keyword))) {
						_player->useItem(ptr);
					}
				} else {
					cout << "You don't have that item in your backpack!\n";
				}

			} else {
				writeError("Invalid format.", BOLDRED);
			}
		}
	} else if (command == "backpack") {
		if(hasOption) { 
			cout << _descriptions["backpack"] << "\n";
		} else {
			if(checkSize(userInput, 1)) {
				cout << BOLDYELLOW << "Items in backpack\n" << RESET;
				for(auto item : _player->_inventory) {
					cout << item->_name << "\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "look") {
		if(hasOption) { 
			cout << _descriptions["look"] << "\n";
		} else {
			if(checkSize(userInput, 2)) {
				// TODO: Check for characters too
				if(_player->_location->hasCharacter(_lookup[keyword])) {
					cout << _player->_location->getCharacterByPosition(_lookup[keyword])->_attackPhrase << "\n";
				}
				if(_player->_location->hasItem(_lookup[keyword])) {
					cout << "You found " << _player->_location->getItemByPosition(_lookup[keyword])->_description << "\n";
				} else {
					cout << "There is nothing to be found here.\n";
				}
			} else {
				writeError("Invalid format.", BOLDRED);
			}
		} 
	} else if (command == "quit") {
		if(hasOption) { 
			cout << _descriptions["quit"] << "\n";
		} else {
			cout << "Bye! See you soon!\n";
			_isRunning = false;
		}
	} else {
		cout << BOLDRED << "Unknown command.\n" << RESET;
	}
}
void GameEngine::help() {
	cout << "Available commands (some of them require certain items before they can be used): \n";
	for(auto command: _availableCommands) {
		cout << command << "\n";
	}
}
Item* GameEngine::getItemByName(std::string name) {
	auto it = std::find_if(_items.begin(), _items.end(), [&name] (const Item* p) -> bool { return p->_name == name; });

	if(it != _items.end()) {
		return *it;
	} else {
		return nullptr;
	}
}