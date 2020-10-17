//
// Created by Aniket Gupta on 10/17/20.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_hotdogs, num_buns;
    cin >> num_hotdogs;
    if (num_hotdogs == 0) {
        cout << "impossible\n";
        return 0;
    }
    vector<int> hotdogs;
    int sum_hotdogs = 0, sum_buns = 0;
    for (int i = 0; i < num_hotdogs; i++) {
        int x;
        cin >> x;
        sum_hotdogs += x;
        hotdogs.push_back(x);
    }
    vector<int> dp_hotdogs (1 + sum_hotdogs, num_hotdogs + 10);
    dp_hotdogs[0] = 0;
    // dp_hotdogs[j] = minimum number of hotdogs used for amount j
    for (int i = 0; i < num_hotdogs; i++) {
        for (int j = sum_hotdogs; j >= hotdogs[i]; j--) {
            dp_hotdogs[j] = min(dp_hotdogs[j], 1 + dp_hotdogs[j - hotdogs[i]]);
        }
    }
    cin >> num_buns;
    if (num_buns == 0) {
        cout << "impossible\n";
        return 0;
    }
    vector<int> buns;
    for (int i = 0; i < num_buns; i++) {
        int x;
        cin >> x;
        sum_buns += x;
        buns.push_back(x);
    }
    vector<int> dp_buns (1 + sum_buns, num_buns + 10);
    dp_buns[0] = 0;
    for (int i = 0; i < num_buns; i++) {
        for (int j = sum_buns; j >= buns[i]; j--) {
            dp_buns[j] = min(dp_buns[j], 1 + dp_buns[j - buns[i]]);
        }
    }
    int i = 1;
    int j = 1;
    int mini = num_hotdogs + num_buns + 5;
    while (i < dp_hotdogs.size() && j < dp_buns.size()) {
        if (dp_hotdogs[i] != num_hotdogs+10 && dp_buns[j] != num_buns+10) {
            mini = min(mini, dp_hotdogs[i] + dp_buns[j]);
        }
        ++i;
        ++j;
    }
    if (mini < num_buns + num_hotdogs + 5) {
        cout << mini << '\n';
    } else {
        cout << "impossible\n";
    }
}
/*
4 2 3 5 6
4 4 5 9 1
 */