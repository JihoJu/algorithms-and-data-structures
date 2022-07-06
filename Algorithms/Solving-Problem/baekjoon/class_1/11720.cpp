// 숫자의 합
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, sum = 0;
    string num;
    
    cin >> n;
    cin >> num;
    
    for (int i = 0; i < n; i++) {
        sum += (num[i] - '0');
    }

    cout << sum << '\n';

    return 0;
}