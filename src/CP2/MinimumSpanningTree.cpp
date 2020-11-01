//
// Created by Aniket Gupta on 11/1/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class edge {
public:
    int u,v,w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool cmp(edge e1, edge e2) {
    return e1.w < e2.w;
}

bool cmp2(edge e1, edge e2) {
    if (e1.u != e2.u) {
        return e1.u < e2.u;
    }
    return e1.v < e2.v;
}

void unionize(vector<int>& parents, int i, int j) {
    parents[j] = i;
}

int find (vector<int> &parents, int i) {
    while (parents[i] != i) {
        i = parents[i];
        parents[i] = parents[parents[i]];
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<edge> edges;
        vector<int> parents (n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u < v) {
                edge e(u, v, w);
                edges.push_back(e);
            } else {
                edge e(v, u, w);
                edges.push_back(e);
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int numComp = n;
        int cost = 0;
        vector<edge> ans;
        for (edge e : edges) {
            int u = e.u;
            int v = e.v;
            int p_a = find(parents, u);
            int p_b = find(parents, v);
            if (p_a != p_b) {
                unionize(parents, p_a, p_b);
                --numComp;
                cost += e.w;
                ans.push_back(e);
            }
        }
        sort(ans.begin(), ans.end(), cmp2);
        if (numComp == 1) {
            cout << cost << '\n';
            for (edge e : ans) {
                cout << e.u << " " << e.v << '\n';
            }
        } else {
            cout << "Impossible\n";
        }
    }
}


