//
// Created by Aniket Gupta on 10/28/20.
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

bool cmp (edge e1, edge e2) {
    return e1.w < e2.w;
}

void unionize(vector<int> &parents, int a, int b) {
    parents[b] = a;
}

int find(vector<int> &parents, int c) {
    while (c != parents[c]) {
        c = parents[c];
        parents[c] = parents[parents[c]];
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int m = 0; m < n; m++) {
        int M, C;
        cin >> M >> C;
        int N = ((C) * (C-1)) / 2;
        vector<edge> edges;
        vector<int> parent (C);
        for (int i = 0; i < C; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < N; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            edge e (x, y, w);
            edge e2 (y, x, w);
            edges.push_back(e);
            edges.push_back(e2);
        }
        sort(edges.begin(), edges.end(), cmp);

        int comp = C;
        int total = 0;
        int x = 0;
        while (comp != 1) {
            edge curr = edges[x++];
            int p_a = find(parent, curr.u);
            int p_b = find(parent, curr.v);
            if (p_a != p_b) {
                unionize(parent, p_a, p_b);
                --comp;
                total += curr.w;
            }
        }
        total += C;
        if (total <= M) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
