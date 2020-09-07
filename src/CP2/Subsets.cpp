//
// Created by Aniket Gupta on 9/4/20.
//
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

class Solution {

public:
    vector<vector<int>> list;
    vector<int> v;

    void backtrack(vector<int> &nums, int start) {
        list.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            backtrack(nums, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return list;
    }
};

int main() {
    Solution s;
    vector<int> vec {1,2,3};
    vector<vector<int>> res = s.subsets(vec);
    for (vector<int> &list : res) {
        for (int x : list) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

