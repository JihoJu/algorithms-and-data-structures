// Z
#include <iostream>

using namespace std;

void sol(int x, int y, int n, int m);

int N, c, r, order = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    sol(0, 0, 1 << N, 1 << N);
 
    return 0;
}

void sol(int x, int y, int n, int m) {
    int k = (n - x) / 2;
    
    if (k == 0) {
        if (x == r && y == c) {
            cout << order << '\n';
            return;
        }
        else order++;
    }
    else {
        if ((r >= x && r < n) && (c >= y && c < m)) {
        sol(x, y, n - k, m - k);
        sol(x, y + k, n - k, m);
        sol(x + k, y, n, m - k);
        sol(x + k, y + k, n, m);
        }       
        else {  // 현재 판에 없는 경우
            order += (n - x) * (m - y);
        }
    }
}