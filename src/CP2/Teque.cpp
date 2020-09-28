//
//  main.cpp
//  Kattis
//
//  Created by Aniket Gupta on 9/28/20.
//

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<int> left;
    deque<int> right;

    for (int i = 0; i < n; i++) {
        string command;
        int data;
        cin >> command >> data;
        if (command == "push_back") {
            right.push_back(data);
            while (right.size() > left.size()) {
                int val = right.front();
                left.push_back(val);
                right.pop_front();
            }
        } else if (command == "push_front") {
            left.push_front(data);
            while (left.size() - right.size() > 1) {
                int val = left.back();
                right.push_front(val);
                left.pop_back();
            }
        } else if (command == "push_middle") {
            right.push_front(data);
            while (right.size() > left.size()) {
                int val = right.front();
                left.push_back(val);
                right.pop_front();
            }
        } else {
            if (data < left.size()) {
                cout << left[data] << '\n';
            } else {
                cout << right[data - left.size()] << '\n';
            }
        }
    }

}
