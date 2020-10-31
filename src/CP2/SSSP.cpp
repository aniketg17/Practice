//
// Created by Aniket Gupta on 10/31/20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class edge {
public:
    int u, w;

    edge(int u, int w) : u(u), w(w) {}
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;
        vector<int> dists (n, 100000000);
        unordered_map<int, vector<pair<int,int>>> graph;
        dists[s] = 0;
        auto comp = [&] (int a, int b) {
            return dists[a] > dists[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0; i < n; i++) {
            pq.push(i);
        }
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            pair p(y, z);
            graph[x].push_back(p);
        }
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            vector<pair<int, int>> neigh = graph[curr];
            for (auto p : neigh) {
                if (dists[curr] + p.second < dists[p.first]) {
                    dists[p.first] = dists[curr] + p.second;
                    pq.push(p.first);
                }
            }
        }
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (dists[x] == 100000000) {
                cout << "Impossible\n";
            } else {
                cout << dists[x] << '\n';
            }
        }
        cout << '\n';
    }
}