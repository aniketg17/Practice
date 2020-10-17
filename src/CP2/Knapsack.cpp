//
// Created by Aniket Gupta on 10/15/20.
//
#include <iostream>
#include <vector>

using namespace std;

void solution (vector<int> &weights, vector<int> &values,
               int num_objects, int weight_capacity) {
    // dp[i][j] represents the maximum value achieved using the first i items with weight j
    vector<vector<int>> dp (num_objects + 1, vector<int>(weight_capacity+1, 0));

    for (int i = 1; i <= num_objects; i++) {
        int weight = weights[i - 1];
        int value = values[i - 1];
        for (int j = 1; j <= weight_capacity; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >=  weight) {
                dp[i][j] = max(dp[i][j], value + dp[i-1][j - weight]);
            }
        }
    }
    int i = num_objects;
    int j = weight_capacity;
    vector<int> used;
    while (dp[i][j] != 0) {
        if (dp[i][j] == dp[i-1][j]) {
            i = i-1;
        } else if (dp[i][j] == values[i-1] + dp[i-1][j - weights[i-1]]){
            used.push_back(i-1);
            j = j - weights[i-1];
            i = i - 1;
        } else {
            break;
        }
    }
    cout << used.size() << '\n';
    for (int x : used) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int capacity, num_objects;
    while (cin >> capacity && cin >> num_objects) {
        vector<int> weights;
        vector<int> values;
        for (int i = 0; i < num_objects; i++) {
            int value, weight;
            cin >> value >> weight;
            weights.push_back(weight);
            values.push_back(value);
        }
        solution(weights, values, num_objects, capacity);
    }
}
