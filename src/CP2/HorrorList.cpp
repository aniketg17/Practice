//
// Created by Aniket Gupta on 10/2/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class movie {
public:
    int val;
    int score;
    movie(int val, int score) : val(val), score(score) {}
};

void bfs(vector<vector<int>> &graph, int start, unordered_map<int, int> &scores) {
    queue<movie> q;
    vector<bool> seen (graph.size(), false);
    movie m(start, 0);
    q.push(m);
    seen[start] = true;
    while (!q.empty()) {
        movie point = q.front();
        q.pop();
        vector<int> neighbours = graph[point.val];
        int score = point.score;
        for (int x : neighbours) {
            if (!seen[x]) {
                seen[x] = true;
                scores[x] = min(score + 1, scores[x]);
                movie n(x, scores[x]);
                q.push(n);
            }
        }
    }
}

int main() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> horrors(h);
    vector<vector<int>> graph (n, vector<int>());
    unordered_map<int, int> scores;
    for (int i = 0; i < n; i++) {
        scores[i] = INT32_MAX;
    }
    for (int i = 0; i < h; i++) {
        cin >> horrors[i];
        scores[horrors[i]] = 0;
    }
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int x : horrors) {
        bfs(graph, x, scores);
    }
    int maximum = INT32_MIN;
    int id;
    for (int i = 0; i < n; i++) {
        if (scores[i] > maximum) {
            maximum = scores[i];
            id = i;
        }
    }
    cout << id << '\n';
}
