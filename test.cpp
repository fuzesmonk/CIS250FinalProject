#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


int main(){

    //Default Variables
    int boardSize = 6;
    std::string AllWords[51];
    std::string themeFile = "USmilitaryaircraft.txt";
    std::ifstream inputFile(themeFile);
    std::string importWord;
    int i = 0;


    while(getline(inputFile, importWord)){
        if(i < 51){
            AllWords[i] = importWord;
            i++;
            std::cout << "New Word: " << importWord << std::endl;
        }
    }
    inputFile.close();


    //Testing Code
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
                std::cout << "Word Already in Array" << std::endl;
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
    return 0;
}

    /*
    for(int i = 0; i < neededWords; i++){
        bool inArray = false;
        newWord = AllWords[i];
        //Check if word is already in array
        //If yes, sets inArray to true and exits for loop
        for(int j = 0; j < i; j++){
            if(newWord == AllWords[j]){
                inArray = true;
                break;
            }
        }
        
        //Word not in chosenWord, adds it to array
        if(inArray == false){
            chosenWordArray[openIndex] = newWord;
            openIndex++;
        }
        */