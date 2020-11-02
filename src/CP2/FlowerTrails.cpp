//
// Created by Aniket Gupta on 11/1/20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

typedef long long ll;

using namespace std;

class edge {
public:
    ll v, w;

    edge(ll v, ll w) : v(v), w(w) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> dists(n, INT32_MAX);
    unordered_map<ll, vector<edge>> graph;
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge e(v, w);
        graph[u].push_back(e);
        edge e2 (u, w);
        graph[v].push_back(e2);
    }
    auto comp = [&] (vector<ll> a, vector<ll> b) {
        if (a[1] != b[1]) return a[1] > b[1];
        else return a[0] > b[0];
    };
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(comp)> pq (comp);
    vector<ll> t {0,0,0}; // 0: v, 1: w, 2: prev
    pq.push(t);
    vector<vector<ll>> prevs (n);
    while (!pq.empty()) {
        vector<ll> curr = pq.top();
        ll u = curr[0], u_w = curr[1], prev = curr[2];
        pq.pop();
        if (u_w > dists[u]) {
            continue;
        } else if (u_w == dists[u]) {
            prevs[u].push_back(prev);
            continue;
        } else {
            dists[u] = u_w;
            prevs[u].clear();
            prevs[u].push_back(prev);
        }
        vector<edge> neighbours = graph[u];
        for (edge e : neighbours) {
            ll v = e.v, w = e.w;
            if (dists[u] + w <= dists[v]) {
                vector<ll> temp {v, dists[u] + e.w, u};
                pq.push(temp);
            }
        }
    }
    unordered_map<ll, bool> seen;
    seen[n-1] = true;
    queue<ll> s;
    s.push(n-1);
    ll ans = 0;
    while (s.front() != n && !s.empty()) {
        ll curr = s.front();
        s.pop();
        vector<ll> prev = prevs[curr];
        for (ll x : prev) {
            ans += dists[curr] - dists[x];
            if (!seen[x]) {
                s.push(x);
                seen[x] = true;
            }
        }
    }
    cout << ans * (ll) 2;

};