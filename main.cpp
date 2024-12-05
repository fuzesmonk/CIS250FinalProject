#include "MemoryMatch.hpp"
#include "game.hpp"
#include <iostream>
//For Linux Machines
#include <unistd.h>
#include <random>

//For Windows Machines
//#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main() {
    bool done = false;
    game mainGame;
    while(!done){
        done = mainGame.start();
    }
    mainGame.gameLoop();
    mainGame.~game();
    return 0;
}
