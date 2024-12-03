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
    int neededColumns = neededFormat - 1;
    int neededRows = neededFormat - 1;
    std::string wordLocation;
    //[Columns][Rows]
    std::string * wordArray[neededFormat][neededFormat];
    for(int i = 0; i < neededFormat; i++){
        for(int j = 0; j < neededFormat; j++){
            wordLocation = tableColumn[i] + std::to_string(j);
            //std::cout << "DEBUG wordLocation: " << wordLocation << std::endl;
        }
    }
    std::string  tableRowChar = "\u2550";
    std::string tableRowIntersection = "\u256C";
    std::string tableColumnChar = "\u2551";

    //Generating Gameboard
    //Use Array of Strings which are generated based on needed Rows
     
    int rows;
    int cols;
    const int cellWidth = 8;
    switch(neededFormat){
        case 4:
            rows = 15;
            cols = 35;
            break;

        case 6:
            rows = 23;
            cols = 53;
            break;

        case 8:
            rows = 31;
            cols = 70;
            break;
    }
    //Header
    for(int col = 0; col < cols; ++col){
        std::cout << std::setw(cellWidth) << col + 1 << std::endl;
    }
    //Top Border
    for(int col = 0; col < cols; ++col){
        std::cout << std::string(cellWidth - 1, '\u2550') << '\u2566';
    }
    std::cout << std::string(cellWidth - 1, '\u2550') << '\u2557';
    //Board Rows
    for(int row = 0; row < rows; ++rows){
        std::cout << std::setw(2) << row + 1 << '\u2551';
        for(int col = 0; col < cols; ++col){
            std::cout << std::setw(cellWidth - 1) << *wordArray[row][col] << '\u2551';
        }
        std::cout << std::endl;

        if(row < rows - 1){
            std::cout << "    \u255F";
            for(int col = 0; col < cols; ++col){
                std::cout << std::string(cellWidth - 1, '\u2550') << '\u256C';
            }
            std::cout << std::string(cellWidth - 1, '\u2550') << '\u2563';
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