#pragma once
#include <iostream>
#include <array>
#include <cassert>

/*
* A simple struct to store a single cell in the grid
*/

struct Position{
    int row;
    int col;
};

/*
*   Main class that abstracts the solution to the user.
*/

class Grid{
private:

    /*
    Main 2D array that contains the values of the grid. Everything is heap allocated.
    */
    std::array<std::array<int, 9>, 9>* const grid; 

    /*
    Function to find the first cell in the grid of which the value is 0.
    The cells are counted from the top left corner and counted right and down. (Row major order)
    Returns a pointer to a Position struct that contains the position of the first cell with 0.
    Returns nullptr if none of the values in the grid are 0.
    */
    Position* getFirstZero();

    /*
    the function to retrieve which elements are still valid to be inserted into a particular row.
    (Returns the digits that are missing from a certain row.)

    If the i'th value of the returned array is true, that means the digit (i + 1) is safe to 
    be inserted into that row.
    */
    std::array<bool, 9> validateRow(int row) const;

    /*
    the function to retrieve which elements are still valid to be inserted into a particular column.
    (Returns the digits that are missing from a certain column.)

    If the i'th value of the returned array is true, that means the digit (i + 1) is safe to 
    be inserted into that column.
    */
    std::array<bool, 9> validateCol(int col) const;

    /*
    the function to retrieve which elements are still valid to be inserted into a particular mini-grid.
    (Returns the digits that are missing from a certain mini-grid.)

    A mini-grid is a 3x3 sub-grid of the main grid in sudoku. (Not all possible sub-grids. Only the ones
    used in the sudoku game itself.)
    */
    std::array<bool, 9> validateMiniGrid(int x, int y) const;

public:
    /*
    Constructor that takes a pointer to an array containing the values of the grid, which is also
    located in the heap.
    */
    Grid(std::array<std::array<int, 9>, 9>* grid);

    /*
    The destructor is used to delete the heap allocated grid.
    */
    ~Grid();

    /*
    Print the grid.
    */
    void print() const;

    /*
    Solve the current sudoku puzzle residing inside the grid.

    To solve, make the value of the unknown tiles, 0.
    If the puzzle is unsolvale, false is returned. Else true is returned and the grid will be
    changed to its final (solved) state.
    */
    bool solve();
    

};