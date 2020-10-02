//
// Created by Aniket Gupta on 9/28/20.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int stack1 = 0; // to give from
        int stack2 = 0; // to keep extras
        for (int i = 0; i < n; i++) {
            pair<string, int> command;
            cin >> command.first >> command.second;
            if (command.first == "DROP") {
                stack2 += command.second;
                cout << "DROP " << 2 << " " << command.second << "\n";
            } else {
                int remove = command.second;
                if (remove > stack1) {
                    if (stack1 != 0) {
                        cout << "TAKE 1 " << stack1 << "\n";
                    }
                    remove -= stack1;
                    cout << "MOVE 2->1 " << stack2 << "\n";
                    stack1 = stack2;
                    stack2 = 0;
                    cout << "TAKE 1 " << remove << "\n";
                    stack1 -= remove;
                } else {
                    stack1 -= remove;
                    cout << "TAKE 1 " << remove << "\n";
                }
            }
        }
        cout << '\n';
    }
}
