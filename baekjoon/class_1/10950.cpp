// A + B - 3
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}