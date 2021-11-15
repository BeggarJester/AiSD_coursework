#include "AiSD_coursework_SudokuSolver.h"

int main()
{
    cout << "Create and fill in sudoku board:\n";
    SudokuSolver MySudoku;
    MySudoku.print_sudoku();
    cout << "\n";
    cout << "\n";
    cout << "Solve the sudoku:\n";
    MySudoku.solve_sudoku();
    MySudoku.print_sudoku();
    cout << "\n";
    
}


