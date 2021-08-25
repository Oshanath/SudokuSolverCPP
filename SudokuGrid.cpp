#include "SudokuGrid.h"

Grid::Grid(std::array<std::array<int, 9>, 9>* grid): grid(grid){}

Grid::~Grid(){
    delete grid;
}

void Grid::print() const{

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            std::cout << grid->at(i).at(j) << " ";

            /*
            Printing an extra space to make margins more visible.
            */
            if(j % 3 == 2)
                std::cout << " ";
        }
        std::cout << std::endl;

        /*
        Printing an extra newline to make margins more visible.
        */
        if(i % 3 == 2)
            std::cout << std::endl;
    }

}

Position* Grid::getFirstZero(){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if((*grid)[i][j] == 0){
                Position* positionPtr = new Position;
                positionPtr->row = i;
                positionPtr->col = j;
                return positionPtr;
            }
        }
    }

    return nullptr;

}

std::array<bool, 9> Grid::validateRow(int row) const{

    std::array<bool, 9> counts;

    for(int i = 0; i < 9; i++){
        counts[i] = true;
    }

    for(int i = 0; i < 9; i++){
        counts[(*grid)[row][i] - 1] = false;
    }

    return counts;

}

std::array<bool, 9> Grid::validateCol(int col) const{

    std::array<bool, 9> counts;

    for(int i = 0; i < 9; i++){
        counts[i] = true;
    }

    for(int i = 0; i < 9; i++){
        counts[(*grid)[i][col] - 1] = false;
    }

    return counts;

}

std::array<bool, 9> Grid::validateMiniGrid(int x, int y) const{

    assert(x < 3 && y < 3);

    std::array<bool, 9> counts;

    for(int i = 0; i < 9; i++){
        counts[i] = true;
    }

    for(int i = x * 3; i < x * 3 + 3; i++){
        for(int j = y * 3; j < y * 3 + 3; j++){
            counts[(*grid)[i][j] - 1] = false;
        }
    }

    return counts;

}

bool Grid::solve(){

    Position* firstZero = getFirstZero();

    // Base case
    if(firstZero == nullptr){
        return true;
    }

    int originalValue = (*grid)[firstZero->row][firstZero->col];

    //Generate valid digits
    std::array<bool, 9> validDigitsRow = validateRow(firstZero->row);
    std::array<bool, 9> validDigitsCol = validateCol(firstZero->col);
    std::array<bool, 9> validDigitsMiniGrid = validateMiniGrid(firstZero->row / 3, firstZero->col / 3);

    std::array<bool, 9> validDigits;

    for(int i = 0; i < 9; i++){
        validDigits[i] = validDigitsRow[i] && validDigitsCol[i] && validDigitsMiniGrid[i];
    }

    for(int i = 0; i < 9; i++){
        if(validDigits[i]){

            int digit = i + 1;

            (*grid)[firstZero->row][firstZero->col] = digit;
            bool result = solve();

            if(result)
                return true;
            
        }
    }

    (*grid)[firstZero->row][firstZero->col] = originalValue;
    delete firstZero;
    return false;

}
