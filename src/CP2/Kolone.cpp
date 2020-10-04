//
// Created by Aniket Gupta on 10/3/20.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<char> order (a+b+120, '#');
    string line;
    cin >> line;
    int x = 0;
    for (int i = line.size() - 1; i >= 0; i--) {
        order[x+60] = line[i];
        x++;
    }
    for (int i = 0; i < b; i++) {
        char a;
        cin >> a;
        order[x + 60] = a;
        ++x;
    }
    vector<char> ret (a+b+120);
    for (int l = 0; l < ret.size(); l++) {
        ret[l] = order[l];
    }
    int t;
    cin >> t;
    int n = t;
    for (int i = 0; i < n; i++) {
        ret[59 + a - i + t] = order[59 + a - i];
        ret[60 + a + i - t] = order[60 + a + i];
        --t;
    }
    if (n != 0) {
        for (char k : ret) {
            if (k != '#') {
                cout << k;
            }
        }
    } else {
        for (char k : order) {
            if (k != '#') {
                cout << k;
            }
        }
    }

}
