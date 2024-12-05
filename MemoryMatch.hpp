/**
 * @file MemoryMatch.hpp
 * @author Ella Ley
 * @brief Memory Matching Game
 * @version 1.0
 * @date 2024-11-08
 *  
 */

//Requirements
//3 Themes, each based on one of the three txt files in \dir themes
//Have each themeFile have a term that describes it
// 
//USER MENU
//Level of Play: 4x4, 6x6, 8x8
//Speed of Play: How long in seconds words in the grids will be shown: 2, 4, 6
//
//At game start, themeFile name should be shown in all grid spaces
//
//MECHANICS
//Amount of words needed is gridSize / 2
//Each word will be present twice on the board
//Store the words and their respective locations in a 2D array
//
//GAMEPLAY LOOP
// 1. User selects first square, themeFile term is replaced by its respective word from the word array
// 2. User selects second square, themeFile term replaced by respective word from game array
// 3. IF SAME: Keep terms displayed, those terms are no longer selectable
//    IF DIFFERENT: Terms remain on screen for selected difficulty time, then revert to themeFile name
#pragma once
#include <iostream>
#include <iomanip>

class MemoryMatch{
    
    private:
        std::string AllWords[51];
        std::string themeFile;
        std::string themeName;
        std::string displayThemeName;
        std::string * SelectedWords;
        std::string * ptrChosenWords = nullptr;
        int boardSize;
        int difficultyTime;
        int row;
        bool wordsSelected;
        int totalWords;

    public:
        MemoryMatch();

        
        int sizeSelect();

        int timeSelect();

        //themeFile Selection, loads words into array
        bool themeSelect();

        //void boardInit();
    
        std::string * getWords();

        int getWordCount();

        int getSize();

        std::string  getDisplayTheme();

        ~MemoryMatch(){};
};
