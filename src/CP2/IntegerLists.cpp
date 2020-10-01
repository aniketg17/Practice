//
// Created by Aniket Gupta on 10/1/20.
//
#include <iostream>
#include <deque>

using namespace std;

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string commands;
        cin >> commands;
        int k;
        cin >> k;
        deque<int> nums;
        char empty;
        cin >> empty;
        if (k == 0) {
            cin >> empty;
        } else {
            while (nums.size() != k) {
                int x;
                cin >> x;
                nums.push_back(x);
                cin >> empty;
            }
        }
        bool order = true; // normal = true
        bool restart = false;
        for (int j = 0; j < commands.size(); j++) {
            if (commands[j] == 'R') {
                order = !order;
            } else {
                if (nums.empty()) {
                    cout << "error" << '\n';
                    restart = true;
                    break;
                } else if (order) {
                    nums.pop_front();
                } else {
                    nums.pop_back();
                }
            }
        }
        if (restart) continue;
        cout << "[";
        if (!order) {
            for (int l = nums.size() - 1; l >= 0; l--) {
                if (l == 0) {
                    cout << nums[l];
                } else {
                    cout << nums[l] << ",";
                }
            }
        } else {
            for (int l = 0; l < nums.size(); l++) {
                if (l == nums.size() - 1) {
                    cout << nums[l];
                } else {
                    cout << nums[l] << ",";
                }
            }
        }
        cout << "]\n";
    }
}
