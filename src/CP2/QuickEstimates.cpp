//
// Created by Aniket Gupta on 10/5/20.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        cout << line.size() << '\n';
    }
}