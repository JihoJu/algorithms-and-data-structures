// 종이의 개수
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<vector<int> > MAP;

int cnt[3] = {0, 0, 0}; // -1, 0, 1
MAP M;
int N;

void resize(int n, MAP &m);
void sol(int x, int y, int n);
bool check(int x, int y, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    resize(N, M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> M[i][j];
    }

    sol(1, 1, N);
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << '\n';

    return 0;
}

bool check(int x, int y, int n) {
    int num = M[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++)
            if (M[i][j] != num) return false;
    }

    return true;
}

void sol(int x, int y, int n) {
    if (n == 1) {
        cnt[M[x][y] + 1]++;
        return;
    }
    if (check(x, y, n))
        cnt[M[x][y] + 1]++;
    else {
        int t = n / 3;
        sol(x, y, t); sol(x, y + t, t); sol(x, y + 2 * t, t);
        sol(x + t, y, t); sol(x + t, y + t, t); sol(x + t, y + 2 * t, t);
        sol(x + 2 * t, y, t); sol(x + 2 * t, y + t, t); sol(x + 2 * t, y + 2 * t, t);
    }
}

void resize(int n, MAP &m) {
    m.resize(n + 1);
    for (int i = 1; i <= n; i++)
        m[i].resize(n + 1);
}
