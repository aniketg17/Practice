//
// Created by Aniket Gupta on 10/23/20.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    vector<vector<int>> graph(c + 1, vector<int>());
    vector<int> degree (c + 1, 0);
    vector<int> odegree (c + 1, 0);
    vector<bool> seen (c+1, false);
    for (int i = 0; i < p; i++) {
        int z,y;
        cin >> z >> y;
        graph[z].push_back(y);
        graph[y].push_back(z);
        degree[z]++;
        degree[y]++;
        odegree[z]++;
        odegree[y]++;
    }
    queue<int> q;
    q.push(l);
    seen[l] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        vector<int> neighbours = graph[curr];
        for (int n : neighbours) {
            degree[n]--;
            degree[curr]--;
            if (degree[n] <= odegree[n] / 2 && !seen[n]) {
                q.push(n);
                seen[n] = true;
            }
        }
    }
    if (degree[x] <= odegree[x] / 2) {
        cout << "leave" << '\n';
    } else {
        cout << "stay" << '\n';
    }
}