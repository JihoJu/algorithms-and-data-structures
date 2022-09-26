// 잃어버린 괄호
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>

using namespace std;

vector<int> stack;
string input;

string reverse_string(string a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    string s;
    int num, sum = 0;
    string s_num;
    stack.push_back(0);
    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] == '+' || input[i] == '-') {
            s_num = reverse_string(s);
            sum += stoi(s_num);
            if (input[i] == '-') {
                stack.push_back(-1*sum);
                sum = 0;
            }
            s.clear();
        }
        else s += input[i];
    }

    int answer = stoi(reverse_string(s)) + sum;
    for (int i = 0; i < stack.size(); i++)
        answer += stack[i];

    cout << answer << '\n';

    return 0;
}

string reverse_string(string a) {
    string s;

    for (int i = a.size() - 1; i >= 0; i--)
        s += a[i];

    return s;
}