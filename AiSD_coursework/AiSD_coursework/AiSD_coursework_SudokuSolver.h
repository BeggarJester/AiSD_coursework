#pragma once
#include <iostream>
#include <fstream>
#include "AiSD_coursework_SudokuArray.h"

using namespace std;

// class SudokuSolver for solse the sudoku puzzles
class SudokuSolver {
private:
    char board[9][9]; // bivariate masive for sudoku storage;

    // sudoku board step by step completion
    bool solve(char(*board)[9], size_t index) {
        if (index == 81)
            return true;

        const int row = index / 9;
        const int column = index % 9;

        if (board[row][column] != '.')
            return solve(board, index + 1);

        for (char cell = '1'; cell <= '9'; ++cell) {
            if (digitCheck(board, row, column, cell)) {
                board[row][column] = cell;
                if (solve(board, index + 1))
                    return true;
                board[row][column] = '.';
            }
        }

        return false;
    }

    // check that digit is valid for this position
    bool digitCheck(char(*board)[9], int row, int column, char digit) {
        for (int i = 0; i < 9; ++i)
            if (board[i][column] == digit || board[row][i] == digit || board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == digit)
                return false;
        return true;
    }
public:

    // Consrtructor of SudokuSolver
    SudokuSolver() {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                board[i][j] = sudoku_array[i][j];
            }
    }

    // Desrtructor of SudokuSolver
    ~SudokuSolver() {
        delete[] board;
    }

    // print the sudoku board
    void print_sudoku() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }

    // get the sudoku board element by position
    char at(size_t row, size_t column) {
        if (row < 9 && column < 9) {
            return board[row][column];
        }
        else {
            throw out_of_range("There is not sudoku element at that position");
        }
    }

    // solve the sudoku
    void solve_sudoku() {
        solve(board, 0);
    }

};