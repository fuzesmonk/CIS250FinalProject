#include "MemoryMatch.hpp"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <cmath>


MemoryMatch::MemoryMatch(){
    themeFile = "none";
    boardSize = 0;
    char tableColumn[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    difficultyTime = 0;
    row = 0;

}


void MemoryMatch::sizeSelect(){
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
}

void MemoryMatch::timeSelect(){
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
            break;
        case 2:
            difficultyTime = 4;
            break;
        case 3:
            difficultyTime = 2;
            break;        
        }
    }
}

void MemoryMatch::themeSelect(){

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
                themeFile = "humanProteins.txt";
                themeName = "Human Proteins";
                done = false;
                //std::cout << "DEBUG: Proteins" << std::endl;
                break;

            case 2:
                themeFile = "USmilitaryaircraft.txt";
                themeName = "US Military Aircraft";
                done = false;
                //std::cout << "DEBUG: Aircraft" << std::endl;
                break;

            case 3:
                themeFile = "x86assembly.txt";
                themeName = "x86 Assembly";
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
}


void MemoryMatch::getWords(){
double neededWords = (pow(boardSize, 2)) / 2;
    std::cout << "Needed Words Value: " << neededWords << std::endl;
    std::string chosenWordArray[int(neededWords)];
    //Default Values for all array members
    for(int j = 0; j < ((int(neededWords)) / 2) - 1; j++){
        chosenWordArray[j] = "none";
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
            if(potentialWord != chosenWordArray[i]){
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
            chosenWordArray[openIndex] = potentialWord;
            openIndex++;
        }
        }    

}