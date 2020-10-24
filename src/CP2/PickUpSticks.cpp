//
// Created by Aniket Gupta on 10/24/20.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> degree (n+1, 0);
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < m; i++) {
        int top, below;
        cin >> top >> below;
        if (graph[top].find(below) == graph[top].end()) {
            graph[top].insert(below);
            degree[below]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    int i = 1;
    vector<int> answer (n+1, 0);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        answer[i++] = curr;
        unordered_set<int> neighbours = graph[curr];
        for (int x : neighbours) {
            degree[x]--;
            if (degree[x] == 0) {
                q.push(x);
            }
        }
    }
    if (i == n+1) {
        for (int j = 1; j < n+1; j++) {
            cout << answer[j] << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

