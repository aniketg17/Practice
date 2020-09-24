//
// Created by Aniket Gupta on 9/22/20.
//
#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int> & arr) {
    int max = -10;
    for (int x : arr) {
        max = std::max(max, x);
    }
    return max;
}

int main() {
    int n, k;
    cin >> n >> k;

    while (n != 0) {
        vector<vector<int>> gallery (n, vector<int>(2));
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(k+1, vector<int>(3, -1)));
        /* dp[i][j][k:0-2] best value that can be achieved
            in first i rows by
            closing j rooms in the first i rows, w/ last row status k.
            k=0 means no closing,
            k=1 means closing room on left column,
            k=2 means closing room on right column
            allocating one extra index in 2nd dim
        */
        for (int i = 0; i < n; i++) {
            cin >> gallery[i][0] >> gallery[i][1];
        }

        dp[0][0][0] = gallery[0][0] + gallery[0][1];
        if (k > 0) {
            dp[0][1][1] = gallery[0][1];
            dp[0][1][2] = gallery[0][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i + 1 && j <= k; j++) { // i+1 because there can be n blocks at nth row
                // also up to k because there can be 0, 1, ... k blocks out of k
                if (get_max(dp[i-1][j]) >= 0) {
                    dp[i][j][0] = gallery[i][0] + gallery[i][1] + get_max(dp[i-1][j]);
                }
                if (j > 0 && max(dp[i-1][j-1][0], dp[i-1][j-1][1]) >= 0) {
                    dp[i][j][1] = gallery[i][1] + max(dp[i-1][j-1][0], dp[i-1][j-1][1]);
                }
                if (j > 0 && max(dp[i-1][j-1][0], dp[i-1][j-1][2]) >= 0) {
                    dp[i][j][2] = gallery[i][0] + max(dp[i-1][j-1][0], dp[i-1][j-1][2]);
                }
            }
        }

        cout << get_max(dp[n-1][k]);
        cin >> n >> k;
    }

}

