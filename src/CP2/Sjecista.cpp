//
// Created by Aniket Gupta on 10/3/20.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int lim = n;
    for (int i = lim - 1; i > lim - 4; i--) {
        n *= i;
    }
    n /= 24;
    cout << n;
}

