//
// Created by Aniket Gupta on 10/26/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class edge {
public:
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool comp (edge e1, edge e2) {
    if (e1.w < e2.w) {
        return true;
    } else {
        return false;
    }
}

void unionize(vector<int> &parents, int p_a, int p_b) {
    parents[p_b] = p_a;
}

int parent (vector<int> &parents, int a) {
    while (parents[a] != a) {
        a = parents[a];
        parents[a] = parents[parents[a]];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<edge> edges;
    vector<int> parents;
    for (int i = 0; i < n; i++) {
        parents.push_back(i);
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w != 0) {
                edge e (i, j, w);
                edges.push_back(e);
            }
        }
    }
    sort(edges.begin(), edges.end(), comp);
    int components = n;
    for (edge e : edges) {
        int p_u = parent(parents, e.u);
        int p_v = parent(parents, e.v);
        if (p_u != p_v) {
            unionize(parents, p_u, p_v);
            --components;
            cout << e.u + 1 << " " << e.v + 1 << '\n';
        }
        if (components == 1) {
            break;
        }
    }
}

