// Z
// 로직은 맞는 거 같은데 시간초과가 난다면 범위 설정을 꼼꼼히 확인하자 -> 잘못된 범위로 인한 무한 루프 등이 생길 수 있다.
#include <iostream>

using namespace std;

void sol(int x, int y, int n);

int N, c, r, order = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> c >> r;

    sol(0, 0, 1 << N);

    return 0;
}

void sol(int x, int y, int n) {
    if (x == c && y == r) {
        cout << order << '\n';
        return;
    }

    int m = n / 2;
    if (c >= x && c < x + m && r >= y && r < y + m) {
        order += m * m * 0;
        sol(x, y, m);
    }
    else if (c >= x && c < x + m && r >= y + m && r < y + n) {
        order += m * m * 1;
        sol(x, y + m, m);
    }
    else if (c >= x + m && c < x + n && r >= y && r < y + m) {
        order += m * m * 2;
        sol(x + m, y, m);
    }
    else {
        order += m * m * 3;
        sol(x + m, y + m, m);
    }
}