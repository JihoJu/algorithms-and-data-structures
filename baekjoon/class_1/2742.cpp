// 기찍 N
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = n; i >= 1; i--) 
        cout << i << "\n";

    return 0;
}