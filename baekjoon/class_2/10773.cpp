// 제로
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, elem, sum;
    vector<int> stack;

    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> elem;
        if (elem == 0) stack.pop_back();
        else stack.push_back(elem);
    }

    sum = 0;
    for (int i = 0; i < stack.size(); i++)
        sum += stack[i];

    cout << sum << '\n';

    return 0;
}