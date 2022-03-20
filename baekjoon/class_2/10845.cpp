// 큐
#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, push_num;
    string instruction;
    deque<int> queue;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> instruction;
        if (instruction == "push") {
            cin >> push_num;
            queue.push_back(push_num);
        }
        else if (instruction == "pop") {
            if (!queue.empty()) {
                cout << queue.front() << '\n';
                queue.pop_front();
            }
            else cout << -1 << '\n';
        }
        else if (instruction == "size") {
            cout << queue.size() << '\n';
        }
        else if (instruction == "empty") {
            if (queue.empty())
                cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (instruction == "front") {
            if (!queue.empty())
                cout << queue.front() << '\n';
            else cout << -1 << '\n';
        }
        else { // back
            if (!queue.empty())
                cout << queue.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}