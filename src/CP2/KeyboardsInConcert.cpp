//
// Created by Aniket Gupta on 9/17/20.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int> notes;
int num_notes;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_instruments, num_notes_1;
    cin >> num_instruments >> num_notes_1;
    num_notes = num_notes_1;
    vector<int> noter (num_notes_1);
    // table for each instrument and the number of changes needed for each instrument's note
    vector<vector<int>> dp (num_instruments, vector<int>(num_notes_1, 1));
    vector<vector<int>> note_map (num_instruments, vector<int> (1001, -1));
    for (int i = 0; i < num_instruments; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int note;
            cin >> note;
            note_map[i][note] = 1;
        }
    }

    for (int i = 0; i < num_notes_1; i++) {
        int note;
        cin >> note;
        noter[i] = note;
    }
    notes = noter;
    for (int i = 0; i < num_notes_1; i++) {
        for (int j = 0; j < num_instruments; j++) {
            if (i == 0) {
                if (note_map[j][notes[i]] == 1) {
                    dp[j][i] = 0;
                } else {
                    dp[j][i] = 1;
                }
            } else {
                if (note_map[j][notes[i]] == 1) {
                    dp[j][i] = dp[j][i-1];
                } else {
                    dp[j][i] = 1 + dp[j][i-1];
                }
            }
        }
    }
    int pointer = 1;
    int counter = -1;
    num_notes = num_notes_1;
    for (; pointer < num_notes_1;) {
        ++counter;
        int max = 0;
        for (int i = 0; i < dp.size(); i++) {
            int curr_max = 0;
            for (int j = pointer; dp[i][j] == dp[i][j-1]; j++) {
                if (pointer == 1) {
                    if (dp[i][j] == 0) {
                        curr_max++;
                    }
                } else {
                    curr_max++;
                }
            }
            max = std::max(max, curr_max);
        }
        pointer += max;
    }
    cout << counter << endl;
}

/*
2 4
4 1 3 5 4
4 2 3 5 7
3 5 2 7
 */