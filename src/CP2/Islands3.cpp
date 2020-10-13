//
// Created by Aniket Gupta on 10/13/20.
//
#include <iostream>
#include <vector>

using namespace std;

const vector<int> dr {-1,0,1,0};
const vector<int> dc {0,1,0,-1};

void dfs(vector<vector<bool>> &seen, vector<vector<char>> &grid, int i, int j, int count) {
    for (int x = 0; x < 4; x++) {
        int nr = i + dr[x];
        int nc = j + dc[x];
        if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
        !seen[nr][nc] && (grid[nr][nc] == 'L' || grid[nr][nc] == 'C')) {
            seen[nr][nc] = true;
            grid[nr][nc] = count;
            dfs(seen, grid, nr, nc, count);
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char x;
            cin >> x;

            grid[i][j] = x;
        }
    }
    int count = 0;

    vector<vector<bool>> seen(r, vector<bool>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!seen[i][j] && grid[i][j] == 'L') {
                seen[i][j] = true;
                grid[i][j] = count;
                dfs(seen, grid, i, j, count++);
            }
        }
    }
    cout << count << '\n';
}



