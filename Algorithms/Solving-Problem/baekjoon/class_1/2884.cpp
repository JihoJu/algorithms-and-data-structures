// 알람 시계
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int hour, min;

    cin >> hour >> min;

    if (min < 45) {
        if (hour == 0)
            hour = 23;
        else
            hour -= 1;
        min = 60 - (45 - min);
    }
    else 
        min -= 45;

    cout << hour << ' ' << min << '\n';

    return 0;
}