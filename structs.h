//
// Created by Owen Morgan on 21/07/2024.
//

#ifndef EE1010GAMECOURSEWORK_STRUCTS_H
#define EE1010GAMECOURSEWORK_STRUCTS_H

#include <iostream>

// Note, most of these will be passed by references for safe altering without dealing with pointers
// However current area is a POINTER to the map area we are in, so this must be remembered when passing it to functions

// forward declaration to avoid dependency loops in other structs
struct area;

// Set structs for the 2 main item types
struct equippableItem {
    std::string name;
    int HPboost = 0;
    int attackBoost = 0;
    int defenceBoost = 0;
    std::string equipped = "N";
    std::string type;
};
struct useableItem {
    std::string name;
    int HPboost = 0;
    int attackBoost = 0;
    int defenceBoost = 0;
    bool specialItem = false; //some use able items will have single, specific action they perform
    std::string descriptor = "default";
};
// define struct for player
struct player
{
    int playerNumber = -1;
    std::string name;
    int maxHP = 0;
    int currentHP = 0;
    int attack = 0;
    int defence = 0;
    std::string weapon = "\033[1;31mnothing\033[0m"; //use these to get a callable name of currently equipped weapon
    std::string armour = "\033[1;31mnothing\033[0m";
    std::vector<equippableItem> equipment;
    std::vector<useableItem> items;
    area *currentArea;
    bool dead = true;
};

struct routes{
    area *connectingArea;
    std::string direction;
};
struct enemy {
    std::string name = "";
    int maxHP = 0;
    int currentHP = 0;
    int attack = 0;
    int defence = 0;
    std::string introText;
};
// define struct for area with vectors for items to be found and routes into and out of area
struct area
{
    std::string name;
    std::string P1descriptor;
    std::string P2descriptor;
    std::vector<routes> connectingAreas;
    std::vector<equippableItem> equippableItems;
    std::vector<useableItem> useableItems;
    bool searchable = true;
    bool p1cleared = false;
    bool p2cleared = false;
    enemy p1presentEnemy;
    enemy p2presentEnemy;

    // a function that can be called to add a route to the routes vector above, used in generate map
    // takes a pointer to the area the route references, and a string to describe the user that route
    void addRoute(area *location, const std::string direction){
        routes currentRoute;
        currentRoute.connectingArea = location;
        currentRoute.direction = direction;
        connectingAreas.push_back(currentRoute);
    }
};

#endif //EE1010GAMECOURSEWORK_STRUCTS_H
