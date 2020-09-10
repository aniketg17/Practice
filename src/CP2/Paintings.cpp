//
// Created by Aniket Gupta on 9/10/20.
//
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int num_ways;
int n;
vector<int> result;
unordered_map<int, string> int_to_color;

void get_painting (unordered_set<int> &seen, vector<vector<bool>> &grid,
                   vector<int> &colors, int curr, int combination[]) {
    if (curr == n) {
        num_ways++;
        if (result.empty()) {
            for (int x = 0; x < curr; x++) {
                result.push_back(combination[x]);
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (seen.find(i) != seen.end() || (curr != 0 && grid[i][combination[curr-1]])) {
            continue;
        }
        combination[curr] = i;
        seen.insert(i);
        get_painting(seen, grid, colors, curr+1, combination);
        seen.erase(i);
    }
}

void process_sequence() {
    int num_colors;
    cin >> num_colors;
    n = num_colors;
    int combination[n];
    unordered_map<string, int> color_to_int;
    int_to_color.clear();
    vector<int> colors;
    for (int i = 0; i < num_colors; i++) {
        string color;
        cin >> color;
        colors.push_back(i);
        color_to_int[color] = i;
        int_to_color[i] = color;
    }
    int bad_col;
    cin >> bad_col;

    vector<vector<bool>> grid(n, vector<bool>(n, false));
    unordered_set<int> seen;
    result.clear();
    result.resize(0);
    for (int i = 0; i < bad_col; i++) {
        string col1;
        string col2;
        cin >> col1 >> col2;
        int id1 = color_to_int.at(col1);
        int id2 = color_to_int.at(col2);
        grid[id1][id2] = true;
        grid[id2][id1] = true;
    }
    num_ways = 0;
    get_painting(seen, grid, colors, 0, combination);
    cout << num_ways << endl;
    for (int x = 0; x < n; x++) {
        if (x < n - 1) {
            cout << int_to_color[result[x]] + " ";
        } else {
            cout << int_to_color[result[x]];
        }
    }
    cout << '\n';
}

//int main() {
//    int num_cases;
//    cin >> num_cases;
//
//    for (int i = 0; i < num_cases; i++) {
//        process_sequence();
//    }
//}