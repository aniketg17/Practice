//
// Created by Aniket Gupta on 9/24/20.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node(const string &word) {
        val = word;
        next = NULL;
    }
};

class List {
public:
    Node *head;
    Node *tail;

    List(string &word) {
        Node *n = new Node(word);
        head = n;
        tail = n;
    }

    void append(List *list) {
        tail->next = list->head;
        tail = list->tail;
    }

    void print() {
        Node *h = head;
        while (h != NULL) {
            cout << h->val;
            h = h->next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<List*> strings(n+1);
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        List *l = new List(inp);
        strings[i+1] = l;
    }
    if (n == 1) {
        strings[1]->print();
        return 0;
    }
    int start = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y; // store in x
        strings[x]->append(strings[y]);
        if (i == n - 2) {
            start = x;
        }
    }
    strings[start]->print();
}