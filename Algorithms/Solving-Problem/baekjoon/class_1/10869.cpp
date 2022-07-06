// 사칙연산
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    cout << a + b << '\n';
    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a / b << '\n';
    cout << a % b << '\n';

    return 0;
}