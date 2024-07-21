// Owen Morgan
// EE1010 C++
// Final Project - Game
// Version 1.00

//#include <vector> // Vectors are used for inventories, routes
//#include <iomanip> // Just for the inventory screen to set table widths
//#include <cstdlib>
#include <iostream> // used for cin cout mainly
#include <ctime> // just used to gen a random number for stat creation
#include <thread> // These two just used in pauseOutput() to get a cross platform time delay, note this also includes chrono

#include "functions.h"

// make empty structs for the players
player player1;
player player2;



int main() {

    std::srand(time(nullptr));



// Start with no game in progress so it falls into the first part of the game loop
// cont is the variable watched to see if the user wants to continue the game at various points
    bool gameInProgress = false;
    bool cont = true;
// variables to set 2 player mode
    int noOfPlayers;
    bool twoPlayerMode = false;

// make the map
    generateMap();

// variable to count turns
    int turnNo;

    while(true) // inner gameloop, a running game
    {
        // This runs as the top screen when the program starts or is reset, ie no game in progress
        if(!gameInProgress)
        {
            //set turn to 1
            turnNo = 1;
            // ensures the map is cleared if returning here from a cancelled game
            resetMap();
            // display menu
            gameStartMenu(gameInProgress);

            // if gameinprogress is switched to Yes by gameStartMenu() load function, skip initialise; (not written yet)
            std::cout << "One or Two player?\n\n";
            noOfPlayers = getUserIntInput(1, 2);
            if(noOfPlayers == 2)
            {
                twoPlayerMode = true;
                // make player 2, player 2 name is always Elon
                player2 = generatePlayers(2);
            }

            // Always generate p1, this will ask for a name
            player1 = generatePlayers(1);

        }

        // Player 1 and Player 2 take turns
        if (!player1.dead)
        {
            turnChangeover(player1, turnNo);
            // take turn and check that the user wants to continue
            cont = playerTakeTurn(player1, turnNo, gameInProgress);
        }
        // ignore if not 2 player mode, or if p2 is dead
        if (twoPlayerMode && !player2.dead && cont == true) // the second argument just skips p2turn if the game has been reset
        {
            turnChangeover(player2, turnNo);
            cont = playerTakeTurn(player2, turnNo, gameInProgress);
        }

        //if the user has asked to discontinue this game and start a new one, this will cycle back to top
        if(cont == false)
        {
            gameInProgress = false;
        }

        // If both players are dead it's game over, and cycle back to the top
        if (player1.dead && player2.dead)
        {
            gameInProgress = false;
            gameOver();
        }
        // iterate turn no and do game loop again
        turnNo++;
    }

}




