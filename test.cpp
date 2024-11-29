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
    char tableColumn[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int neededFormat = 4;
    int neededColumns = neededFormat;
    int neededRows = neededFormat;
    std::string wordLocation;
    //[Columns][Rows]
    std::string wordArray[neededFormat][neededFormat];
    for(int i = 0; i < neededFormat; i++){
        for(int j = 0; j < neededFormat; j++){
            wordLocation = tableColumn[i] + std::to_string(j);
            std::cout << "DEBUG wordLocation: " << wordLocation << std::endl;
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