//
// Created by Aniket Gupta on 10/27/20.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;



bool okay(ll val, vector<vector<ll>> &grid) {
    const vector<int> dr {1,-1,0,0};
    const vector<int> dc {0,0, -1, 1};
    vector<vector<bool>> seen (n, vector<bool>(m, false));
    queue<vector<int>> q;
    vector<int> v {0,0};
    seen[0][0] = true;
    q.push(v);
    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        int i = temp[0];
        int j = temp[1];
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !seen[nr][nc]) {
                ll w = (grid[nr][nc] - grid[i][j] > 0) ? grid[nr][nc] - grid[i][j] : 0;
                if (w <= val) {
                    seen[nr][nc] = true;
                    vector<int> t {nr, nc};
                    q.push(t);
                }
            }
        }
        if (seen[n-1][m-1]) return true;
    }
    return false;
}


ll binary_search(ll low, ll high, vector<vector<ll>> &val) {
    while (low <= high) {
        if (low == high) return low;
        if (low + 1 == high) {
            if (okay(low, val)) return low;
            else return high;
        }
        ll mid = low/2 + high/2;
        if (okay(mid, val)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("/Users/aniketgupta/Desktop/secret/0longpath2.in.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    n = N;
    m = M;
    vector<vector<ll>> graph (n, vector<ll> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    int ans = binary_search(0, (ll) 1000000000, graph);
    cout << ans;
}

