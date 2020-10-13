//
// Created by Aniket Gupta on 10/13/20.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int move = 0;
        vector<int> parent(n+1);
        vector<int> marbles(n+1);
        vector<int> degree(n+1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int id, num_marbles, children;
            cin >> id >> num_marbles >> children;
            degree[id] = children;
            marbles[id] = num_marbles;
            for (int j = 0; j < children; j++) {
                int x;
                cin >> x;
                parent[x] = id;
            }
            if (children == 0) {
                q.push(id);
            }
        }

        while (!q.empty()) {
            int id =q.front();
            q.pop();
            int new_count = marbles[id] - 1;
            move += abs(new_count);
            int p = parent[id];
            degree[p]--;
            if (degree[p] == 0) {
                q.push(p);
            }
            marbles[p] += new_count;
        }
        cout << move << '\n';
    }
}
