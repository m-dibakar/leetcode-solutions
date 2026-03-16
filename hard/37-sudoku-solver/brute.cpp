#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<vector<char>>& board, int row, int col, int digit) {
        char ch = '0' + digit;

        // check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
        }

        // check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch) return false;
        }

        // check 3x3 box
        int stRow = (row / 3) * 3;
        int stCol = (col / 3) * 3;
        for (int i = stRow; i <= stRow + 2; i++) {
            for (int j = stCol; j <= stCol + 2; j++) {
                if (board[i][j] == ch) return false;
            }
        }

        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;   

        int nextRow = row;
        int nextCol = col + 1;
        if (col + 1 == 9) {
            nextRow = row + 1;
            nextCol = 0;            
        }

        if (board[row][col] != '.') {
            return sudokuSolver(board, nextRow, nextCol);
        }

        for (int digit = 1; digit <= 9; digit++) {
            if (isSafe(board, row, col, digit)) {
                board[row][col] = '0' + digit;  
                if (sudokuSolver(board, nextRow, nextCol)) return true;
                board[row][col] = '.';           // backtrack
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sol.solveSudoku(board);

    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }
    return 0;
}