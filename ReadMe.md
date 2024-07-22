## Hollow-Ai ##
### Text based RPG for 1 or 2 players ###

## Build Instructions ##

This is a C++ project for an RPG game created as part of the EE1010 coursework. The project uses only the C++ standard library.

### Prerequisites
- C++17 compatible compiler (e.g., GCC, Clang)
- CMake (version 3.10 or later)

### Building the Project

1. **Clone the Repository**:
   ```shell
   git clone https://github.com/yourusername/Hollow-Ai.git
   cd Hollow-Ai
   
2. **Create build directory**
    ```shell
    mkdir build
    cd build
   ```
   
3. **Run Cmake** 
    ```shell
    cmake ..
   ```
4. **Compile**
    ```shell
      make
    ```
5. **Run the Exectuable**
   ```shell
    ./Hollow-Ai
    ```

## Intro ##
The Games initial specificalions when set as a piece of coursework were narrow and limited to an
earlier version of c++, no classes (only structs), only explicitly declared iterators (no auto)
and only features that we had been introduced to on the course.

The aim of this projects is to update and streamline the game, initially getting it into a more
modern format and then to add functionality, and fixes.

## Current Goals ##

- Ascertain if structs are the best choice or if anything could be gained by using classes.
- Further refine functions to be clearer in layout, maybe seperate by type
- seperate enemy and item creation funtions from map creation function


## Planned Goals ##

- Try and make the map system more like I originally envisaged (no globals)
- Add the luck stat and a mechanism for escape chance percentage
- Add load/save functionality
- Maybe add some graphics, just very simple map with dot where you are or similar to start with.
- Make audio play on encounters etc.
- Add more flavour, items, enemies etc.
- Add music
- Add resize terminal window on run
- Make own window
- Add simple graphics
- Add mouse support and gui (:O)

## Completed Goals ##


- Convert all loops over vectors etc to use auto or smart looping methods
- Move away from using namespace std
- - Split all functions out into dedicated header file
- 
