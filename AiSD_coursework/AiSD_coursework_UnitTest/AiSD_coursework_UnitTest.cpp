#include "pch.h"
#include "CppUnitTest.h"

#include "../AiSD_coursework/AiSD_coursework_SudokuSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSDcourseworkUnitTest
{
	TEST_CLASS(AiSDcourseworkUnitTest)
	{
	public:
		TEST_METHOD(ConsrtructorSudokuSolverTest) {
			SudokuSolver MySudokuSolver;
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					Assert::IsTrue(MySudokuSolver.at(i, j) != '0');
				}
			}
		}
		TEST_METHOD(PrintSudokuSolverTest) {
			SudokuSolver MySudokuSolver;
			string output_string = "";
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					output_string += MySudokuSolver.at(i, j);
				}
			}
			Assert::IsTrue(output_string  == "53..7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79");
			MySudokuSolver.solve_sudoku();
			output_string = "";
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					output_string += MySudokuSolver.at(i, j);
				}
			}
			Assert::IsTrue(output_string == "534678912672195348198342567859761423426853791713924856961537284287419635345286179");
		}
		TEST_METHOD(AtSudokuSolverTest) {
			SudokuSolver MySudokuSolver;
			try {
				MySudokuSolver.at(0, 2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not sudoku element at that position", error.what());
			}
			Assert::IsTrue(MySudokuSolver.at(0, 2) == '.');
			MySudokuSolver.solve_sudoku();
			try {
				MySudokuSolver.at(0, 2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not sudoku element at that position", error.what());
			}
			Assert::IsTrue(MySudokuSolver.at(0, 2) == '4');
			try {
				MySudokuSolver.at(10, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not sudoku element at that position", error.what());
			}
			try {
				MySudokuSolver.at(0, 20);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not sudoku element at that position", error.what());
			}
		}
		TEST_METHOD(SolveSudokuTest) {
			SudokuSolver MySudokuSolver;
			Assert::IsTrue(MySudokuSolver.at(0, 2) == '.');
			MySudokuSolver.solve_sudoku();
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					Assert::IsTrue(MySudokuSolver.at(i, j) != '.');
				}
			}
		}
		TEST_METHOD(DigitCheckTest) {
			SudokuSolver MySudokuSolver;
			MySudokuSolver.solve_sudoku();
			char temp = MySudokuSolver.at(0, 0);
			for (int i = 1; i < 9; ++i) {
				Assert::IsTrue(MySudokuSolver.at(i, 0) != temp);
				Assert::IsTrue(MySudokuSolver.at(0, i) != temp);
			}
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) {
					if (i != 0 || j != 0) Assert::IsTrue(MySudokuSolver.at(i, j) != temp);
				}
		}
		TEST_METHOD(SolveSudokuSolverTest) {
			SudokuSolver MySudokuSolver;
			Assert::IsTrue(MySudokuSolver.at(0, 2) == '.');
			MySudokuSolver.solve_sudoku();
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					Assert::IsTrue(MySudokuSolver.at(i, j) != '.');
				}
			}
		}
	};
}
