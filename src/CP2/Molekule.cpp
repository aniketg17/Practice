//
// Created by Aniket Gupta on 10/13/20.
//
#include <iostream>
#include <vector>

using namespace std;


void dfs(int id, vector<int> &seen, vector<vector<int>> &graph,
         vector<bool> &connections) {
    vector<int> neighbours = graph[id];
    for (int x : neighbours) {
        if (!seen[x]) {
            seen[x] = true;
            connections[x] = !connections[id];
            dfs(x, seen, graph, connections);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<bool> connections(n+1);
    vector<int> seen(n+1);
    vector<pair<int, int>> commands;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        pair p(a, b);
        commands.push_back(p);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    seen[1] = false;
    dfs(1, seen, graph, connections);
    for (auto p : commands) {
        if (connections[p.first]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
