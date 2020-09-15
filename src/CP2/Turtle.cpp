//
// Created by Aniket Gupta on 9/14/20.
//
#include <iostream>
#include <vector>

using namespace std;

void move(int direction, int &row, int &col) {
    if (direction % 4 == 0) {
        row--;
    } else if (direction % 4 == 1) {
        col++;
    } else if (direction % 4 == 2) {
        row++;
    } else if (direction % 4 == 3) {
        col--;
    }
}

int main() {
    vector<vector<char>> grid (8, vector<char>(8));
    string sequence;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> sequence;
    int direction = 1; // 0: up | 1: right | 2: down | 3 left
    int row = 7;
    int col = 0;

    for (int i = 0; i < sequence.length(); i++) {
        char command = sequence[i];
        if (command == 'R') {
            direction++;
        }
        else if (command == 'L') {
            direction--;
            if (direction < 0) {
                direction = 3;
            }
        }
        else if (command == 'F') {
            move(direction, row, col);

            if (row >= 8 || row <= -1 || col >= 8 ||
                col <= -1 || grid[row][col] == 'I' ||
                grid[row][col] == 'C') {
                cout << "Bug!" << endl;
                return 0;
            }
        }
        else if (command == 'X') {
            int temp_r = row;
            int temp_c = col;
            move(direction, temp_r, temp_c);

            if (temp_r >= 8 || temp_r <= -1 || temp_c >= 8 ||
                    temp_c <= -1 || grid[temp_r][temp_c] != 'I') {
                cout << "Bug!" << endl;
                return 0;
            } else {
                grid[temp_r][temp_c] = '.';
            }
        }

    }
    if (grid[row][col] == 'D') {
        cout << "Diamond!" << endl;
    } else {
        cout << "Bug!" << endl;
    }
}