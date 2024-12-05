#include "MemoryMatch.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

/**
 * @brief Construct a new Memory Match:: Memory Match object
 * 
 */
MemoryMatch::MemoryMatch(){
    themeFile = "none";
    boardSize = 0;
    difficultyTime = 0;
    row = 0;
    displayThemeName = "none";

}

/**
 * @brief Selects size for the gameboard for later use
 * 
 * @return int Dimension of one side of the gameboard
 */
int MemoryMatch::sizeSelect(){
    bool done = true;
    while(done){
        int userSelection;
        std::cout << "Select Board Size" << std::endl;
        std::cout << "1. 4x4" << std::endl;
        std::cout << "2. 6x6" << std::endl;
        std::cout << "3. 8x8\n" << std::endl;
        std::cout << "Enter Selection Number: ";
        std::cin >> userSelection;
        
        switch(userSelection){
            case 1:
                boardSize = 4;
                done = false;
                break;
            case 2:
                boardSize = 6;
                done = false;
                break;
            case 3:
                boardSize = 8;
                done = false;
                break;
        }
    }
    return boardSize;
}


/**
 * @brief Selects how long the words will be displayed if not matching
 * 
 * @return int How long the user can see the words before the board is reset
 */
int MemoryMatch::timeSelect(){
    int userSelection;
    bool done = true;
    while(done){
        std::cout << "Select how long words are displayed when pair do not match" << std::endl;
        std::cout << "1. 6 Seconds" << std::endl;
        std::cout << "2. 4 Seconds" << std::endl;
        std::cout << "3. 2 Seconds" << std::endl;
        std::cout << "Enter Selection Number: ";
        std::cin >> userSelection;

        switch(userSelection){
            case 1:
                difficultyTime = 6;
                done = false;
                break;
            case 2:
                difficultyTime = 4;
                done = false;
                break;
            case 3:
                difficultyTime = 2;
                done = false;
                break;        
            }
        }
    return difficultyTime;
}

/**
 * @brief Selects theme for 3 possible choices corresponding to its respective .txt file
 * 
 * @return true When a theme has been chosen and words are loaded into the @var AllWords array
 * @return false Does not occur as the theme will only exit upon successful loading of a theme
 */
bool MemoryMatch::themeSelect(){

    bool done = true;
    int userSelection;
    while(done){
        std::cout << "1. Human Proteins" << std::endl;
        std::cout << "2. US Military Aircraft" << std::endl;
        std::cout << "3. x86 Assembly Instructions" << std::endl;
        std::cout << "Select Theme: ";
        std::cin >> userSelection;
        switch(userSelection){
            case 1:
                themeFile = "./themes/humanProteins.txt";
                themeName = "Human Proteins";
                displayThemeName = "Protein";
                done = false;
                //std::cout << "DEBUG: Proteins" << std::endl;
                break;

            case 2:
                themeFile = "./themes/USmilitaryaircraft.txt";
                themeName = "US Military Aircraft";
                displayThemeName = "Aircraft";
                done = false;
                //std::cout << "DEBUG: Aircraft" << std::endl;
                break;

            case 3:
                themeFile = "./themes/x86assembly.txt";
                themeName = "x86 Assembly";
                displayThemeName = "x86";
                done = false;
                //std::cout << "DEBUG: Assembly" << std::endl;
                break;
        }
    }
    //Import File Contents
    std::ifstream inputFile(themeFile);
    std::string importWord;
    int i = 0;
    while(getline(inputFile, importWord)){
        AllWords[i] = importWord;
        i++;
    }
    inputFile.close();
    return true;
}

/**
 * @brief Sets up the array that selects which words are loaded into the gameboard
 * 
 * @return std::string* Pointer to the array of strings which contains all of the words loaded into gameboard
 */
std::string * MemoryMatch::getWords(){
    int neededWords = (pow(boardSize, 2) / 2);
    totalWords = neededWords;
    std::string ChosenWords[neededWords];
    ptrChosenWords = ChosenWords;
    //Default Values for all array members
    for(int j = 0; j < ((neededWords) / 2) - 1; j++){
        ptrChosenWords[j] = "none";
    }
    std::string newWord;
    int randomNum = 0;
    int openIndex = 0;
    bool inArray = true;
    std::string potentialWord;
    while(openIndex < neededWords){
        randomNum = rand() % 50;
        potentialWord = AllWords[randomNum];
        for(int i = 0; i <= openIndex; i++){
            if(potentialWord != ptrChosenWords[i]){
                inArray = false;
                }
            else{
                inArray = true;
                //std::cout << "Word Already in Array" << std::endl;
            }
        }
        if(inArray){
            break;
        }    
        else{
            ptrChosenWords[openIndex] = potentialWord;
            openIndex++;
        }
    }  
    wordsSelected = true; 
    return ptrChosenWords;
}
/**
 * @brief Simple Getter for the total word count
 * 
 * @return int Count of how many words will be needed in the gameboard
 */
int MemoryMatch::getWordCount(){
    return totalWords;
}

/**
 * @brief Simple Getter for gameboard size
 * 
 * @return int Size of one side of the gameboard
 */
int MemoryMatch::getSize(){
    return boardSize;
}

/**
 * @brief Simple Getter for the theme name
 * 
 * @return std::string Abbreviated name of the theme for use in the gameboard
 */
std::string MemoryMatch::getDisplayTheme(){
    return displayThemeName;
}