// 스택
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, push_num;
    string instruction;
    vector<int> stack;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> instruction;

        if (instruction == "push") {
            cin >> push_num;
            stack.push_back(push_num);
        }
        else if (instruction == "pop") {
            if (!stack.empty()) {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if (instruction == "size") {
            cout << stack.size() << '\n';
        }
        else if (instruction == "empty") {
            if (!stack.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else {  // top 명령어
            if (!stack.empty())
                cout << stack.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}