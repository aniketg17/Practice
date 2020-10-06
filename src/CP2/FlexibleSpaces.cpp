//
// Created by Aniket Gupta on 10/6/20.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,p;
    cin >> n >> p;
    vector<int> rooms(n+1);
    vector<int> partitions;
    vector<bool> distances(n+1);
    distances[n] = true;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        distances[x] = true;
        distances[n - x] = true;
        partitions.push_back(x);
    }
    for (int i = 0; i < partitions.size(); i++) {
        for (int j = 0; j < i; j++) {
            distances[partitions[i] - partitions[j]] = true;
        }
    }
    for (int i = 1; i < rooms.size(); i++) {
        if (distances[i]) {
            cout << i << " ";
        }
    }
}