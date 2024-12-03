#include <iostream>
#include "MemoryMatch.hpp"
#include <map>

//Use unicode to display gameboard
//Unicode Reference: https://unicode.org/charts/nameslist/n_2500.html 
class gameboard : public MemoryMatch{

    private:
        int neededBoardSize;
        char tableColumn[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        std::map<std::string, std::string> words;
        std::string wordLocation;
        bool themeSelected = false;



    public:
        gameboard(){
            MemoryMatch mainWords;
            neededBoardSize = mainWords.sizeSelect();
            themeSelected = mainWords.themeSelect();
            //[Columns][Rows]
            //Setting Words into places
            std::string wordArray[neededBoardSize][neededBoardSize];
            for(int i = 0; i < neededBoardSize; i++){
                for(int j = 0; j < neededBoardSize; j++){
                    wordLocation = tableColumn[i] + std::to_string(j);
                    
                }
            }
        }
};