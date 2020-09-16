#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

typedef long long ll;
typedef long double ld;

using namespace std;

bool okay(ll thresh, vector<vector<ll>> &vals, ll goal) {
    ll curr = 0;
    for (vector<ll> vec : vals) {
        if (vec[1] > thresh) {
            break;
        } else {
            curr += vec[0] * thresh - vec[2];
            if (curr >= goal) return true;
        }
    }
    return false;
}

ll binary_search(ll low, ll high, vector<vector<ll>> &vals, ll goal) {
    while (low <= high) {
        if (low == high) return low;
        if (low + 1 == high) {
            if (okay(low, vals, goal)) return low;
            else return high;
        }
        ll mid = low/2 + high/2;
        if (okay(mid, vals, goal)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    ll n, minimum;
    cin >> n >> minimum;
    vector<vector<ll>> days;
    ll max_days = -1;
    ll min_days = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll profit, cost;
        cin >> profit >> cost;
        ll break_even = round((ld) cost/profit);
        days.emplace_back(vector<ll> {profit, (ll) round(break_even), cost});
        ll day = round(break_even);
        max_days = max(max_days, day);
        min_days = std::min(min_days, day);
    }
    auto comp = [] (vector<ll> val1, vector<ll> val2) {
        return val1[1] < val2[1];
    };
    sort(days.begin(), days.end(), comp);
    ll ans = binary_search(days[0][1], INT32_MAX, days, minimum);
    cout << ans << endl;
}