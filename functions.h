//
// Created by Owen Morgan on 21/07/2024.
//

#ifndef EE1010GAMECOURSEWORK_FUNCTIONS_H
#define EE1010GAMECOURSEWORK_FUNCTIONS_H

#include "structs.h"

// Function prototypes to set up the game environment
bool gameStartMenu(bool &gameInProgress);
void resetMap();
player generatePlayers(int playerNo);
void generateInitialStats(player &playerToMod);
void generateMap();
bool playerTakeTurn(player &currentPlayer, int &turnNo, bool &gameInProgress);
void turnChangeover(player &currentPlayer, int turnNo);
void bannerBar(player &currentPlayer, int turnNo);
void searchAndCollectItems(area *currentArea, player &currentPlayer);
void move(area *currentArea, player *currentPlayer);
void equip(std::vector<equippableItem> &currentPlayerEquipment, player &currentPlayer);
void useItem(std::vector<useableItem> &currentPlayerItems, player &currentPlayer); //I'll need to find a way of deleting items.. if so update the area struct to have items deleted rather than removed as well
void encounter(player &currentPlayer, enemy &presentEnemy); // don't start till after founders/the hub?
void printUserInventory(std::vector<equippableItem> &currentPlayerEquipment, std::vector<useableItem> &currentPlayerItems);
void printUserStats(player &currentPlayer);
void setAreaCleared(player &currentPlayer);
void winString(player &currentPlayer);
void gameOver();
void clearScreen();
int getUserIntInput(int min, int max);
bool getUserYNInput();
void getAnyKeyContinue();
void pauseOutput(int time);


#endif //EE1010GAMECOURSEWORK_FUNCTIONS_H
