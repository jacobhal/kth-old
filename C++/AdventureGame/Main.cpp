//in main.cpp
#include "Headers/Character.h"
#include "Setting.h"
#include "Headers/Item.h"
#include "Headers/GameEngine.h"
#include "Equipment.h"


// Make header files later

// Items
#include "Scroll.h"
#include "Chest.h"
#include "Key.h"
#include "Map.h"
#include "Potion.h"

// Settings
#include "Ruins.h"
#include "Woods.h"
#include "Gurubashi.h"
#include "Orgrimmar.h"
#include "Icecrown.h"
#include "Onyxia.h"

// Characters
#include "Paladin.h"
#include "Priest.h"
#include "DeathKnight.h"
#include "Mage.h"
#include "Beast.h"


// Non-program includes
#include <time.h>
#include <limits>

using std::cout;
using std::cin;
using std::vector;
using std::string;

// Ubuntu/Linux/Mac color codes to spice things up
#define RESET   ""
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA ""      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     ""      /* Bold Red */
#define BOLDGREEN   ""      /* Bold Green */
#define BOLDYELLOW  ""      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



int main()
{
cout << "Welcome to World of Adrian, a boring MMO game, please choose what class you would like to play: \n";
cout << "(1) Priest" << "\n";
cout << "(2) Paladin" << "\n"; 
cout << "(3) DeathKnight" << "\n"; 

// Create new player

Character *player;

// Let player choose class
int c;
bool b = 0;
while (!b) {
    cin >> c;
    switch (c)
    {
        case 1:
        {
            cout << "You chose Priest! \n";
            player = new Priest("I'm a healer!", "Lars");
            b = 1;
            break;
        }
        case 2:
        {
            cout << "You chose Paladin! \n";
            player = new Paladin("I'm a tank!", "Olle");
            b = 1;
            break;
        }
        case 3:
        {
            cout << "You chose Death Knight! \n";
            player = new DeathKnight("I'm DPS", "Rutger");
            b = 1;
            break;
        }
        default:
        {
            cout << "That is not a valid choice. Try again." << "\n";
            cin.clear();
            // Ignore the rest of the line since it is wrong input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            b = 0;
            break;
        }
    }
}

// Let player choose weapon
cout << "Before your journey begins you must choose your weapon of choice: \n";
vector<Equipment*> weps = player->weapons();
for(int i = 0; i < weps.size(); ++i) {
    cout << "(" << i + 1 << ") " <<  *weps[i] << "\n";
}

cin >> c;
while (c > weps.size() || !cin) {
    cout << "That is not a valid choice. Try again." << "\n";
    cin.clear();
    // Ignore the rest of the line since it is wrong input
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> c;
}
    // Choice of weapon is always wise...
player->_weapon = weps[c-1];
cout << "You chose " << *weps[c-1] << ", a wise choice!\n";
cout << "Let the journey begin! Type help to see all available commands and call a specific command with " <<
        "the -h option to see a more detailed description of what it does.\n";

// Create characters & environment & items and start the game engine

// Create characters
Character *tyrael = new Paladin("The mighty paladin tyrael is here to aid you!", "Tyrael");
Character *jaina = new Mage("Jaina, the powerful mage stands before you and begins to cast a fireball!", "Jaina");
Character *lichKing = new DeathKnight("Lich King, a mighty foe stands in your way. Choose what to do, and quick!", "LichKing");
Character *benedictus = new Priest("The priest benedictus provides you with bandages!", "Benedictus");
Character *basilisk = new Beast("A hostile basilisk gets ready to attack.", "Beast");

// Create items
Item *key = new Key("key", "a key to unlock secret doors with");
Item *chest = new Chest("chest", "a chest with unknown content", key);
Item *scroll = new Scroll("scroll", "a scroll which can be used to teleport back to where you started");
Item *map = new Map("map", "a map to guide you through this adventure");
Item *potion = new Potion("potion", "a healing potion");

std::vector<Item*> items;
items.push_back(key);
items.push_back(chest);
items.push_back(scroll);
items.push_back(map);
items.push_back(potion);


// Add settings with optional characters items
Setting *ruins = new Ruins("Ruins", "The fearsome ruins where giants fought over 1000 years ago. Some say such creatures still exist.");
Setting *gurubashi = new Gurubashi("Gurubashi", "Gurubashi, the arena where champions have arised and fallen for many decades.");
Setting *icecrown = new Icecrown("Icecrown", "Icecrown, the chilling castle where Lich King rules.");
Setting *orgrimmar = new Orgrimmar("Orgrimmar", "Orgrimmar, the famous capital city of the Hordes. The leader Thrall might be found somewhere around.");
Setting *woods = new Woods("Woods", "The dark woods, infamous for its dark creatures lurking around.");
Setting *onyxia = new Onyxia("Onyxia's lair", "Onyxia's lair, the lair of the mighty dragon Onyxia");

// Setup routes (inverses too)
ruins->addRoute(icecrown, "north");
icecrown->addRoute(ruins, "south");

ruins->addRoute(gurubashi, "east");
gurubashi->addRoute(ruins, "west");

ruins->addRoute(orgrimmar, "south");
orgrimmar->addRoute(ruins, "north");

woods->addRoute(gurubashi, "east");
gurubashi->addRoute(woods, "west");

icecrown->addRoute(onyxia, "west");
onyxia->addRoute(icecrown, "east");

// Maybe add subsettings too?
int c1 = rand() % 4 + 1;
int c2 = rand() % 4 + 1;
int c3 = rand() % 4 + 1;
int c4 = rand() % 4 + 1;
int c5 = rand() % 4 + 1;

ruins->addCharacter(tyrael, c1);
gurubashi->addCharacter(jaina, c2);
icecrown->addCharacter(lichKing, c3);
orgrimmar->addCharacter(benedictus, c4);
woods->addCharacter(basilisk, c5);


// Player starting items
player->addItem(map);
player->addItem(potion);

// Setting items
int l1 = rand() % 4 + 1;
int l2 = rand() % 4 + 1;
int l3 = rand() % 4 + 1;
// 1: north 2: west 3: south 4: east
ruins->addItem(scroll, l1);
icecrown->addItem(chest, l2);
orgrimmar->addItem(key, l3);
// Idea is to use look to try and find specific items but using look also means risk to face hostile NPCs


// Start the game for player at specified area with these items
GameEngine *game = new GameEngine(orgrimmar, player, items);


// Prevent memory loss
delete game;
delete player;
delete tyrael;
delete jaina;
delete lichKing;
delete basilisk;
delete benedictus;
delete key;
delete chest;
delete scroll;
delete ruins;
delete gurubashi;
delete icecrown;
delete orgrimmar;
delete woods;

return 0;
}