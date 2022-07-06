// A + B - 4
#include <iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    while (1) {
        cin >> a >> b;
        if (cin.eof() == true) break;
        cout << a + b << '\n';
    }

    return 0;
}