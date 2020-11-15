//
// Created by Aniket Gupta on 11/14/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> costs (n);
    for (ll i = 0; i < n; i++) {
        ll item = 0;
        cin >> item;
        costs[i] = item;
    }
    sort(costs.begin(), costs.end());
    vector<ll> prefix;
    vector<ll> queries;
    ll sum = 0;
    for (ll cost : costs) {
        sum += cost;
        prefix.push_back(sum);
    }
    unordered_map<ll, ll> map;
    unordered_map<ll, ll> ans;
    for (ll i = 0; i < q; i++) {
        ll query;
        cin >> query;
        queries.push_back(query);
        map[i] = query;
    }
    sort(queries.begin(), queries.end());
    ll j = 0;
    for (ll query : queries) {
        while (j < prefix.size() && prefix[j] < query) {
            ++j;
        }
        ans[query] = j;
    }
    for (ll i = 0; i < queries.size(); i++) {
        cout << ans[map[i]] << '\n';
    }
}

