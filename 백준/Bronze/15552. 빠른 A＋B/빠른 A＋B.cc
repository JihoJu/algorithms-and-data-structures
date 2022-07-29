// 빠른 A+B
#include <iostream>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    int a, b;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}