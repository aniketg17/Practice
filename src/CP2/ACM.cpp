//
// Created by Aniket Gupta on 10/27/20.
//
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

void unionize(vector<int> &parents, int a, int b, vector<int> &sizes) {
    parents[b] = a;
    sizes[a] += sizes[b];
}

int find(vector<int> &parents, int a) {
    while (parents[a] != a) {
        a = parents[a];
        parents[a] = parents[parents[a]];
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> parents (500001, 0);
    vector<int> sizes (500001, 1);
    for (int i = 0; i <= 500001; i++) {
        parents[i] = i;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        unordered_set<int> groups;
        int total = 0;
        for (int j = 0; j < m; j++) {
            int o;
            cin >> o;
            int parent = find(parents, o);
            if (groups.find(parent) != groups.end()) {
                continue;
            }
            groups.insert(parent);
            total += sizes[parent];
        }
        if (m != total) {
            continue;
        }
        int flag = -1;
        for (int group : groups) {
            if (flag == -1) {
                flag = group;
            } else {
                unionize(parents, flag, group, sizes);
            }
        }
        ++count;
    }
    cout << count;
}