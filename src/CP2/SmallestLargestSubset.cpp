//
// Created by Aniket Gupta on 9/11/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> combinations;
vector<int> result;
int curr_sum;
int target;
bool done;

void runner(vector<int> &vals, int start) {
    if (start == vals.size() || curr_sum >= target) {
        if (curr_sum == target && combinations.empty()) {
            combinations.push_back(result);
            done = true;
        }
        return;
    }
    // two choices. take current element or dont
    if (!done) {
        // use
        result.push_back(vals[start]);
        curr_sum += vals[start];
        runner(vals, start + 1);
        // dont use
        result.pop_back();
        curr_sum -= vals[start];
        runner(vals, start+1);
    }
}

int main() {
    vector<int> input {1,2,6,3,17,82,23,234};// assuming no duplicates
    unordered_map<int, int> idx;
    done = false;
    int i = 0;
    for (int x : input) {
        idx[x] = i++;
    }
    int val = 40; // local tests with 23, 26, 40
    target = val;
    curr_sum = 0;
    sort(input.begin(), input.end(), greater()); // sort in descending for greedy approach
    runner(input, 0);
    vector<int> combo = combinations[0];
    sort(combo.begin(), combo.end());
    for (int x : combo) cout << idx[x] << " ";
}