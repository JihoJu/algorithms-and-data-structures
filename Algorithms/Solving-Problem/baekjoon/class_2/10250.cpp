// ACM 호텔
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n_times, h, w, n, r, f; // r: room | f: floor

    cin >> n_times;

    for (int t = 0; t < n_times; t++) {
        cin >> h >> w >> n;

        if (n % h == 0) {
            f = h;
            r = n / h;
        }
        else {
            r = (n / h) + 1;
            f = (n % h);
        }
        cout << 100 * f + r << '\n';
    }
    
    return 0;
}