#include "MemoryMatch.hpp"
#include "game.hpp"
#include <iostream>
#include <unistd.h>
#include <random>
#include <iomanip>


//For windows machines
//#include <windows.h>

game::game(){
    themeSelected = internalGame.themeSelect();
    displayName = internalGame.getDisplayTheme();
    timeDiff = internalGame.timeSelect();
    rows = internalGame.sizeSelect();
    cols = internalGame.getSize();
    totalCells = rows * cols;
    revealed = new bool[rows * cols]{false};
    matchedWords = 0;
    finished = false;
}

/**
 * @brief Startup script for game
 * 
 * @return true If there are enough words to fill board, board size is allocated, and words are placed into board array
 * @return false    In case enough words are somehow not chosen for the board
 */
bool game::start(){

    //Checking if there are enough words to fill the whole board
    if(totalCells > internalGame.getWordCount()){
        std::cout << "GameError: Not enough words to fill board" << std::endl;
        return false;
    }
    //Allocating board size dynamically
    board = new std::string *[rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new std::string[cols];
    }

    //Fetching Words from chosenWords array
    chosenWords = internalGame.getWords();
    wordPool = new std::string[totalCells];
    for(int i = 0; i < totalCells / 2; ++i){
        wordPool[i] = chosenWords[i];
        totalWords++;
    }
    //Placing the word randomly into the array twice
    wordIndex = 0;
    for(int i = 0; i < totalCells / 2; i++) {
        firstPlace = false;
        secondPlace = false;
        while(!firstPlace){
            //Generating the random numbers for the array indexes
            randomRow = rand() % rows;
            randomCol = rand() % rows;
            //Checks if the array has a blank value, replaces it with word if it does and sets firstPlace to true
            if(board[randomRow][randomCol] == ""){
                board[randomRow][randomCol] = wordPool[wordIndex];
                std::cout << wordPool[wordIndex] << " placed at row " << randomRow + 1 << " and column " << randomCol + 1 << std::endl;
                firstPlace = true;
            }   else{
                    continue;
                    std::cout << "Array at row " << randomRow << " and column " << randomCol << " filled. Retrying" << std::endl;
            }
        }
        //If secondPlace is false, then if the first word has been placed 
        while(!secondPlace) {
            if(firstPlace){
                randomRow = rand() % rows;
                randomCol = rand() % rows;

                if(board[randomRow][randomCol] == "") {
                    board[randomRow][randomCol] = wordPool[wordIndex];
                    std::cout << wordPool[wordIndex] << " placed at row " << randomRow + 1 << " and column " << randomCol + 1 << std::endl;
                    wordIndex++;
                    secondPlace = true;
                } else{
                    continue;
                    std::cout << "Array at row " << randomRow << " and column " << randomCol << " filled. Retrying" << std::endl;
                }
            }
        }
    }
    return true;
}

/**
 * @brief Main game loop, contains the logic for finding the cells in the 2d array
 * 
 * @return int Returns 0 if all the words are found, else returns 1 as a catch condition
 */
int game::gameLoop(){
    //system("clear");
    while(!finished) {
        printBoard(board, revealed, cellWidth, rows, cols);

        std::cout << "First Word" << std::endl;
        std::cout << "Enter Row: ";
        std::cin >> x1;
        std::cout << "Enter Column: ";
        std::cin >> y1;
        std::cout << "First Word: " << board[x1 - 1][y1 - 1] << std::endl;

        int index1 = (x1 - 1) * cols + (y1 - 1);
        revealed[index1] = true;
        printBoard(board, revealed, cellWidth, rows, cols);
        revealed[index1] = false;

        std::cout << "Second Word" << std::endl;
        std::cout << "Enter Row: ";
        std::cin >> x2;
        std::cout << "Enter Column: ";
        std::cin >> y2;

        if(x1 < 1 || x1 > rows || y1 < 1 || y1 > cols){
            std::cout << "Invalid Coordinates. Try Again \n";
            continue;
        }
        if (revealed[index1]) {
            std::cout << "Tile already revealed. Try another.\n";
            continue;
        }
        if(x2 < 1 || x2 > rows || y2 < 1 || y2 > cols ) {
            std::cout << "Invalid coordinates. Try again. \n";
            continue;
        }

        int index2 = (x2 - 1) * cols + (y2 - 1);
        if(revealed[index2]) {
            std::cout << "Tile already revealed. Try again. \n";
            continue;
        }

        if(x1 == x2 && y1 == y2) {
            std::cout << "The same tile was selected twice. Try again. \n";
            continue;
        }        
        matchedWords += checkAndRevealWords(board, revealed, rows, cols, x1, y1, x2, y2);
        if(matchedWords >= ((rows * rows) / 2)){
            std::cout << "All Words Found!" << std::endl;
            finished = true;
            return 0;
        }
    }
    return 1;
}




/**
 * @brief Prints out the board, with cells containing either the placeholder or the shown word
 * 
 * @param board Pointer to the gameboard array
 * @param revealed Pointer that stores which of the values in the gameboard are revealed
 * @param cellWidth Controls the width of the cells in the board, can be changed 
 * @param rows Rows needed to display the gameboard
 * @param cols Columns needed to display the gameboard
 */
void game::printBoard(std::string** board, const bool* revealed, const int cellWidth, int rows, int cols) {
    std::cout << "  ";
    for (int col = 0; col < cols; ++col)
        std::cout << std::setw(cellWidth) << col + 1;
    std::cout << std::endl;

    std::cout << "  +";
    for (int col = 0; col < cols; ++col)
        std::cout << std::string(cellWidth - 1, '-') << "+";
    std::cout << std::endl;

    for (int row = 0; row < rows; ++row) {
        std::cout << row + 1 << " |";
        for (int col = 0; col < cols; ++col) {
            int index = row * cols + col;
            if (revealed[index]) {
                std::cout << std::setw(cellWidth - 2) << board[row][col] << std::setw(cellWidth - 6) << "|";
            } else {
                std::cout << std::setw(cellWidth - 2) << "■" << std::setw(cellWidth - 4) << "|";
            }
        }
        std::cout << std::endl;

        std::cout << "  +";
        for (int col = 0; col < cols; ++col)
            std::cout << std::string(cellWidth - 1, '-') << "+";
        std::cout << std::endl;
    }
}

/**
 * @brief Checks if the words at the coordinates given by the user are the same
 * 
 * @param board Pointer to the 2d array which contains all of the words in the gameboard
 * @param revealed Pointer to a 1d array which stores whether a word has been revealed as a boolean
 * @param rows Rows necessary to display gameboard, Needed for printBoard()
 * @param cols Columns necessary to display gameboard, Needed for printBoard()
 * @param x1 User chosen x coordinate in gameboard of First Word 
 * @param y1 User chosen y coordinate in gameboard of First Word
 * @param x2 User chosen x coordinate in gameboard for Second Word
 * @param y2 User chosen y coordinate in gameboard for Second Word
 * @return int Returns 0 if the words do not match, else returns 1 since words match which updates @var matchedWords
 */
int game::checkAndRevealWords(std::string ** board, bool * revealed, int rows, int cols, int x1, int y1, int x2, int y2){
    int index1 = (x1 - 1) * cols + (y1 - 1);
    int index2 = (x2 - 1) * cols + (y2 - 1);
    revealed[index1] = true;
    revealed[index2] = true;

    printBoard(board, revealed, 8, rows, cols);

    if(board[x1- 1][y1 - 1] != board[x2 - 1][y2 - 1]){
        std::cout << "Words do not match" << std::endl;
        sleep(timeDiff);
        revealed[index1] = false;
        revealed[index2] = false;
        system("clear");
        return 0;
    } else{
        std::cout << "The Words Match" << std::endl;
        //system("clear");
        return 1;
    }
} 

/**
 * @brief Destroy the game::game object
 * 
 */
game::~game(){
    for(int i = 0; i < rows; ++i){
        delete[] board[i];
    }
    delete[] board;
    delete[] revealed;
    delete[] wordPool;
}
