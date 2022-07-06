// 스택 수열
#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, input, index, is_possible = 1;

    cin >> n;
    
    vector<int> vec(n), stack;
    vector<char> result;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    index = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= vec[index]) {
            stack.push_back(i);
            result.push_back('+');
            while (stack[stack.size() - 1] == vec[index]) {
                stack.pop_back();
                result.push_back('-');
                index++;
                if (index >= n) break;
            }
        }
    }

    if (stack.size() > 0)
        cout << "NO\n";
    else {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << '\n';
    }

    return 0;
}
