//
// Created by Aniket Gupta on 10/29/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void unionize(vector<int> &parents, int i, int j) {
    parents[j] = i;
}

int parent(vector<int> &parents, int c) {
    while (parents[c] != c) {
        c = parents[c];
        parents[c] = parents[parents[c]];
    }
    return c;
}

class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool cmp (edge e1, edge e2) {
    return e1.w < e2.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int k = 0; k < N; k++) {
        int n, m, l, s;
        cin >> n >> m >> l >> s;
        vector<int> parents (n+1);
        for (int i = 1; i < n+1; i++) {
            parents[i] = i;
        }
        vector<edge> edges;
        bool first = true;
        int a;
        ll cost = (n-s) * (ll) l;
        for (int i = 0; i < s; i++) {
            if (first) {
                first = false;
                cin >> a;
                continue;
            }
            int temp;
            cin >> temp;
            unionize(parents, a, temp); // union subequent elements with first element in S
        }
        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            edge e(x, y, w);
            edges.push_back(e);
        }
        sort(edges.begin(), edges.end(), cmp);
        int iter = 0; // variable to iterate
        ll total = 0;
        int component = n - s + 1;
        while (component > 1) {
            edge temp = edges[iter++];
            int p_a = parent(parents, temp.u); // parent of a
            int p_b = parent(parents, temp.v); // parent of b
            if (p_a != p_b) {
                unionize(parents, p_a, p_b);
                total += temp.w;
                --component;
            }
        }
        cost += total;
        cout << cost << '\n';
    }
}
