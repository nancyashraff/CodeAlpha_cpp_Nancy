//Sudoku Solver
//It is implementation of a Sudoku solver using the backtracking algorithm. This program will solve a given Sudoku puzzle from a 9x9 grid.

#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Check if it's safe to place a number in the given position
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num; // Place the number

                        // Recursively try to solve
                        if (solveSudoku(grid)) {
                            return true;
                        }

                        // If not valid, reset and try next number
                        grid[row][col] = 0;
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

int main() {
    // Sample Sudoku puzzle (0 represents empty cells)
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku grid:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku grid:\n";
        printGrid(grid);
    }
    else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
