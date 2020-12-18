//
// Created by Aniket Gupta on 12/18/20.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n > 0) {
        string line;
        cin >> line;
        int sz = line.size();
        int root = sqrt(sz);
        int m = root;
        if (root*root != sz) {
            m = root + 1;
        }
        vector<vector<char>> chars (m, vector<char>(m, 0));
        int k = 0;
        for (int i = 0; i < m && k < line.size(); i++) {
            for (int j = 0; j < m && k < line.size(); j++) {
                chars[i][j] = line[k++];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = m-1; j >= 0; j--) {
                if (chars[j][i] != 0) {
                    cout << chars[j][i];
                }
            }
        }
        cout << '\n';
        --n;
    }
}