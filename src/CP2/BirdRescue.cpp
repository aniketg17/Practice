#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rescue() {
    int n, q; // friends and queries
    cin >> n;
    cin >> q;
    int x_B, y_B;
    cin >> x_B;
    cin >> y_B;
    vector<int> distances(2000002, 0); // added another index for area's end invariance

    for(int i = 0; i < n; i++) {
        vector<int> x_coord(2);
        vector<int> y_coord(2);
        cin >> x_coord[0];
        cin >> y_coord[0];
        cin >> x_coord[1];
        cin >> y_coord[1];
        sort(x_coord.begin(), x_coord.end());
        sort(y_coord.begin(), y_coord.end()); // take small vals first and then bigger ones

        if(x_coord[0] <= x_B && x_B <= x_coord[1]) {
            x_coord.push_back(x_B);
        }
        if(y_coord[0] <= y_B && y_B <= y_coord[1]) {
            y_coord.push_back(y_B);
        }

        vector<int> combinations;
        for(int x : x_coord) { // compute all combinations of areas w.r.t bird
            for(int y : y_coord) {
                int val = abs(x - x_B) + abs(y - y_B);
                combinations.push_back(val);
            }
        }
        sort(combinations.begin(), combinations.end());
        distances[combinations.front()]++; // add area starts and subtract area ends
        distances[combinations.back() + 1]--;
    }

    int sum = 0;
    for(int & i : distances) {
        sum += i;
        i = sum;
    }

    for(int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        cout << distances[idx] << endl;
    }
}