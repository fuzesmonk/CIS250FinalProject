#pragma once
#include "MemoryMatch.hpp"
#include <iostream>

class game : public MemoryMatch{

    private:
        MemoryMatch internalGame;
        std::string displayName;
        bool themeSelected, firstPlace, secondPlace;
        int rows, cols, totalCells, randomRow, randomCol, wordIndex, timeDiff;
        //Gameboard coordinates
        int x1, x2, y1, y2;
        int totalWords = 0;
        int matchedWords;
        const int cellWidth = 8;
        std::string ** board = nullptr;
        std::string * chosenWords = nullptr;
        std::string * wordPool = nullptr;
        bool * revealed = nullptr;
        bool finished;


    public:

        game();

        bool start();

        int gameLoop();

        void printBoard(std::string**, const bool*, const int, int, int);

        int checkAndRevealWords(std::string**, bool *, int, int, int, int, int, int);

        ~game();

};
