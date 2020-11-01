
#include <iostream>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;

int main() {
    const ll LARGE_LONG = (ll) 1000000;
    while (true) {
        ll n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) break;
        vector<vector<ll>> graph (n, vector<ll>(n, LARGE_LONG));
        for (int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = min(w, graph[u][v]);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][k] + graph[k][j] < graph[i][j] && graph[i][k] != LARGE_LONG && graph[k][j] != LARGE_LONG) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n && graph[i][j] != LONG_LONG_MIN; k++) {
                    if (graph[k][k] < 0 && graph[i][k] != LARGE_LONG && graph[k][j] != LARGE_LONG) {
                        graph[i][j] = LONG_LONG_MIN;
                    }
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            if (graph[u][v] == LARGE_LONG) {
                cout << "Impossible\n";
            } else if (graph[u][v] == LONG_LONG_MIN) {
                cout << "-Infinity\n";
            } else {
                cout << graph[u][v] << '\n';
            }
        }
        cout << '\n';
    }

}