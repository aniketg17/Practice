//
// Created by Aniket Gupta on 9/15/20.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // key: U-Unknown, M-Matched, [Name] = name
    int n, k;
    cin >> n >> k;
    vector<string> cards (n + 1, "U");
    for (int i = 0; i < k; i++) {
        int idx1, idx2;
        string card1, card2;
        cin >> idx1 >> idx2 >> card1 >> card2;
        if (card1 == card2) {
            cards[idx1] = "M";
            cards[idx2] = "M";
            continue;
        }
        cards[idx1] = card1;
        cards[idx2] = card2;
    }
    int unmatched_but_known = 0, unknown = 0, ret = 0;
    for (int i = 1; i <= n; i++) {
        if (cards[i] == "M") {
            continue;
        } else if (cards[i] == "U") {
            unknown++;
        } else {
            for (int j = i + 1; j <= n; j++) {
                if (cards[i] == cards[j]) {
                    ++ret;
                    cards[i] = "M";
                    cards[j] = "M";
                    break;
                }
            }
            if (cards[i] != "M") {
                unmatched_but_known++;
            }
        }
    }
    // now only left with unmatched knowns and unknowns
    if (unmatched_but_known >= unknown) {
        ret += unknown;
    } else if (unknown == 2) {
        ret += 1;
    }
    cout << ret;

}

