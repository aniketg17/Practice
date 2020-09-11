//
// Created by Aniket Gupta on 9/11/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> ret;
vector<int> result;
int curr_sum;
int target;
int min_sz = 1000000;

void runner(vector<int> &vals, int start) {
    if (start == vals.size() || curr_sum >= target) {
        if (curr_sum == target && result.size() < min_sz) {
            ret = result;
            min_sz = result.size();
        }
        return;
    }
    result.push_back(vals[start]);
    curr_sum += vals[start];
    runner(vals, start + 1);
    result.pop_back();
    curr_sum -= vals[start];
    runner(vals, start + 1);
}

int main() {
    vector<int> input{1,3,2,4,5,8};// assuming no duplicates
    unordered_map<int, int> idx;
    int i = 0;
    for (int x : input) {
        idx[x] = i++;
    }
    int val = 5; // local tests with 23, 26, 40
    target = val;
    curr_sum = 0;
    sort(input.begin(), input.end(), greater()); // sort in descending for greedy approach
    runner(input, 0);
    vector<int> combo;
    for (int x : ret) {
        combo.push_back(idx[x]);
    }
    sort(combo.begin(), combo.end());
    for (int x : combo) {
        cout << x << " ";
    }
}
