//
// Created by Aniket Gupta on 11/14/20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int z;
    cin >> z;
    while (z > 0) {
        int n, m;
        cin >> n >> m;
        vector<int> vertices (n+1);
        unordered_map<int, vector<int>> graph;
        for (int i = 1; i < n+1; i++) {
            vertices[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        unordered_map<int, vector<int>> prev;
        queue<int> q;
        q.push(1);
        vector<bool> seen(n+1);
        seen[1] = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> d;
            for (int k = 0; k < sz; k++) {
                int curr = q.front();
                q.pop();
                if (curr == 2) {
                    goto here;
                }
                vector<int> neighbours = graph[curr];
                for (int x : neighbours) {
                    if (!seen[x]) {
                        q.push(x);
                        prev[x].push_back(curr);
                        d.push_back(x);
                    }
                }
            }
            for (int a : d) {
                seen[a] = true;
            }
        }
        here: queue<int> q2;
        q2.push(2);
        seen.clear();
        seen.resize(n+1, false);
        seen[2] = true;
        while (!q2.empty()) {
            int curr = q2.front();
            q2.pop();
            vector<int> ns = prev[curr];
            for (int x : ns) {
                if (!seen[x]) {
                    q2.push(x);
                    seen[x] = true;
                }
            }
        }
        if (seen[3]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        --z;
    }
}