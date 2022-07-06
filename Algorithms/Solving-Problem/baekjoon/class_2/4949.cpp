// 균형잡힌 세상
#include <iostream>
#include <algorithm>
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

    int is_balance;
    string input;
    vector<char> stack;

    while (true){
        getline(cin, input);
        if (input == ".") break;
        is_balance = 1;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(') stack.push_back(input[i]);
            if (input[i] == ')') {
                if (stack.empty() || stack.back() != '(') {
                    is_balance = 0;
                    break;
                }
                else stack.pop_back();
            }
            if (input[i] == '[') stack.push_back(input[i]);
            if (input[i] == ']') {
                if (stack.empty() || stack.back() != '[') {
                    is_balance = 0;
                    break;
                }
                else stack.pop_back();
            }
        }
        
        if (!stack.empty() || !stack.empty()) is_balance = 0;

        if (is_balance) cout << "yes" << '\n';
        else cout << "no" << '\n';

        clear_stack(stack);
    }

    return 0;
}