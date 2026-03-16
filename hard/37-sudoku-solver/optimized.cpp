#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rowMask[9] = {}, colMask[9] = {}, boxMask[9] = {};

    int getBoxIdx(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    // Returns bitmask of available digits at (r, c)
    int getAvailable(int r, int c) {
        int used = rowMask[r] | colMask[c] | boxMask[getBoxIdx(r, c)];
        return (~used) & 0x1FF;  // 9-bit mask (bits 1–9)
    }

    bool solve(vector<vector<char>>& board) {
        // MRV: find the most constrained empty cell
        int bestRow = -1, bestCol = -1, minOptions = 10;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    int avail = getAvailable(r, c);
                    int options = __builtin_popcount(avail);

                    if (options == 0) return false;  // dead end
                    if (options < minOptions) {
                        minOptions = options;
                        bestRow = r;
                        bestCol = c;
                    }
                }
            }
        }

        if (bestRow == -1) return true;  // no empty cells left — solved

        int avail = getAvailable(bestRow, bestCol);

        // Iterate over set bits (available digits)
        while (avail) {
            int bit = avail & (-avail);     // isolate lowest set bit
            avail &= avail - 1;             // clear lowest set bit
            int digit = __builtin_ctz(bit); // bit position = digit - 1

            // Place digit
            board[bestRow][bestCol] = '1' + digit;
            rowMask[bestRow]         |= bit;
            colMask[bestCol]         |= bit;
            boxMask[getBoxIdx(bestRow, bestCol)] |= bit;

            if (solve(board)) return true;

            // Undo
            board[bestRow][bestCol] = '.';
            rowMask[bestRow]         ^= bit;
            colMask[bestCol]         ^= bit;
            boxMask[getBoxIdx(bestRow, bestCol)] ^= bit;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize masks from pre-filled cells
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int bit = 1 << (board[r][c] - '1');
                    rowMask[r]                   |= bit;
                    colMask[c]                   |= bit;
                    boxMask[getBoxIdx(r, c)]     |= bit;
                }
            }
        }
        solve(board);
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