//
// Created by Aniket Gupta on 9/10/20.
//
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

string word;
vector<int> underscore;
bool containsL;
ll total_r;

bool isVowel(int i) {
    if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
        return true;
    }
    return false;
}

bool isConsonant(int i) {
    if (word[i] != '_' && word[i] != 'A' && word[i] != 'E' &&
        word[i] != 'I' && word[i] != 'O' && word[i] != 'U') {
        return true;
    }
    return false;
}

bool isSafeConsonant(int idx) {
    if (idx - 2 >= 0 && isConsonant(idx-2) && isConsonant(idx-1)) return false;
    if (idx - 1 >= 0 && idx+1 < word.length() &&
            isConsonant(idx-1) &&
            isConsonant(idx+1)) return false;
    if (idx+2 < word.length() &&
            isConsonant(idx+1) && isConsonant(idx+2)) return false;
    return true;
}

bool isSafeVowel(int idx) {
    if (idx - 2 >= 0 && isVowel(idx-2) && isVowel(idx-1)) return false;
    if (idx - 1 >= 0 && idx+1 < word.length() &&
        isVowel(idx-1) && isVowel(idx+1)) return false;
    if (idx+2 < word.length() &&
        isVowel(idx+1) && isVowel(idx+2)) return false;
    return true;
}

ll ways = 1;

void compute(int i) {
    if (i == underscore.size()) {
        if (containsL) {
            total_r += ways;
        }
        return;
    }
    int idx = underscore[i];
    if (!containsL && isSafeConsonant(idx)) {
        word[idx] = 'L';
        containsL = true;
        compute(i+1);
        containsL = false;
        word[idx] = '_';
    }
    if (isSafeConsonant(idx)) {
        word[idx] = 'C';
        if (!containsL) {
            ways *= (ll) 20;
        } else {
            ways *= (ll) 21;
        }
        compute(i+1);
        if (!containsL) {
            ways /= (ll) 20;
        } else {
            ways /= (ll) 21;
        }
        word[idx] = '_';
    }
    if (isSafeVowel(idx)) {
        word[idx] = 'A';
        ways *=  (ll) 5;
        compute(i+1);
        ways /= (ll) 5;
        word[idx] = '_';
    }
}

int main() {
    cin >> word;
    for (char c : word) {
        if (c == 'L')  {
            containsL = true;
        }
    }
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == '_') {
            underscore.push_back(i);
        }
    }
    compute(0);
    cout << total_r << endl;
}

