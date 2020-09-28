//
// Created by Aniket Gupta on 9/25/20.
//
#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class event {
public:
    int time;
    bool direction;
    int idx;
    event(int time, bool direction, int idx) : time(time), direction(direction), idx(idx) {}
};

void travel(int &time, int step, bool &direction) {
    time += step;
    direction = !direction;
}


int main() {
    int num_tests;
    cin >> num_tests;
    for (int i = 0; i < num_tests; i++) {
        int capacity, time_step, lines;
        cin >> capacity >> time_step >> lines;
        int curr_time = 0;
        deque<event> left_q, right_q, main_q;
        for (int j = 0; j < lines; j++) {
            int t;
            string s;
            cin >> t >> s;
            bool dir = (s != "left");
            event e (t, dir, j);
            if (!dir) {
                left_q.push_back(e);
            } else {
                right_q.push_back(e);
            }
            main_q.push_back(e);
        }
        bool direction = false; // false = left
        curr_time = main_q.front().time;
        int idx = 0;
        deque<event> ferry;
        vector<int> offload_times(lines, -1);
        int done = 0;
        while (done != lines) {
            int ctr = 0;
            if (curr_time >= left_q.front().time || curr_time >= right_q.front().time) { // add if possible
                if (!direction) {
                    while (!left_q.empty() && ctr < capacity &&
                           curr_time >= left_q.front().time) {
                        ferry.push_back(left_q.front());
                        ++ctr;
                        ++idx;
                        left_q.pop_front();
                    }
                } else {
                    while (!right_q.empty() && ctr < capacity &&
                           curr_time >= right_q.front().time) {
                        ferry.push_back(right_q.front());
                        ++ctr;
                        ++idx;
                        right_q.pop_front();
                    }
                }
            }
            if (ctr == 0) { // could not add so check 2 conditions: if available right now or later
                if ((!left_q.empty() && curr_time >= left_q.front().time) ||
                    (!right_q.empty() && curr_time >= right_q.front().time)) {
                    travel(curr_time, time_step, direction);
                    continue;
                } else {
                    curr_time = max(main_q[idx].time, curr_time);
                }
            } else { // got passengers so offload them
                travel(curr_time, time_step, direction);
                while (ctr > 0) {
                    event e = ferry.front();
                    ferry.pop_front();
                    offload_times[e.idx] = curr_time;
                    --ctr;
                    ++done;
                }
            }
        }
        for (int x : offload_times) {
            cout << x << '\n';
        }
        cout << '\n';
    }
}