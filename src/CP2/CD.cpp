//
// Created by Aniket Gupta on 10/4/20.
//
#include <iostream>
#include <unordered_set>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<ll> jack;
    unordered_set<ll> jill;
    while (true) {
        jack.clear();
        jill.clear();
        ll counter = 0;
        ll n = 0, m = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            jack.insert(x);
        }
        for (ll i = 0; i < m; i++) {
            ll x;
            cin >> x;
            jill.insert(x);
        }
        for (auto x : jack) {
            if (jill.find(x) != jill.end()) {
                counter++;
            }
        }
        cout << counter << '\n';
    }
}
