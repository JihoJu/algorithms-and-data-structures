// 덱
#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, input;
    string instruction;
    deque<int> dq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> instruction;

        if (instruction == "push_front") {
            cin >> input;
            dq.push_front(input);
        }
        else if (instruction == "push_back") {
            cin >> input;
            dq.push_back(input);
        }
        else if (instruction == "pop_front") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (instruction == "pop_back") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (instruction == "size") {
            cout << dq.size() << '\n';
        }
        else if (instruction == "empty") {
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (instruction == "front") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else {  // back
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}