#include "SudokuGrid.h"
#include <cstring>

int main(){

    std::array<std::array<int, 9>, 9> gridStack = {
        0, 0, 0,    0, 0, 1,    0, 9, 0,
        0, 2, 4,    3, 6, 0,    0, 0, 0,
        6, 1, 0,    0, 0, 0,    4, 0, 0,

        8, 6, 0,    5, 9, 3,    7, 0, 4,
        2, 7, 9,    6, 0, 4,    5, 0, 1,
        0, 0, 3,    0, 0, 0,    9, 0, 8,

        7, 0, 0,    9, 1, 0,    0, 4, 0,
        0, 0, 2,    0, 0, 0,    6, 0, 0,
        0, 0, 0,    8, 0, 6,    3, 7, 0
    }; 

    //Creating the above grid in the heap for encapsulation purposes
    std::array<std::array<int, 9>, 9>* gridHeap = new std::array<std::array<int, 9>, 9>;

    //Memcpy can be used since all the data in both arrays are contigous
    memcpy(gridHeap, &gridStack[0][0], 81 * sizeof(int));

    Grid grid(gridHeap);
    grid.solve();
    grid.print();

}
