//
// Created by Aniket Gupta on 9/7/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


int total = 0;

void backtrack(int sum, vector<int> &fruits, int start) {
    total += sum;
    if (fruits[start] + sum >= 200) {
        return;
    }

    for (int i = start; i < fruits.size() && sum + fruits[i] < 200; i++) {
        sum += fruits[i];
        backtrack(sum, fruits, i + 1);
        sum -= fruits[i];
    }
}

int main() {
    int num;
    int sumW = 0;
    vector<int> fruits;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int a;
        cin >> a;
        fruits.push_back(a);
        sumW += a;
    }
    sort(fruits.begin(), fruits.end());
    int sum = 0;
    backtrack(sum, fruits, 0);
    ll a = 1LL << (num - 1);
    ll totalWeight = a * sumW;
    cout << totalWeight - total << endl;
}
