//
// Created by Aniket Gupta on 12/18/20.
//
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;


void computeOne(unordered_map<ll, ll> &map, int a) {
    int ctr = 0;
    map[a] = ctr++;
    while (a != 1) {
        if (a % 2 == 0) {
            a = a/2;
        }
        else {
            a = 3*a + 1;
        }
        if (map.find(a) == map.end()) {
            map[a] = ctr;
        }
        ctr++;
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (true) {
        unordered_map<ll, ll> map;
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        ll original_x = x, original_y = y;
        computeOne(map, x);
        ll step_y = 0;
        while (true) {
            if (map.find(y) != map.end()) {
                break;
            }
            if (y == 1) {
                break;
            }
            if (y % 2 == 0) {
                y = y/2;
            }
            else {
                y = 3*y + 1;
            }
            ++step_y;
        }
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n",
               original_x, map[y], original_y, step_y, y);
    }
}