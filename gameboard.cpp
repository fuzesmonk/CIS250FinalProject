#include <iostream>
#include "MemoryMatch.hpp"

//Use unicode to display gameboard
//Unicode Reference: https://unicode.org/charts/nameslist/n_2500.html 
class gameboard : public MemoryMatch{

    private:
        int neededBoardSize;
        char tableColumn[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        std::string wordLocation;
        bool themeSelected = false;
        const int constCellWidth = 8;
        std::string * ptrWordArray = nullptr;
        int rows;
        int cols;

    public:
        gameboard(){
            MemoryMatch mainWords;
            neededBoardSize = mainWords.sizeSelect();
            themeSelected = mainWords.themeSelect();
            ptrWordArray = mainWords.getWords();
            std::string **hiddenValues = new std::string*[rows];
            for(int i = 0; i < rows; i++){
                hiddenValues[i] = new std::string[cols];
            }

            rows, cols = {neededBoardSize};
            printBoard(ptrWordArray, constCellWidth, rows, cols);
        }
        void printBoard(std::string *wordArray, const int cellWidth, int rows, int cols){
            for(int col = 0; col < cols; ++col){
                std::cout << std::setw(cellWidth) << col + 1 << std::endl;
            }
            //Top Border
            for(int col = 0; col < cols; ++col){
                std::cout <<  std::string(cellWidth - 1, '\u2550') << '\u2566';
            }
            std::cout << std::string(cellWidth - 1, '\u2550') << '\u2557';
            //Board Rows
            for(int row = 0; row < rows; ++rows){
                std::cout << std::setw(2) << row + 1 << '\u2551';
                for(int col = 0; col < cols; ++col){
                    std::cout << std::setw(cellWidth - 1) << wordArray[row][col] << '\u2551';
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
            std::cout << "    \u255A";
            for(int col = 0; col < cols - 1; ++col){
                std::cout << std::string(cellWidth - 1, '\u2550') << '\u2569';
                }
            std::cout << std::string(cellWidth - 1, '\u2550') << '\u255D';
            }
};