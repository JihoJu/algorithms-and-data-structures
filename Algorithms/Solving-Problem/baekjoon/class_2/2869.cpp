// 달팽이는 올라가고 싶다
#include <iostream>

using namespace std;

long long a, b, v, h, d, sum_num;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> v;

    // h = 0;  // 올라가는 높이
    // d = 0;  // 며칠 걸리는지
    // while (true) {
    //     d++;
    //     h += a;
    //     if (h >= v) break;
    //     h -= b;
    // }

    if ((v - a) % (a - b) == 0) sum_num = (v - a) / (a - b);
    else sum_num = ((v - a) / (a - b)) + 1;

    d = sum_num + 1;

    cout << d << '\n';
}