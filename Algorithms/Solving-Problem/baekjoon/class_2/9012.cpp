// 괄호
#include <iostream>
#include <vector>

using namespace std;

void clear_stack(vector<char> &stack) {
    vector<char> empty;
    swap(stack, empty);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, is_vps;
    string input;
    vector<char> stack;

    cin >> n;

    for (int i = 0; i < n; i++) {
        is_vps = 1;
        cin >> input;
        
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == '(') stack.push_back(input[j]);
            else {
                if (stack.empty() || stack.back() != '(') {
                     is_vps = 0;
                     break;
                }
                else stack.pop_back();
            }
        }
        if (!stack.empty()) is_vps = 0;

        if (is_vps) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        clear_stack(stack);
    }

    return 0;
}