//
// Created by Aniket Gupta on 10/26/20.
//
#include <iostream>
#include <vector>

using namespace std;

int parent(vector<int> &parents, int a) {
    while(parents[a] != a) {
        parents[a] = parents[parents[a]];
        a = parents[a];
    }
    return a;
}

void unionize(vector<int> &parents, int p_a, int p_b, vector<int> &sizes) {
    sizes[p_a] += sizes[p_b];
    parents[p_b] = p_a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> parents (l+1, 0);
    vector<int> sizes (l+1, 1);
    for (int i = 0; i < parents.size(); i++) {
        parents[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int p_a = parent(parents, a);
        int p_b = parent(parents, b);
        if (p_a != p_b) {
            unionize(parents, p_a, p_b, sizes);
        }
        int curr_size = sizes[p_a];
        if (curr_size <= 0) {
            cout << "SMECE\n";
        } else {
            sizes[p_a] -= 1;
            cout << "LADICA\n";
        }
    }
}
