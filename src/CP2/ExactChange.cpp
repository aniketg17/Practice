//
// Created by Aniket Gupta on 10/14/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int amount;
        cin >> amount;
        int num_coins;
        cin >> num_coins;
        vector<int> coins;
        int max_denom = -1;
        for (int j = 0; j < num_coins; j++) {
            int x;
            cin >> x;
            max_denom = max(max_denom, x);
            coins.push_back(x);
        }
        int m = max_denom + amount + 1;
        vector<vector<int>> dp (coins.size() + 1, vector<int>(m+1, coins.size() + 1));
        // dp[i][j] means the minimum number of coins used using the first i values for amount j
        dp[0][0] = 0;
        int min_amt = m;
        int min_num = coins.size() + 1;
        for (int j = 1; j <= coins.size(); j++) {
            for (int k = 0; k <= m; k++) {
                if (k == 0) {
                    dp[j][k] = 0;
                    continue;
                }
                int dont_take = dp[j - 1][k];
                int take = INT32_MAX;
                if (k >= coins[j - 1]) {
                    take = 1 + dp[j-1][k - coins[j - 1]];
                }
                int mini = min(dont_take, take);
                dp[j][k] = min(mini, dp[j][k]);
                if (k >= amount && dp[j][k] <= coins.size()) {
                    if (k == min_amt) {
                        min_num = min(min_num, dp[j][k]);
                    } else if (k < min_amt) {
                        min_amt = k;
                        min_num = dp[j][k];
                    }
                }
            }
        }
        cout << min_amt << " " << min_num << "\n";
    }
}