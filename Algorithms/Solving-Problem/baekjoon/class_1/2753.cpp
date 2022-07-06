// 윤년
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int year;

    cin >> year;

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}