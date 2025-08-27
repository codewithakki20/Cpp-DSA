#include <bits/stdc++.h>
using namespace std;

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit) {
    // vertical check
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) return false;
    }

    // horizontal check
    for (int j = 0; j < 9; j++) {
        if (sudoku[row][j] == digit) return false;
    }

    // 3x3 grid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == digit) return false;
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if (row == 9) { // sudoku solved
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if (col == 8) { // end of row, move to next row
        nextRow = row + 1;
        nextCol = 0;
    }

    if (sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;

            if (sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            }

            // backtrack
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int sudoku[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout << sudokuSolver(sudoku, 0, 0) << endl;

    return 0;
}
