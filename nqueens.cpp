#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    // Check the column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
    // If all queens are placed, add the solution to the result
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';  // Place the queen
            solve(row + 1, board, solutions, n);  // Recurse to the next row
            board[row][col] = '.';  // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));  // Initialize the board with '.'
    solve(0, board, solutions, n);
    return solutions;
}

int main() {
    int n = 8;  // Example with 8-queens
    vector<vector<string>> solutions = solveNQueens(n);

    // Print all solutions
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
