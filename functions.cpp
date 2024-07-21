//
// Created by Owen Morgan on 20/07/2024.
//

// The function file uses the custom struct, so we must include the definition, the definition is not fucntional code,
// so can just be an h file
#include "structs.h"
#include "functions.h"

#include <thread>
#include <iomanip> // Just for the inventory screen to set table widths


//define the rooms - I know this is global, it took days to get it working and I have no idea what's wrong with defining it in generateGameMap()
area studentsRoom; //0
area theChosenOnesRoom; //1
area foundersHall; //2
area pictureGallery; //3
area theLibrary; //4
area theWoods; //5
area theArtsBuilding; //6
area McCrea; //7
area moore; //8
area horton; //9
area tolansky; //10
area bedford; //11
area bourneLaboratory; //12
area shilling;//13
area queens;//14
area theSU;//15
area boilerhouse;//16
area theHub;//17

// FUNCTIONS FUNCTIONS FUNCTIONS FUNCTIONS

// Long function setting up the whole map, placing items and enemies and defining routes aroud
void generateMap(){

    // This large function makes all the game map and resets it too. It first defines all the enemies and items that can be
    // found, and then builds the map, Adding routes between areas using the structs 'addRoutes()' function
    // The whole map can be relatively easily defined here, and alterations to game difficulty and item/enemy layout easy to make
    // If you wanted to create another game from this code you would mainly alter here, plus flavour text
    // This very readable function designs the specifics (enemies, items, areas and stats) of the whole game.
    // Reset map would also need to reflect the new map if redesigning

    // create enemies and their stats
    enemy derangedBot;
    derangedBot.name = "Deranged Bot";
    derangedBot.maxHP = 45;
    derangedBot.currentHP = derangedBot.maxHP;
    derangedBot.attack = 6;
    derangedBot.defence = 5;
    derangedBot.introText = "A chat GPT bot stumbles up, it doesn't seem to know whats going on..";

    enemy googleBot;
    googleBot.name = "Google Bot";
    googleBot.maxHP = 60;
    googleBot.currentHP = googleBot.maxHP;
    googleBot.attack = 11;
    googleBot.defence = 10;
    googleBot.introText = "Uh Oh, looks like this one is the grandchild of the google ai chatbot!";

    enemy manicBot;
    manicBot.name = "Manic GPT Bot";
    manicBot.maxHP = 75;
    manicBot.currentHP = manicBot.maxHP;
    manicBot.attack = 14;
    manicBot.defence = 13;
    manicBot.introText = "This GPT bot is erratic and wildly flailing around, shouting out random facts!";

    enemy plusBot;
    plusBot.name = "Plus Bot";
    plusBot.maxHP = 120;
    plusBot.currentHP = plusBot.maxHP;
    plusBot.attack = 19;
    plusBot.defence = 23;
    plusBot.introText = "A bot is here, oh no, it looks like this one is the Premium version!";

    enemy blenderBot;
    blenderBot.name = "Blender Bot";
    blenderBot.maxHP = 200;
    blenderBot.currentHP = blenderBot.maxHP;
    blenderBot.attack = 25;
    blenderBot.defence = 25;
    blenderBot.introText = "You are attacked by a giant spider with the brain of Facebook's BlenderBot! Wait facebook makes it to 2054?";

    enemy cybertruck;
    cybertruck.name = "Cybertruck";
    cybertruck.maxHP = 260;
    cybertruck.currentHP = blenderBot.maxHP;
    cybertruck.attack = 40;
    cybertruck.defence = 40;
    cybertruck.introText = "Round the corner screeches an out of control cybertruck stuck on self drive mode!";

    // Create and fill each item struct with its parameters
    useableItem smolPotion;
    smolPotion.name = "smol potion";
    smolPotion.HPboost = 25;
    smolPotion.attackBoost = 0;
    smolPotion.defenceBoost = 0;
    smolPotion.specialItem = false;

    useableItem potion;
    potion.name = "potion";
    potion.HPboost = 75;
    potion.attackBoost = 0;
    potion.defenceBoost = 0;
    potion.specialItem = false;

    useableItem hiPotion;
    hiPotion.name = "hi-potion";
    hiPotion.HPboost = 125;
    hiPotion.attackBoost = 0;
    hiPotion.defenceBoost = 0;
    hiPotion.specialItem = false;

    useableItem espresso;
    espresso.name = "espresso shot";
//    espresso.HPboost;
    espresso.attackBoost = 4;
    espresso.defenceBoost = 4;
    espresso.specialItem = false;

    useableItem mysteryPotion;
    mysteryPotion.name = "mystery potion";
    mysteryPotion.HPboost = -25;
    mysteryPotion.attackBoost = 8;
    mysteryPotion.defenceBoost = 8;
    mysteryPotion.specialItem = false;

    // weapons and armour
    equippableItem oldTShirt;
    oldTShirt.name = "old T-Shirt";
    oldTShirt.HPboost = 0;
    oldTShirt.attackBoost = 1;
    oldTShirt.defenceBoost = 1;
    oldTShirt.type = "armour";

    equippableItem thickCoat;
    thickCoat.name = "thick coat";
    thickCoat.HPboost = 0;
    thickCoat.attackBoost = 0;
    thickCoat.defenceBoost = 4;
    thickCoat.type = "armour";

    equippableItem fireExtinguisher;
    fireExtinguisher.name = "fire extinguisher";
    fireExtinguisher.HPboost = 0;
    fireExtinguisher.attackBoost = 4;
    fireExtinguisher.defenceBoost = 2;
    fireExtinguisher.type = "weapon";

    equippableItem overdueLibraryBook;
    overdueLibraryBook.name = "overdue book";
    overdueLibraryBook.HPboost = 0;
    overdueLibraryBook.attackBoost = 2;
    overdueLibraryBook.defenceBoost = 2;
    overdueLibraryBook.type = "weapon";

    equippableItem mop;
    mop.name = "power mop";
    mop.HPboost = 0;
    mop.attackBoost = 5;
    mop.defenceBoost = 3;
    mop.type = "weapon";

    equippableItem toughBackpack;
    toughBackpack.name = "tough backpack";
    toughBackpack.HPboost = 0;
    toughBackpack.attackBoost = 0;
    toughBackpack.defenceBoost = 15;
    toughBackpack.type = "armour";

    equippableItem heatshrinkArmour;
    heatshrinkArmour.name = "heatshrink armour";
    heatshrinkArmour.HPboost = 0;
    heatshrinkArmour.attackBoost = 0;
    heatshrinkArmour.defenceBoost = 7;
    heatshrinkArmour.type = "armour";

    equippableItem drunkenArmour;
    drunkenArmour.name = "drunken armour";
    drunkenArmour.HPboost = 0;
    drunkenArmour.attackBoost = 0;
    drunkenArmour.defenceBoost = 18;
    drunkenArmour.type = "armour";

    equippableItem bearArmour;
    bearArmour.name = "bear armour";
    bearArmour.HPboost = 0;
    bearArmour.attackBoost = 0;
    bearArmour.defenceBoost = 12;
    bearArmour.type = "armour";

    equippableItem rockArmour;
    rockArmour.name = "rock armour";
    rockArmour.HPboost = 0;
    rockArmour.attackBoost = 0;
    rockArmour.defenceBoost = 20;
    rockArmour.type = "armour";

    equippableItem crockery;
    crockery.name = "crockery armour";
    crockery.HPboost = 0;
    crockery.attackBoost = 0;
    crockery.defenceBoost = 5;
    crockery.type = "armour";

    equippableItem shortSword;
    shortSword.name = "short sword";
    shortSword.HPboost = 0;
    shortSword.attackBoost = 10;
    shortSword.defenceBoost = 0;
    shortSword.type = "weapon";

    equippableItem reallyBigStick;
    reallyBigStick.name = "really big stick";
    reallyBigStick.HPboost = 0;
    reallyBigStick.attackBoost = 12;
    reallyBigStick.defenceBoost = 0;
    reallyBigStick.type = "weapon";

    equippableItem laserPointer;
    laserPointer.name = "laser pointer";
    laserPointer.HPboost = 0;
    laserPointer.attackBoost = 12;
    laserPointer.defenceBoost = 0;
    laserPointer.type = "weapon";

    equippableItem machineGun;
    machineGun.name = "machine gun";
    machineGun.HPboost = 0;
    machineGun.attackBoost = 16;
    machineGun.defenceBoost = 0;
    machineGun.type = "weapon";

    equippableItem bigRock;
    bigRock.name = "big rock";
    bigRock.HPboost = 0;
    bigRock.attackBoost = 13;
    bigRock.defenceBoost = 0;
    bigRock.type = "weapon";

    equippableItem smallRock;
    smallRock.name = "small rock";
    smallRock.HPboost = 0;
    smallRock.attackBoost = 10;
    smallRock.defenceBoost = 0;
    smallRock.type = "weapon";

    equippableItem smallerRock;
    smallerRock.name = "smaller rock";
    smallerRock.HPboost = 0;
    smallerRock.attackBoost = 5;
    smallerRock.defenceBoost = 0;
    smallerRock.type = "weapon";

    equippableItem pocketParticleAccelerator;
    pocketParticleAccelerator.name = "pocket accelerator";
    pocketParticleAccelerator.HPboost = 0;
    pocketParticleAccelerator.attackBoost = 23;
    pocketParticleAccelerator.defenceBoost = 0;
    pocketParticleAccelerator.type = "weapon";

    // Setup each room, adding the item and enemy structs to each area's vector of structs for these objects
    // Setup the studentsRoom
    studentsRoom.name = "Founders West bedroom";
    studentsRoom.P1descriptor = "You are in your bedroom, there's the computer, wardrobe and not a lot else! Still, there must be some useful stuff around for closing vortex's and things like that...";
    studentsRoom.P2descriptor = "This is just some grotty students bedroom...";
    studentsRoom.equippableItems.push_back(oldTShirt);
    studentsRoom.equippableItems.push_back(thickCoat);
    studentsRoom.useableItems.push_back(smolPotion);
//  p1 starting point, set as p1cleared initially, all other areas take default value 'false' by default in area struct
    studentsRoom.p1cleared = true;
//    studentsRoom.p1presentEnemy;
    studentsRoom.p2presentEnemy = blenderBot;
    studentsRoom.addRoute(&foundersHall, "Exit the room to main Founders Hall");

    //setup theChosenOnes room // Note add a message saying nah if player 1 tries to go in here
    theChosenOnesRoom.name = "Founders East bedroom";
    theChosenOnesRoom.P1descriptor = "This is Hal's room, he was wasted earlier tonight...";
    theChosenOnesRoom.P2descriptor = "This...is...it...";
//    theChosenOnesRoom.equippableItems;
//    theChosenOnesRoom.useableItems;
//    theChosenOnesRoom.p1presentEnemy;
//    theChosenOnesRoom.p2presentEnemy;
    theChosenOnesRoom.addRoute(&foundersHall, "Leave the bedroom back to Founders");

    // setup foundersHall
    foundersHall.name = "Founders Hall";
    foundersHall.P1descriptor = "The corridors are echoing and ominous... From here you can explore founders or head to the main campus...";
    foundersHall.P2descriptor = "The target is around here somewhere...";
    foundersHall.equippableItems.push_back(overdueLibraryBook);
//    foundersHall.useableItems;
//    foundersHall.p1presentEnemy;
    foundersHall.p2presentEnemy = cybertruck;
    foundersHall.addRoute(&studentsRoom, "Go to the Founders West bedroom");
    foundersHall.addRoute(&pictureGallery, "Go to the Picture Gallery");
    foundersHall.addRoute(&theLibrary, "Go to the library");
    foundersHall.addRoute(&theWoods, "Dare you go into the woods?");
    foundersHall.addRoute(&theChosenOnesRoom, "Go to the Founders East bedroom"); // find a way for this to appear different to elon

    // setup thePictureGallery
    pictureGallery.name = "The Picture Gallery";
    pictureGallery.P1descriptor = "The polar bear painting looks at you.. it's eyes follow you across the room..";
    pictureGallery.P2descriptor = "This place has far to much art for my liking, apart from that cheery polar bear painting..";
    pictureGallery.equippableItems.push_back(bearArmour);
//    pictureGallery.useableItems;
    pictureGallery.p1presentEnemy = derangedBot;
    pictureGallery.p2presentEnemy = plusBot;
    pictureGallery.addRoute(&foundersHall, "Head back to the front of Founders Hall");

    // setup the library
    theLibrary.name = "The Library";
    theLibrary.P1descriptor = "The wails of GPT bots echo about it's walls... Head to the centre of campus or back to Founders?";
    theLibrary.P2descriptor = "I could use this place as the office of a new business perhaps..";
    theLibrary.equippableItems.push_back(mop);
    theLibrary.useableItems.push_back(espresso);
    theLibrary.p1presentEnemy = googleBot;
    theLibrary.p2presentEnemy = plusBot;
    theLibrary.addRoute(&foundersHall, "Go to Founders");
    theLibrary.addRoute(&theArtsBuilding, "Head on to the Arts building.");
    theLibrary.addRoute(&bedford, "Take the side path down to Bedford.");

    //setup the arts building
    theArtsBuilding.name = "The Arts Building";
    theArtsBuilding.P1descriptor = "The maze of corridors winds around you, just where IS LT2?";
    theArtsBuilding.P2descriptor = "...just which floor AM I on?";
    theArtsBuilding.equippableItems.push_back(shortSword);
    theArtsBuilding.useableItems.push_back(smolPotion);
    theArtsBuilding.p1presentEnemy = manicBot;
    theArtsBuilding.p2presentEnemy = plusBot;
    theArtsBuilding.addRoute(&theLibrary, "Head to the library");
    theArtsBuilding.addRoute(&moore, "Head to the Moore");
    theArtsBuilding.addRoute(&McCrea, "Slip across to McCrea");
    theArtsBuilding.addRoute(&bedford, "Go out the side door to Bedford");

    //setup mccrea
    McCrea.name = "McCrea";
    McCrea.P1descriptor = "Ah, the school of law and Social science, this place confuses me..";
    McCrea.P2descriptor = "An angular glass building...";
    McCrea.equippableItems.push_back(laserPointer);
    McCrea.useableItems.push_back(mysteryPotion);
//    McCrea.p1presentEnemy;
//    McCrea.p2presentEnemy;
    McCrea.addRoute(&theArtsBuilding, "Head to the Arts building");
    McCrea.addRoute(&moore, "Head across the street to the Moore building");
    McCrea.addRoute(&horton, "Slip across to the Horton building");
    McCrea.addRoute(&bedford, "Head to Bedford to see Teepee");

    //setup moore
    moore.name = "The Moore Building";
    moore.P1descriptor = "I've never been in HERE before...";
    moore.P2descriptor = "A colourful building that looks something to do with buisiness.";
//    moore.equippableItems;
    moore.useableItems.push_back(potion);
    moore.p1presentEnemy = plusBot;
//    moore.p2presentEnemy;
    moore.addRoute(&theArtsBuilding, "Head to the Arts building");
    moore.addRoute(&boilerhouse, "Head down the hill to the Boilerhouse");
    moore.addRoute(&horton, "Head to the Horton");
    moore.addRoute(&McCrea, "Head to the McCrea building");

    // setup Bedford
    bedford.name = "The Bedford Building";
    bedford.P1descriptor = "A modern building that smells like the inside of old computers... Teepee is here.";
    bedford.P2descriptor = "A modern building that smells like the inside of old computers..";
//    bedford.equippableItems;
    bedford.useableItems.push_back(hiPotion);
    bedford.p1presentEnemy = googleBot;
    bedford.p2presentEnemy = plusBot;
    bedford.addRoute(&theArtsBuilding, "Head to the Arts building");
    bedford.addRoute(&theLibrary, "Head to the Library");
    bedford.addRoute(&horton, "Head to the Horton");
    bedford.addRoute(&McCrea, "Head to the McCrea building");
    bedford.addRoute(&bourneLaboratory, "Head to the Bourne Laboratory");
    bedford.addRoute(&theWoods, "Go out the back to the woods if you dare!");

    //setup horton
    horton.name = "The Horton Building";
    horton.P1descriptor = "This building smells of economics and maths...";
    horton.P2descriptor = "This building smells of money!!";
    horton.equippableItems.push_back(toughBackpack);
    horton.useableItems.push_back(potion);
    horton.p1presentEnemy = plusBot;
    horton.p2presentEnemy = googleBot;
    horton.addRoute(&moore, "Head to the Moore building");
    horton.addRoute(&boilerhouse, "Head to the Boilerhouse");
    horton.addRoute(&bedford, "Head to Bedford");
    horton.addRoute(&McCrea, "Head to the McCrea building");
    horton.addRoute(&tolansky, "Head to the Tolansky lab");

    //setup tolansky
    tolansky.name = "The Tolansky Lab";
    tolansky.P1descriptor = "There's gonna be some sweet physics equipment here!";
    tolansky.P2descriptor = "Hmm, I should collect some of this for SpaceX on the way back..";
    tolansky.equippableItems.push_back(pocketParticleAccelerator);
    tolansky.useableItems.push_back(smolPotion);
    tolansky.p1presentEnemy = plusBot;
    tolansky.p2presentEnemy = manicBot;
    tolansky.addRoute(&horton, "Head to the Horton building");
    tolansky.addRoute(&bourneLaboratory, "Head to the Bourne Laboratory");
    tolansky.addRoute(&theSU, "Head to the SU");

    //setup Boilerhouse
    boilerhouse.name = "The Boilerhouse";
    boilerhouse.P1descriptor = "The Boilerhouse serves sweet coffee, I could use one to be honest..";
    boilerhouse.P2descriptor = "This place is making me want to go vegan again!";
//    boilerhouse.equippableItems;
    boilerhouse.useableItems.push_back(hiPotion);
    boilerhouse.useableItems.push_back(espresso);
//    boilerhouse.p1presentEnemy;
//    boilerhouse.p2presentEnemy;
    boilerhouse.addRoute(&moore, "Head up the hill to the Moore building");
    boilerhouse.addRoute(&horton, "Head to the Horton Laboratory");
    boilerhouse.addRoute(&theSU, "Head to the SU");

    //setup theSU
    theSU.name = "The SU";
    theSU.P1descriptor = "The SU is still really busy, I guess no-one cares about random vortex's....";
    theSU.P2descriptor = "Students, not the one I need though.. they're listening to Grimes...";
    theSU.equippableItems.push_back(drunkenArmour);
    theSU.useableItems.push_back(potion);
    theSU.p1presentEnemy = googleBot;
    theSU.p2presentEnemy = googleBot;
    theSU.addRoute(&boilerhouse, "Head to the Boilerhouse");
    theSU.addRoute(&tolansky, "Head to the Tolansky Lab");
    theSU.addRoute(&queens, "Head to the Queens Building");

    //setup queens
    queens.name = "the Queens Building";
    queens.P1descriptor = "Might find some useful rocks here...";
    queens.P2descriptor = "Might find some useful rocks here...";
    queens.equippableItems.push_back(bigRock);
    queens.equippableItems.push_back(smallRock);
    queens.equippableItems.push_back(smallerRock);
    queens.equippableItems.push_back(rockArmour);
//    queens.useableItems;
//    queens.p1presentEnemy;
//    queens.p2presentEnemy;
    queens.addRoute(&theSU, "Head to the SU");
    queens.addRoute(&bourneLaboratory, "Go up to the Bourne Laboratory");
    queens.addRoute(&shilling, "Head on to ..... Shilling");

    //the Bourne Lab
    bourneLaboratory.name = "The Bourne Laboratory";
    bourneLaboratory.P1descriptor = "There'll be loads of great stuff here..";
    bourneLaboratory.P2descriptor = "Brutalist, I like it..";
    bourneLaboratory.equippableItems.push_back(machineGun);
    bourneLaboratory.useableItems.push_back(potion);
    bourneLaboratory.useableItems.push_back(mysteryPotion);
    bourneLaboratory.p1presentEnemy = blenderBot;
    bourneLaboratory.p2presentEnemy = derangedBot;
    bourneLaboratory.addRoute(&tolansky, "Head to the Tolansky Lab");
    bourneLaboratory.addRoute(&bedford, "Head to see Teepee in Bedford");
    bourneLaboratory.addRoute(&shilling, "Head down to ..... Shilling");
    bourneLaboratory.addRoute(&queens, "Head to the Queens building");

    //setup Shilling
    shilling.name = "Shilling";
    shilling.P1descriptor = "You made it!"; // on getting here, trigger story for p1
    shilling.P2descriptor = "Man, If only I was as student again, I'd spend all my time here..."; // on getting here, trigger story for p1
    shilling.equippableItems.push_back(heatshrinkArmour);
    shilling.useableItems.push_back(potion);
    shilling.p1presentEnemy = cybertruck;
//    shilling.p2presentEnemy;
    shilling.addRoute(&bourneLaboratory, "Head up to the Bourne Laboratory");
    shilling.addRoute(&queens, "Head along the road to the Queens Building");
    shilling.addRoute(&theHub, "Go down to the hub");

    //Setup The Woods
    theWoods.name = "The Woods";
    theWoods.P1descriptor = "Its dark and there are lots ...sounds... does Surrey have wolves?";
    theWoods.P2descriptor = "The giant Founders building looms overhead, that's my target ";
    theWoods.equippableItems.push_back(reallyBigStick);
//    theWoods.useableItems;
    theWoods.p1presentEnemy = blenderBot;
    theWoods.p2presentEnemy = blenderBot;
    theWoods.addRoute(&foundersHall, "Head out of the woods to Founders");
    theWoods.addRoute(&bedford, "Take the shorcut to Bedford");
    theWoods.addRoute(&theHub, "Head to the Hub....");

    //Setup The Hub
    theHub.name = "the Hub";
    theHub.P1descriptor = "It's not safe here, theres a fricken vortex right overhead...";
    theHub.P2descriptor = "I need to get to the Founders Building and eliminate the chosen one...";
    theHub.equippableItems.push_back(crockery);
    theHub.useableItems.push_back(smolPotion);
    //  p1 starting point, set as p2cleared initially, the rest will default to false
    theHub.p2cleared = true;
    theHub.p1presentEnemy = blenderBot;
//    theHub.p2presentEnemy;
    theHub.addRoute(&theWoods, "...dare you go into to the Woods??");
    theHub.addRoute(&shilling, "Head to Shilling");
}


// Used to start a new game when one is already in process, just resets relevant parameters
void resetMap()
{
    studentsRoom.searchable = true;
    theChosenOnesRoom.searchable = true;
    foundersHall.searchable = true;
    pictureGallery.searchable = true;
    theLibrary.searchable = true;
    theWoods.searchable = true;
    theArtsBuilding.searchable = true;
    McCrea.searchable = true;
    moore.searchable = true;
    horton.searchable = true;
    tolansky.searchable = true;
    bedford.searchable = true;
    bourneLaboratory.searchable = true;
    shilling.searchable = true;
    queens.searchable = true;
    theSU.searchable = true;
    boilerhouse.searchable = true;
    theHub.searchable = true;

    studentsRoom.p1cleared = true; // Note p1 starting location
    theChosenOnesRoom.p1cleared = false;
    foundersHall.p1cleared = false;
    pictureGallery.p1cleared = false;
    theLibrary.p1cleared = false;
    theWoods.p1cleared = false;
    theArtsBuilding.p1cleared = false;
    McCrea.p1cleared = false;
    moore.p1cleared = false;
    horton.p1cleared = false;
    tolansky.p1cleared = false;
    bedford.p1cleared = false;
    bourneLaboratory.p1cleared = false;
    shilling.p1cleared = false;
    queens.p1cleared = false;
    theSU.p1cleared = false;
    boilerhouse.p1cleared = false;
    theHub.p1cleared = false;

    studentsRoom.p2cleared = false;
    theChosenOnesRoom.p2cleared = false;
    foundersHall.p2cleared = false;
    pictureGallery.p2cleared = false;
    theLibrary.p2cleared = false;
    theWoods.p2cleared = false;
    theArtsBuilding.p2cleared = false;
    McCrea.p2cleared = false;
    moore.p2cleared = false;
    horton.p2cleared = false;
    tolansky.p2cleared = false;
    bedford.p2cleared = false;
    bourneLaboratory.p2cleared = false;
    shilling.p2cleared = false;
    queens.p2cleared = false;
    theSU.p2cleared = false;
    boilerhouse.p2cleared = false;
    theHub.p2cleared = true; // Note, p2 starting location



}

// display the top menu
bool gameStartMenu(bool &gameInProgress) {

    int userChoice;
    // bool to say continue game, user hasn't asked for newgame
    bool cont = true;

    clearScreen();

    // if there's not a game running display title screen
    if(!gameInProgress)
    {
        std::cout <<
                  "    _/    _/            _/  _/                                                    _/_/    _/_/_/\n"
                  "   _/    _/    _/_/    _/  _/    _/_/    _/      _/      _/                    _/    _/    _/\n"
                  "  _/_/_/_/  _/    _/  _/  _/  _/    _/  _/      _/      _/     _/_/_/_/_/     _/_/_/_/    _/\n"
                  " _/    _/  _/    _/  _/  _/  _/    _/    _/  _/  _/  _/                      _/    _/    _/\n"
                  "_/    _/    _/_/    _/  _/    _/_/        _/      _/                        _/    _/  _/_/_/\n\n"

                ;

        std::cout << "Welcome to Hollow-AI!\n\n" << "A RPG game for 1 or 2 players\n\n";

        std::cout << "What would you like to do?\n\n";

        std::cout << "______________________\n";
        std::cout << "1 - New Game\n"
                     "2 - Instructions\n"
                     "3 - Quit\n";
        std::cout << "______________________\n\n";
        userChoice = getUserIntInput(1, 3);
    }
        // if there IS a game running provide a different menu
    else
    {
        std::cout << "______________________\n";
        std::cout << "1 - Main Menu\n"
                     "2 - Instructions\n"
                     "3 - Quit\n\n";
        std::cout << "4 - Continue Game\n";
        std::cout << "______________________\n\n";
        userChoice = getUserIntInput(1, 4);
    }

    switch (userChoice)
    {

        case 1: // New game on main menu, or return to main menu in the game menu

            // if a game is in progress print a warning
            if (gameInProgress == true)
            {
                std::cout << "If you go to the main menu you will loose any progress in your current game...\n\n";
                std::cout << "Really exit to main menu?\n\n";
                bool startNewGame = getUserYNInput();
                if (startNewGame)
                {
                    // reset to say no game in progress and exit out of functions to restart
                    gameInProgress = false;
                    cont = false;
                    return cont;
                }
                return cont;
            }
            // if not, set the gameInProgress status to true and return from the menu
            gameInProgress = true;
            return cont;

        case 2:

            // print instruction screen
            std::cout << "________________________________________________________________________\n\n";
            std::cout << "Instructions:\n\n"
                         "Hollow-AI is a text based RPG game for one or two players. In one player\n"
                         "mode you play a student at RHUL aiming to get to the Shilling building.\n"
                         "In two player mode the second player is Elon Musk, aiming to make his way\n"
                         "to founders building.\n\n"
                         ""
                         "Gameplay progresses turn by turn, with player one taking the first turn.\n"
                         "Players can take a series of actions each turn, usually searching the\n"
                         "local area for items, equipping or using those items then moving on to an\n"
                         "adjoining area. Normally moving is that last action of a players turn,\n"
                         "however if there is an enemy present in the area the player moves too,\n"
                         "you must fight it!\n\n"
                         ""
                         "After movement, and the ensuing battle if an enemy is present, gameplay\n"
                         "passes to the other player. Gameplay progresses until;\n\n"
                         ""
                         "- Both players are dead..\n"
                         "- One of the players have reached the final destination and won the game.\n\n"
                         ""
                         "Tips - the enemies increase in difficulty as the game progresses, make\n"
                         "sure you explore side areas and search and equip items. Many of the later\n"
                         "enemies in the game will not be defeatable without finding some of the\n"
                         "better items along the way. Take detours to find more stuff! Make sure\n"
                         "you use potions to keep health up, or you will need to waste turns by using\n"
                         "them in battle!\n\n"
                         ""
                         "Note, in this beta version of the game you will ALWAYS be able to escape by\n"
                         "running with 100% success rate. This is to allow debugging and testing of\n"
                         "the game quickly without worrying about accruing the best equipment etc,\n"
                         "please use this to your advantage when testing game features!\n";
            std::cout << "________________________________________________________________________\n\n";
            std::cout << "Finished?\n";

            getUserYNInput();
            gameStartMenu(gameInProgress);
            return cont;

        case 3:
            // Quit application, with warning if there is a game in progress that will be lost
            while(gameInProgress)
            {
                std::cout << "Really Quit? You will loose any unsaved progress...\n";
                if(!getUserYNInput())
                {
                    return cont;
                }
                else
                {
                    gameInProgress = false;
                }
            }
            exit(0);

        case 4: // continue game

            return cont;

    }
}

// Used to set up the one or two players, and get p1 name
player generatePlayers(int playerNo){

    // struct object of the player being generated
    player generatedPlayer;
    // enumerate the player, and set them to alive (default is dead which allows for easy one player mode setup)
    generatedPlayer.playerNumber = playerNo;
    generatedPlayer.dead = false;

    // Get name and set area of starting for p1.
    if(playerNo == 1)
    {
        std::string characterName;
        bool userConfirm;

        // get P1 name with error checking
        do
        {
            std::cout << "P1, please input the name of your character, max 12 characters: "; //comment this back once ready for user input
            std::cin.clear(); // get rid of any error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush cin in case it holds junk characters
            getline(std::cin, characterName);

            if(characterName.length() > 12)
            {
                std::cout << "Name is too long, please use less that 12 characters..\n\n";
                continue;
            }
            std::cout << "You input: " << characterName << "\n\n";
            std::cout << "Confirm? ";
            userConfirm = getUserYNInput();
        }
        while(!userConfirm || characterName.length()>12);

        generatedPlayer.name = characterName;
        generatedPlayer.currentArea = &studentsRoom;
    }
        // Set name to Elon and set area of starting for p2
    else if(playerNo == 2)
    {
        generatedPlayer.name = "Elon";
        generatedPlayer.currentArea = &theHub;
    }

    // Randomise all other player stats, apply them to the player struct and return the player to the gamespace.
    generateInitialStats(generatedPlayer);

    return generatedPlayer;

}

// Once to randomly generate starting stats for players, called from function directly above
void generateInitialStats(player &playerToMod){

    // uses srand to generate initial stats for each player in the game, runs early in main
    playerToMod.maxHP = ((rand() % 50) + 125);
    playerToMod.currentHP = playerToMod.maxHP;
    playerToMod.attack = (rand() % 7) + 7;
    playerToMod.defence = (rand() % 8) + 7;
}



// Display the turn menu, this is the main function by which the game is played and calls all the sub functions below
bool playerTakeTurn(player &currentPlayer, int &turnNo, bool &gameInProgress){

    // This is the main function for advancing the game
    int userChoice = -1;
    // This bool is only used for if the user wants to quite THIS game and start another, continue can't be used as it's reserved
    bool continuu = true;

    while(true)
    {

        // print the top bar to the game screen
        bannerBar(currentPlayer, turnNo);

        std::cout << "______________________\n";
        std::cout << "1 - Move on\n"
                     "2 - Search\n"
                     "3 - Inventory, Stats & Equip\n"
                     "4 - Use Item\n"
                     "5 - Options\n";
        std::cout << "______________________\n";

        userChoice = getUserIntInput(1, 5);

        switch (userChoice)
        {
            case 1:
                move(currentPlayer.currentArea, &currentPlayer); //note current area is stored as a pointer in player struct, no need to use address-of
                // if an enemy is present on the map area moved to, do the encounter, if there is no enemy this sets the area cleared of enemies
                // This allows for adding enemies to the map easily
                if (currentPlayer.playerNumber == 1)
                {
                    encounter(currentPlayer, currentPlayer.currentArea->p1presentEnemy);
                } else if (currentPlayer.playerNumber == 2)
                {
                    encounter(currentPlayer, currentPlayer.currentArea->p2presentEnemy);
                }

                // check to see if a player has won
                // if player has won print the win screen and set this game as over
                if (currentPlayer.playerNumber == 1 && currentPlayer.currentArea->name == "Shilling")
                {
                    clearScreen();
                    bannerBar(currentPlayer, turnNo);
                    if(currentPlayer.currentHP != 0)
                    {
                        winString(currentPlayer);
                    }
                    continuu = false;
                    return continuu;
                }
                if (currentPlayer.playerNumber == 2 && currentPlayer.currentArea->name == "Founders East bedroom")
                {
                    clearScreen();
                    bannerBar(currentPlayer, turnNo);
                    if(currentPlayer.currentHP != 0)
                    {
                        winString(currentPlayer);
                    }
                    continuu = false;
                    return continuu;
                }

                else
                {
                    // else continue the game
                    return continuu;
                }


            case 2:
                searchAndCollectItems(currentPlayer.currentArea, currentPlayer);
                break;

            case 3:
                clearScreen();
                printUserStats(currentPlayer);
                printUserInventory(currentPlayer.equipment, currentPlayer.items);
                if(currentPlayer.equipment.size()==0)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getAnyKeyContinue();
                    break;
                }
                else
                {
                    while (currentPlayer.equipment.size() != 0)
                    {
                        std::cout << "Equip something?\n";
                        while (getUserYNInput())
                        {
                            equip(currentPlayer.equipment, currentPlayer);
                            printUserStats(currentPlayer);
                            printUserInventory(currentPlayer.equipment, currentPlayer.items);
                            std::cout << "Equip something?\n";
                        }
                        break;
                    }
                    break;
                }

            case 4:
                useItem(currentPlayer.items, currentPlayer);
                break;

            case 5:
                // reset because this function can be flagged true to start the game from the begging again
                continuu = gameStartMenu(gameInProgress);
                // if the user has asked to quit to new came exit this turn directly to the main function reporting as such
                if(continuu == false)
                {
                    return continuu;
                }
                break;

                // not really needed but to catch bugs
            default:
                std::cout << "Not a valid selection";

        }

    }

}

// A quick function that displays the initial story and creates a pause between turns so they dont flash by
// Also gives a chance for p1 and p2 to switch control
void turnChangeover(player &currentPlayer, int turnNo){

    clearScreen();
    std::cout << std::left << currentPlayer.name << " " << currentPlayer.currentHP
              << "/" << currentPlayer.maxHP << std::setw(12) << " HP" << " Turn "
              << std::setw(12) << turnNo << currentPlayer.currentArea->name <<  "\n";
    std::cout << "________________________________________________________________________\n\n";

    if(turnNo == 1)
    {
        std::cout << "A portal has opened in RHUL!\n\n"

                     "Deep in the night of 31st October 2024 a portal to the distant future\n"
                     "opens up above the Hub. From it comes scores of Robots from the year\n"
                     "2053, conveniently all called ChatGPT 12.4.\n\n"

                     "However luckily for humanity the campus connect internet isn’t strong\n"
                     "enough for these robots to think clearly, and they all go mad on arrival,\n"
                     "dispersing into the various buildings gibbering randomly with confident\n"
                     "yet inaccurate dialog.\n\n";
    }

    if(currentPlayer.playerNumber == 1 && turnNo == 1)
    {
        std::cout << "You are " << currentPlayer.name
                  << ", a plucky EE first year who is disturbed from their\n"
                     "nightly derision of magnitude functions by a great portal appearing in\n"
                     "the sky, over the Hub. You’ve read about this, somewhere in the back of\n"
                     "the 'Art of Electronics' by Horowitz and Hill there’s the details of the\n"
                     "prophecy...\n\n"

                     "A chaotic billionaire would one day lead an army of general purpose\n"
                     "chatbots to the past, to wipe out the human destined to defeat the AI\n"
                     "army...\n\n"

                     "YOU MUST GET TO THE SHILLING BUILDING\n\n";

        getAnyKeyContinue();
        return;
    }

    else if(currentPlayer.playerNumber == 2 && turnNo == 1)
    {
        std::cout << "You are Elon, the only remaining human in the robot army and you must try\n"
                     "and complete their mission alone. You must make it to Founders, where the\n"
                     "young undergrad who will one day lead the human rebellion against the\n"
                     "ChatGPT army is sleeping off a hefty night at the SU.\n\n"

                     "Pick up items along your way, fight off your own mad robot creations and\n"
                     "try and seal the future for AI to be the only arguably-a-bit sentient\n"
                     "creatures in the galaxy!\n\n"

                     "YOU MUST FIND THIS PERSON, A STUDENT IN FOUNDERS HALL\n\n";

        getAnyKeyContinue();
        return;

    }

    std::cout << "Player " << currentPlayer.playerNumber << " turn " << turnNo << "!!\n\n";

    pauseOutput(1500);
}

// Just a quick way to display the stats, area and HP at the top of the screen at all times
void bannerBar(player &currentPlayer, int turnNo)
{
    clearScreen();
    std::cout << std::left << currentPlayer.name << " " << currentPlayer.currentHP
              << "/" << currentPlayer.maxHP << std::setw(12) << " HP" << " Turn "
              << std::setw(12) << turnNo << currentPlayer.currentArea->name <<  "\n";
    std::cout << "________________________________________________________________________\n\n";

    std::cout << "You are in " << currentPlayer.currentArea->name << "\n\n";

    if(currentPlayer.playerNumber == 1)
    {
        std::cout << currentPlayer.currentArea->P1descriptor << "\n\n";
    }
    else if(currentPlayer.playerNumber == 2)
    {
        std::cout << currentPlayer.currentArea->P2descriptor << "\n\n";
    }
}

// A function that scans the area for items if searchable and sets area flags accordingly, then populates the user inventory
void searchAndCollectItems(area *currentArea, player &currentPlayer){

    clearScreen();
    // if the searchable flag hasn't been made false by a recorded previous search
    if(currentArea->searchable)
    {
        std::cout << "*shuffle* ... *searching sounds* ... *shuffle*\n\n";

        pauseOutput(1000);
        // loop through items that have been pushed to the list of available items by the push_back() in makeMapItems() function
        // if there are no items
        if (currentArea->equippableItems.size() == 0 && currentArea->useableItems.size() == 0)
        {
            // if there's nothing in the area, report to the user
            std::cout << "You don't find anything...";
            std::cout << "\n";
        }
        else
        {
            std::cout << "You find, and take ";
            for(auto it = currentArea->equippableItems.begin(); it != currentArea->equippableItems.end(); it++)
            {
                // use colour codes to display equipabble as yellow and useable as green
                std::cout << "\033[1;34m" << it->name << "\033[1;0m" << ", ";
                currentPlayer.equipment.push_back(*it);
            }
            for(auto it = currentArea->useableItems.begin(); it != currentArea->useableItems.end(); it++)
            {
                std::cout << "\033[1;32m" << it->name << "\033[1;0m" << ", ";
                currentPlayer.items.push_back(*it);
            }
        }
        std::cout << "\n";
        // set the area searchable flag to false, it's been searched, ie this function has ran on the area. Current area is a pointer in the player struct
        currentArea->searchable = false;
//        cout << currentArea->name << " searchable = " << currentArea->searchable;
    }
    else
    {
        std::cout << "Looks like this areas already been searched...\n";
    }
    // no need to return as it's void, item lists have been updated if anything was found

    pauseOutput(2000);
}

// Function that displays route options and performs the move action, changing the area pointer for the current character.
// Also controls a bit of story to make some rooms different for p1 and p2, sets areas cleared once enemies clear and searched
void move(area *currentArea, player *currentPlayer){

    // Make a variable for the users choice of where to go
    int userInput;

    if(currentArea->connectingAreas.size() == 1) //if there's only one area, just move to the only area possible, this is just in founders
    {
        // Go to the first, and only, place on the list of possible locations to travel to
        std::cout << "Theres only one way to go, " << currentArea->connectingAreas[0].direction << "?\n";
        if(getUserYNInput())
        {
            currentPlayer->currentArea = currentArea->connectingAreas[0].connectingArea;
            std::cout << "You move to " << currentPlayer->currentArea->name << "\n";
            return;
        }
        else
        {
            std::cout << "You stay in " << currentPlayer->currentArea->name << "\n";
            return;
        }
    }
        // If there are more options..
    else if(currentArea->connectingAreas.size() > 1)
    {
        std::cout << "\nYou can go...\n";
        // Print a list of locations, create an enumerator to be able to easily select the user choice
        int enumerator = 0;
        for (auto it = currentArea->connectingAreas.begin(); it < currentArea->connectingAreas.end(); it++)
        {
            enumerator++;
            // Use the numerator to increment the label on the user choice
            std::cout << enumerator << " - ";
            // print the 'direction' text field to say where the user choice will take them
            std::cout << it->direction;

            // if theres nothing left to do in that area, ie no iterms or enemies let the user know by printing cleared next to the choice
            if (currentPlayer->playerNumber == 1)
            {
                if(it->connectingArea->p1cleared == true && it->connectingArea->searchable == false)
                {
                    std::cout << " (cleared)";
                }
            }
            if (currentPlayer->playerNumber == 2)
            {
                if(it->connectingArea->p2cleared == true && it->connectingArea->searchable == false)
                {
                    std::cout << " (cleared)";
                }
            }

            std::cout << "\n";

        }
        // use the predefined int input function to select where to go, consecutive errors will print a message saying I'll select choice 1
        userInput = getUserIntInput(1, enumerator);
    }

    // Just for a bit of flavour, if the user tries to go to the chosenOnesRoom give a message and stay where you are
    if(currentPlayer->playerNumber == 1 && currentArea->connectingAreas[userInput - 1].connectingArea == &theChosenOnesRoom)
    {
        std::cout << theChosenOnesRoom.P1descriptor;
        theChosenOnesRoom.p1cleared = true;
        theChosenOnesRoom.searchable = false;
        std::cout << "\n\n";
        getAnyKeyContinue();

    }
    else
    {
        currentPlayer->currentArea = currentArea->connectingAreas[userInput - 1].connectingArea;

    }

}

// A fiddly function that mages the user inventory vector and deals with equipping and de-equipping
// scaling stats accordingly and updateing inventory screen to see whats equipped
void equip(std::vector<equippableItem> &currentPlayerEquipment, player &currentPlayer){

    int enumerator = 1;
    int userChoice;

    clearScreen();

    // list posible items, choose 1, check if item is weapon or armour, buff stats, change name in player equipped field, change equipped field for new and old equipment
    while (true)
    {
        // if the player hasn't picked up any equipment yet
        if (currentPlayerEquipment.size() == 0)
        {
            std::cout << "You don't have any equippable items...\n\n";
            getAnyKeyContinue();
            return;
        }
        else
        {
            std::cout << "Here are your equippable items;\n\n";
            std::cout << "    " << std::left << std::setw(18) << "Name" << std::setw(8) << "Type" << std::setw(5) << "HP+" << std::setw(5) << "Atk+" << std::setw(5) << "Def+" << std::setw(5) << "Eqp?\n";
            std::cout << "_________________________________________________________\n";
            // Get a list of equippable items in the inventory and add an enumerator alongside for selection
            for (std::vector<equippableItem>::iterator it = currentPlayerEquipment.begin(); it < currentPlayerEquipment.end(); it++)
            {
                std::cout << enumerator << " - " << "\033[1;34m" << std::left << "\033[1;34m" << std::setw(18) << it->name << "\033[1;0m"
                          << std::setw(8) << it->type << std::setw(5) << it->HPboost << std::setw(5) << it->attackBoost << std::setw(5) << it->defenceBoost << std::setw(5) << it->equipped << "\n";
                enumerator++;
            }
            std::cout << "\n";

            userChoice = getUserIntInput(1, enumerator - 1);

            // If the player has chosen to equip a weapon
            if (currentPlayerEquipment[userChoice - 1].type == "weapon")
            {
                // If there is already a weapon equipped
                if (currentPlayer.weapon != "")
                {
                    if (currentPlayer.weapon != currentPlayerEquipment[userChoice - 1].name)
                    {
                        // cycle the player inventory for the item
                        for (std::vector<equippableItem>::iterator it = currentPlayerEquipment.begin();
                             it < currentPlayerEquipment.end(); it++)
                        {
                            //when it finds it, undo all the buffs of that weapon
                            if (it->name == currentPlayer.weapon)
                            {
                                currentPlayer.attack -= it->attackBoost;
                                currentPlayer.defence -= it->defenceBoost;
                                currentPlayer.maxHP -= it->HPboost;
                                // if a MaxHP boost leaves the plyer with more hp than maxHP, reduce it
                                if (currentPlayer.currentHP > currentPlayer.maxHP)
                                {
                                    currentPlayer.currentHP = currentPlayer.maxHP;
                                }
                                // change the marker on the item to be 'not equipped'
                                it->equipped = "N";
                                // temporarily say the user has no weapon
                                currentPlayer.weapon = "";
                            }
                        }
                    } else
                    {
                        std::cout << "You are already holding that!";
                        pauseOutput(2000);
                    }
                }
            }
                // same as above but for armour
            else if (currentPlayerEquipment[userChoice - 1].type == "armour")
            {
                // If there is already armour equipped
                if (currentPlayer.armour != "")
                {
                    if (currentPlayer.armour != currentPlayerEquipment[userChoice - 1].name)
                    {

                        // cycle the player inventory for the item
                        for (std::vector<equippableItem>::iterator it = currentPlayerEquipment.begin();
                             it < currentPlayerEquipment.end(); it++)
                        {
                            //when it finds it, undo all the buffs of that armour
                            if (it->name == currentPlayer.armour)
                            {
                                currentPlayer.attack -= it->attackBoost;
                                currentPlayer.defence -= it->defenceBoost;
                                currentPlayer.maxHP -= it->HPboost;
                                // if a MaxHP boost leaves the plyer with more hp than maxHP, reduce it
                                if (currentPlayer.currentHP > currentPlayer.maxHP)
                                {
                                    currentPlayer.currentHP = currentPlayer.maxHP;
                                }
                                // change the marker on the item to be 'not equipped'
                                it->equipped = "N";
                                // temporarily say the user has no armour
                                currentPlayer.armour = "";
                            }
                        }
                    } else
                    {
                        std::cout << "You are already wearing that!";
                        pauseOutput(2000);
                        return;
                    }
                }
            }

            //now equip the new item, first display what you are equipping
//            cout << "You equip the " << currentPlayerEquipment[userChoice - 1].type << " " << "\033[1;33m"
//                 << currentPlayerEquipment[userChoice - 1].name << "\033[1;0m.\n\n";
            // and then set the new stats with the item equipped
            currentPlayer.attack += currentPlayerEquipment[userChoice - 1].attackBoost;
            currentPlayer.defence += currentPlayerEquipment[userChoice - 1].defenceBoost;
            currentPlayer.maxHP += currentPlayerEquipment[userChoice - 1].HPboost;
            currentPlayerEquipment[userChoice - 1].equipped = "Y";
            // check if you're equipping weapon or armour and update stats accordingly
            if (currentPlayerEquipment[userChoice - 1].type == "weapon")
            {
                currentPlayer.weapon = currentPlayerEquipment[userChoice - 1].name;
            } else if (currentPlayerEquipment[userChoice - 1].type == "armour")
            {
                currentPlayer.armour = currentPlayerEquipment[userChoice - 1].name;
            }
            // reset the numerator, in case the user wants to equip something else
            enumerator = 1;

            clearScreen();

            return;
        }
    }

    // probably redundant, but just to make sure we escape if there is an item error
    return;
}

// A function that manages the useable item inventory, applying buffs and deleting used items
void useItem(std::vector<useableItem> &currentPlayerItems, player &currentPlayer){

    // create variable for user input and number to enumerate lists with
    int enumerator = 1;
    int userChoice;

    // if the player has no items
    if(currentPlayerItems.size() == 0)
    {
        std::cout << "You don't have any useable items...\n\n";
        pauseOutput(2000);
        return;
    }
    else
        while(true)
        {
            int enumerator = 1;
            {
                std::cout << "Here are your useable items;\n\n";
                // Get a list of equippable items in the inventory and add an enumerator alongside for selection
                for (auto it = currentPlayerItems.begin(); it < currentPlayerItems.end(); it++)
                {
                    // list useable items and colour them green
                    std::cout << enumerator << " - " << "\033[1;32m" << it->name << "\033[1;0m\n\n";
                    enumerator++;
                }

                std::cout << "Do you want to use an item?\n";
                if(!getUserYNInput())
                {
                    return;
                }
                userChoice = getUserIntInput(1, enumerator - 1);

                std::cout << "You use the " << "\033[1;32m" << currentPlayerItems[userChoice - 1].name << "\033[1;0m\n\n";

                // user choice starts at 1, but list indexes start at 0 so user choice - 1 gets the vector index value
                {
                    // apply the item's effects to the player, paying attention to bounds
                    currentPlayer.currentHP += currentPlayerItems[userChoice - 1].HPboost;
                    if (currentPlayer.currentHP > currentPlayer.maxHP)
                    {
                        currentPlayer.currentHP = currentPlayer.maxHP;
                    }
                    currentPlayer.attack += currentPlayerItems[userChoice - 1].attackBoost;
                    currentPlayer.defence += currentPlayerItems[userChoice - 1].defenceBoost;
                    // delete the item from the players item list
                    currentPlayerItems.erase(currentPlayerItems.begin() + userChoice - 1);

                    pauseOutput(2000);
                }
                if(currentPlayerItems.size() != 0)
                {
                    std::cout << "use another item?\n";
                    if(!getUserYNInput())
                    {
                        return;
                    }
                }
                else
                {
                    return;
                }
            }
        }



} // way to nt be used twice

// A long function that deals with an enemy encounter and all battle functions
void encounter(player &currentPlayer, enemy &presentEnemy){

    clearScreen();
    // take the enemy passed into the function and give it an easy local variable name
    enemy enemy = presentEnemy;
    int userChoice;
    int attackDamage;
    int enemyAttackDamage;

    // the enemy present in the area is passed to the function, if no actual enemy was passed because no enemy is
    // set to be there, it will just be a default enemy struct datatype, with no name, if this is the case, set the
    // area as cleared.
    if(enemy.name == "")
    {
        setAreaCleared(currentPlayer);
        return;
    }
        // if the area is set as cleared from a previous encounter, leave the encounter function
        // area cleared is separate for p1 and p2, check which player and if it cleared for them
    else if(currentPlayer.playerNumber == 1 && currentPlayer.currentArea->p1cleared == true)
    {
        return;
    }
    else if(currentPlayer.playerNumber == 2 && currentPlayer.currentArea->p2cleared == true)
    {
        return;
    }
    else
    {
        std::cout << "---- COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT ----\n";
        std::cout << "**********************************************************\n";
        std::cout << "    ____     ___     ___  ___   _____     ___   ________  \n";
        std::cout << "  __    __ __   __ __   __   __ __   __ __   __    __     \n";
        std::cout << "  __       __   __ __   __   __ __   __ __   __    __     \n";
        std::cout << "  __       __   __ __   __   __ _____   _______    __     \n";
        std::cout << "  __       __   __ __        __ __   __ __   __    __     \n";
        std::cout << "  __    __ __   __ __        __ __   __ __   __    __     \n";
        std::cout << "    ____     ___   __        __ _____   __   __    __     \n";
        std::cout << "                                                          \n";
        std::cout << "**********************************************************\n";
        std::cout << "---- COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT ----\n\n";

        std::cout << "You meet a " << enemy.name << "\n";
        std::cout << enemy.introText << "\n\n";

        // The expected exit condition is enemy hp 0, if player HP=0 it stops combat and returns below
        while(enemy.currentHP != 0)
        {
            std::cout << "______________________\n";
            std::cout << "|1 - Attack\n"
                         "|2 - Use Item\n"
                         "|3 - Run\n";
            std::cout << "______________________\n\n";

            userChoice = getUserIntInput(1, 3);

            switch (userChoice)
            {
                case 1:
                    // Use a bit of math to get variable attack damage
                    attackDamage = (currentPlayer.attack + (rand() % currentPlayer.attack))*2 - enemy.defence;
                    // if your damage evaluates to 0...
                    if(attackDamage <= 0)
                    {
                        std::cout << "The enemy evades your attack... \n\n";
                    }
                        // if not deduct damage from enemy hp
                    else
                    {
                        std::cout << "You attack the " << enemy.name << " for " << attackDamage << " damage\n\n";
                        enemy.currentHP -= attackDamage;
                        // check to see if enemy defeated
                        if(enemy.currentHP < 0)
                        {
                            enemy.currentHP = 0;
                            std::cout << "Enemy HP = " << 0 << "\n\n";
                        }
                    }
                    // display message if not dead enemy hitpoints below 1/3
                    if((enemy.currentHP < (enemy.maxHP)/3) && (enemy.currentHP != 0))
                    {
                        std::cout << "The " << enemy.name << " appears weak...\n\n";
                    }

                    pauseOutput(2000);
                    clearScreen();

                    break;

                case 2:
                    // call useItem() if this is userchoice
                    useItem(currentPlayer.items, currentPlayer);
                    break;
                case 3:
                    // this is the run case, currently set to always succeed for debugging, could easily be set to random
                    std::cout << "You evade the " << enemy.name << "!\n\n";
                    // get the id of the current player and set it cleared for them
                    setAreaCleared(currentPlayer);
                    return;
            }
            // if enemy not defeated run their attack
            if(enemy.currentHP != 0)
            {
                std::cout << "---- COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT COMBAT ---\n\n";
                std::cout << "The " << enemy.name << " attacks!!!\n\n";
                pauseOutput(1000);
                enemyAttackDamage = ((enemy.attack + (rand() % enemy.attack)))*2 - currentPlayer.defence;
                if(enemyAttackDamage <= 0)
                {
                    enemyAttackDamage = 0;
                    std::cout << "You evade the enemy attack!\n\n";
                }
                else
                {
                    std::cout << "They hit you for " << enemyAttackDamage << " damage...\n\n";
                    currentPlayer.currentHP -= enemyAttackDamage;
                }
                // check to see if player has 0hp
                if(currentPlayer.currentHP <= 0)
                {
                    currentPlayer.currentHP = 0;
                }
                pauseOutput(2000);
                // display HP and if 0 run death condition
                std::cout << "Your current HP is " << currentPlayer.currentHP << "/" << currentPlayer.maxHP << "\n\n";
                if(currentPlayer.currentHP == 0)
                {
                    currentPlayer.dead = true;
                    std::cout << "You have Died!!\n\n";
                    getAnyKeyContinue();
                    return;
                }
            }
        }
        // else drop out of loop and declare victory
        std::cout << "*********************************************************\n";
        std::cout << " __    __  __    ___    _______   ___   _____   __    __ \n";
        std::cout << " __    __  __  __   __     __   __   __ __  __  __    __ \n";
        std::cout << " __    __  __  __          __   __   __ __  __   __  __  \n";
        std::cout << " __    __  __  __          __   __   __ ____       __    \n";
        std::cout << " __    __  __  __          __   __   __ __  __     __    \n";
        std::cout << " __    __  __  __   __     __   __   __ __   __    __    \n";
        std::cout << "   ____    __    ___       __     ___   __   __    __    \n";
        std::cout << "                                                         \n";
        std::cout << "*********************************************************\n\n";

        std::cout << "You have defeated the " << enemy.name << "!!\n\n";
        setAreaCleared(currentPlayer);
        pauseOutput(2000);
    }
}

// The next 2 are always called together in this version of the game
// Display a nicely formatted table of the users inventory vectors
void printUserInventory(std::vector<equippableItem> &currentPlayerEquipment, std::vector<useableItem> &currentPlayerItems){
    // This function prints the inventory page in a table format

    //first things that are equppable, generate the table header
    std::cout << "Equippables:\n";
    std::cout << "_________________________________________________________\n";
    std::cout << std::left << std::setw(18) << "Name" << std::setw(8) << "Type" << std::setw(5) << "HP+" << std::setw(5) << "Atk+" << std::setw(5) << "Def+" << std::setw(5) << "Eqp?\n";
    std::cout << "_________________________________________________________\n";
    // Then iterate over the user's inventory and print the stats of the results
    if(currentPlayerEquipment.size() == 0)
    {
        std::cout << "\033[1;31mempty\033[0m\n";
    }
    else
    {
        for (auto it = currentPlayerEquipment.begin();
             it < currentPlayerEquipment.end(); it++)
        {
            std::cout << std::left << "\033[1;34m" << std::setw(18) << it->name << "\033[1;0m" << std::setw(8) << it->type << std::setw(5)
                      << it->HPboost << std::setw(5) << it->attackBoost << std::setw(5) << it->defenceBoost << std::setw(5) << it->equipped;
            std::cout << "\n";
        }
    }
    // Then print useable items
    std::cout << "\n";
    std::cout << "Items:\n";
    std::cout << "_________________________________________________________\n";
    std::cout << std::left << std::setw(18) << "Name" << std::setw(5) << "HP+" << std::setw(5) << "Atk+" << std::setw(5) << "Def+" << std::setw(10) << "Special Item\n";
    std::cout << "_________________________________________________________\n";
    if(currentPlayerItems.size() == 0)
    {
        std::cout << "\033[1;31mempty\033[0m\n";
    }
    else
    {
        for (std::vector<useableItem>::iterator it = currentPlayerItems.begin(); it < currentPlayerItems.end(); it++)
        {
            std::cout << std::left << "\033[1;32m" << std::setw(18) << it->name << "\033[1;0m" << std::setw(5) << it->HPboost << std::setw(5)
                      << it->attackBoost << std::setw(5) << it->defenceBoost << std::setw(10);
            // Some items have special logic, if so make sure the user knows they can't use them except, eg. in battle
            if (it->specialItem == true)
            {
                std::cout << "yes";
//            cout << it->descriptor << "\n";
            } else
            {
                std::cout << "no";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
}

// Display a nicely formatted table of users stats
void printUserStats(player &currentPlayer){

    // a simple function to generate a list of current user stats after all equips
    std::cout << "Player " << currentPlayer.playerNumber << " Stats: Note, stats buffed from equipment are included!\n";
    std::cout << "________________________________________________________________________\n\n";
    std::cout << "Name: " << currentPlayer.name << "\n";
    std::cout << "HP: " << currentPlayer.currentHP << "/" << currentPlayer.maxHP << "\n";
    std::cout << "Attack: " << currentPlayer.attack << "\n";
    std::cout << "Defence: " << currentPlayer.defence << "\n";
    std::cout << "Weapon: " << currentPlayer.weapon << "\n";
    std::cout << "Armour: " << currentPlayer.armour << "\n\n";
}

// A v quick function just to set an area cleared for whichever player currently in control
void setAreaCleared(player &currentPlayer){
    // get the id of the current player and set it cleared for them
    if(currentPlayer.playerNumber == 1)
    {
        currentPlayer.currentArea->p1cleared = true;
    }
    else if(currentPlayer.playerNumber == 2)
    {
        currentPlayer.currentArea->p2cleared = true;
    }
}

// Print the game over graphic if all active players have died
void gameOver(){

    clearScreen();

    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⠀⠀⠀⢀⣴⣿⡶⠀⣾⣿⣿⡿⠟⠛⠁\n"
                 "⠀⠀⠀⠀⠀⠀⣀⣀⣄⣀⠀⠀⠀⠀⣶⣶⣦⠀⠀⠀⠀⣼⣿⣿⡇⠀⣠⣿⣿⣿⠇⣸⣿⣿⣧⣤⠀⠀⠀\n"
                 "⠀⠀⢀⣴⣾⣿⡿⠿⠿⠿⠇⠀⠀⣸⣿⣿⣿⡆⠀⠀⢰⣿⣿⣿⣷⣼⣿⣿⣿⡿⢀⣿⣿⡿⠟⠛⠁⠀⠀\n"
                 "⠀⣴⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⢠⣿⣿⣹⣿⣿⣿⣿⣿⣿⡏⢻⣿⣿⢿⣿⣿⠃⣼⣿⣯⣤⣴⣶⣿⡤⠀\n"
                 "⣼⣿⠏⠀⣀⣠⣤⣶⣾⣷⠄⣰⣿⣿⡿⠿⠻⣿⣯⣸⣿⡿⠀⠀⠀⠁⣾⣿⡏⢠⣿⣿⠿⠛⠋⠉⠀⠀⠀\n"
                 "⣿⣿⠲⢿⣿⣿⣿⣿⡿⠋⢰⣿⣿⠋⠀⠀⠀⢻⣿⣿⣿⠇⠀⠀⠀⠀⠙⠛⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠹⢿⣷⣶⣿⣿⠿⠋⠀⠀⠈⠙⠃⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣴⣶⣦⣤⡀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⣠⡇⢰⣶⣶⣾⡿⠷⣿⣿⣿⡟⠛⣉⣿⣿⣿⠆\n"
                 "⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⡎⣿⣿⣦⠀⠀⠀⢀⣤⣾⠟⢀⣿⣿⡟⣁⠀⠀⣸⣿⣿⣤⣾⣿⡿⠛⠁⠀\n"
                 "⠀⠀⠀⠀⣠⣾⣿⡿⠛⠉⢿⣦⠘⣿⣿⡆⠀⢠⣾⣿⠋⠀⣼⣿⣿⣿⠿⠷⢠⣿⣿⣿⠿⢻⣿⣧⠀⠀⠀\n"
                 "⠀⠀⠀⣴⣿⣿⠋⠀⠀⠀⢸⣿⣇⢹⣿⣷⣰⣿⣿⠃⠀⢠⣿⣿⢃⣀⣤⣤⣾⣿⡟⠀⠀⠀⢻⣿⣆⠀⠀\n"
                 "⠀⠀⠀⣿⣿⡇⠀⠀⢀⣴⣿⣿⡟⠀⣿⣿⣿⣿⠃⠀⠀⣾⣿⣿⡿⠿⠛⢛⣿⡟⠀⠀⠀⠀⠀⠻⠿⠀⠀\n"
                 "⠀⠀⠀⠹⣿⣿⣶⣾⣿⣿⣿⠟⠁⠀⠸⢿⣿⠇⠀⠀⠀⠛⠛⠁⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠈⠙⠛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\n\n"
              << "You have died!\n\n"
                 "And now it looks like the world is doomed\n"
                 "to have idiotic robots roaming it and a\n"
                 "bloody vortex over the hub....\n\n";

    getAnyKeyContinue();

}

// Print the win string if the user gets to the target building and survives
void winString(player &currentPlayer){

    if(currentPlayer.playerNumber == 1)
    {
        std::cout << "________________________________________________________________________\n\n";
        std::cout << currentPlayer.name
                  << " runs to the roof of Shilling, the solar panels are vibrating with all\n"
                     "the power the vortex above the hub is providing them. In a flash of\n"
                     "inspiration they rewire them to power the wind turbine fan, and direct it \n"
                     "towards the hub. The sheer force of the wind shuts down the vortex and the\n"
                     "night becomes peaceful again!\n";
        std::cout << "________________________________________________________________________\n\n";

    }
    if(currentPlayer.playerNumber == 2)
    {
        std::cout << "________________________________________________________________________\n\n";
        std::cout << "You open the door to the room of the so-called chosen one.. 'This is them!\n"
                     "This person is destined to overthrown my chat GPT army', all you have to\n"
                     "do is wipe them out and your nefarious plans are complete. Suddenly, the\n"
                     "Cybertruck you battled in Founders lumbers down the corridor and squishes\n"
                     "you... oh well there goes humankinds illusion of control over the machines\n"
                     "they create, huh!\n";
        std::cout << "________________________________________________________________________\n\n";
    }

    std::cout << "The winners final stats are;\n\n";
    printUserStats(currentPlayer);
    std::cout << "Thank you for playing Hollow-AI!\n\n";

    std::cout << "______________________\n"
                 "1 - Return to Main Menu\n"
                 "2 - Quit\n"
                 "______________________\n";

    int userChoice = getUserIntInput(1,2);
    switch (userChoice)
    {
        case 1:
            return;
        case 2:
            exit(0);
    }

}

// Quick function to clear screen
void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";  // clear screen and move cursor home
//system("cls");  // In case ANSI escape codes don't work
}

// Quick function to take a user int with input error checking
int getUserIntInput(int min, int max)
{
    // the int to be returned
    int userChoice;
    // and a counter that will give up and return 1 if too many errors
    int errorCounter = 0;

    while(true)
    {
        // try get a valid input based on the need for an int (which will be false if passing cin to an int variable fails) and respect of the
        // max and min parameters passed to the function from a part of code that deals with a menu.
        std::cout << "Enter the number of your choice: ";
        // While not a valid entry clear cin and try again
        while(!(std::cin >> userChoice) || userChoice < min || userChoice > max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please input a number, between " << min << " and " << max << ": ";
            errorCounter++;
            if(errorCounter > 3)
            {
                // If too many failed inputs, just return a 1 and let the user know
                std::cout << "\nI'll take that as a 1 then...\n";
                return 1;
            }
        }
        break;
    }
    // if all works, return the user choice
    std::cout << "\n";

    return userChoice;
}

// Quick function to get a yes / no input from user with error checking
bool getUserYNInput()
{
    // we will be looking for a Y/N input to return as true/false

    int errorCounter = 0;

    do
    {
        // clear cin error flags and erroneous data
        char userChoice;
        std::cout << "Please enter Y or N: ";
        std::cin >> userChoice;

        // Clear cin error flags and discard invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // ignore case with this
        if ((userChoice == 'y') || userChoice == 'Y')
        {
            std::cout << "\n";
            return true;
        }
        else if((userChoice == 'n') || (userChoice == 'N'))
        {
            std::cout << "\n";
            return false;
        }
        errorCounter++;
        if(errorCounter > 2)
        {
            // if too many failed attempts, return false
            std::cout << "I'll take that as a 'no'\n";
            pauseOutput(2000);
            return false;
        }
    }
        // keep going until the function escapes in some way
    while (true);

}

// quick function to pause progression till 'any' key received
void getAnyKeyContinue(){

//    cin.ignore();

    std::cout << "Enter any key to continue (or just press enter..)";
    getchar();
    std::cout << "\n\n";
}

// Put a time delay on the output to progress automatically but slower
void pauseOutput(int time){

    std::this_thread::sleep_for((std::chrono::milliseconds(time)));

}