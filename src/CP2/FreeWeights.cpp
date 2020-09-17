// Created by Aniket Gupta on 9/15/20.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


using namespace std;

vector<vector<int>> weights;
vector<int> individual_set;

bool ordered(int idx) {
    int w = individual_set[idx];
    for (int i = 0; i < weights.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < weights[i].size(); j++) {
            if (weights[i][j] < w) {
                continue;
            } else {
                temp.push_back(weights[i][j]);
            }
        }
        if (temp.size() % 2 == 1) return false;
        for (int k = 1; k < temp.size(); k+= 2) {
            if (temp[k] != temp[k-1]) {
                return false;
            }
        }
    }
    return true;
}


int binary_search(int low, int high) {
    while (low <= high) {
        if (low == high) return low;
        if (low + 1 == high) {
            if (ordered(low)) return low;
            else return high;
        }
        int mid = low/2 + high/2;
        if (ordered(mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    unordered_set<int> seen;
    vector<vector<int>> grid (2, vector<int>(n));

    vector<int> list;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (seen.find(grid[i][j]) == seen.end()) {
                list.push_back(grid[i][j]);
            }
        }
    }
    sort(list.begin(), list.end());
    individual_set = list;
    weights = grid;
    bool ans = ordered(0);
    if (ans) {
        cout << 0;
        return 0;
    }
    int val = binary_search(0, individual_set.size() - 1);
    cout << list[val - 1];
}


