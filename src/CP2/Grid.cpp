//
// Created by Aniket Gupta on 10/29/20.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid (n, vector<int>(m));
    vector<vector<bool>> seen (n, vector<bool>(m, false));
    string waste;
    vector<int> dr {0,0,1,-1};
    vector<int> dc {1,-1,0,0};
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j++) {
            int x = line[j] - '0';
            grid[i][j] = x;

        }
    }
    queue<pair<int, int>> q;
    pair p (0,0);
    q.push(p);
    int d = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            pair temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = temp.first + grid[temp.first][temp.second] * dr[i];
                int nc = temp.second + grid[temp.first][temp.second] * dc[i];
                if (nr == n-1 && nc == m-1) {
                    goto found;
                }
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !seen[nr][nc]) {
                    pair<int, int> t2 (nr, nc);
                    q.push(t2);
                    seen[nr][nc] = true;
                }
            }
        }
        ++d;
    }
    cout << -1;
    return 0;
    found: cout << d+1 << '\n';

}
