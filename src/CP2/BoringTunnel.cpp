//
// Created by Aniket Gupta on 11/14/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void unionize(ll x, ll y, vector<ll> &parents) {
    parents[y] = x;
}

int parent (int x, vector<ll> &parents) {
    while (parents[x] != x) {
        x = parents[x];
        parents[x] = parents[parents[x]];
    }
    return x;
}

bool comp(vector<ll> a, vector<ll> b) {
    if (a[2] < b[2]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, t, q;
    cin >> n >> t >> q;
    vector<ll> parents(n);
    for (ll i = 0; i < n; i++) parents[i] = i;
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < t; i++) {
        ll x, y;
        cin >> x >> y;
        pair<ll,ll> p(x, y);
        edges.push_back(p);
    }
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; i++) {
        int x, y, time;
        cin >> x >> y >> time;
        vector<ll> temp {x, y, time, i};
        queries.push_back(temp);
    }
    sort(queries.begin(), queries.end(), comp);
    ll curr = 0;
    vector<string> ans(q);
    int i = 0;
    while (curr < queries.size()) {
        vector<ll> curr_query = queries[curr++];
        while (i <= curr_query[2]) {
            pair<ll, ll> edge = edges[i++];
            ll parent_a = parent(edge.first, parents);
            ll parent_b = parent(edge.second, parents);
            if (parent_a != parent_b) {
                unionize(parent_a, parent_b, parents);
            }
        }
        ll parent_a = parent(curr_query[0], parents);
        ll parent_b = parent(curr_query[1], parents);
        if (parent_a != parent_b) {
            ans[curr_query[3]] = "Not reachable\n";
        } else {
            ans[curr_query[3]] = "Reachable\n";
        }
    }


    for (string &s : ans) {
        cout << s;
    }
}
