//THIS CODE DOESN'T WORK
//TRY TO CORRECT IT

#include <bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, bool>> &mp, vector<map<int, bool>> &row, vector<map<int, bool>> &col) {
    if (r == 9) {
        for (auto it : a) {
            for (auto i : it) {
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    if (c == 9) {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] != '.') {
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        int rw = (r / 3)*3, cl = (c / 3)*3;
        if (!mp[{rw, cl}][i] && !row[r][i] && !col[c][i]) {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c + 1, a, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }

    // Added to indicate no solution found
    if (r == 0 && c == 0) {
        cout << "No solution found" << endl;
    }
}

void sudokusolve(vector<vector<char>> &a) {
    map<pair<int, int>, map<int, bool>> mp;
    vector<map<int, bool>> row(9);
    vector<map<int, bool>> col(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] != '.') {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;
                row[i][a[i][j] - '0'] = 1;
                col[i][a[i][j] - '0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}


int main() {
    // Example Sudoku puzzle
    vector<vector<char>> sudoku = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

    sudokusolve(sudoku);
    
}