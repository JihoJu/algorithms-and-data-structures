// 색종이 만들기
#include <iostream>
#include <vector>

using namespace std;

int N, blue = 0, white = 0;
vector<vector<int>> M;

void resize();
bool is_ok(int n, int x, int y);
void sol(int n, int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    resize();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> M[i][j];
    }

    sol(N, 0, 0);
    cout << white << '\n' << blue << '\n';

    return 0;
}

void sol(int n, int x, int y) {
    if (is_ok(n, x, y) || n == 1) {
        if (M[x][y] == 0)
            white++;
        else
            blue++;
    }
    else {
        int m = n / 2;
        sol(m, x, y);
        sol(m, x, y + m);
        sol(m, x + m, y);
        sol(m, x + m, y + m);
    }
}

bool is_ok(int n, int x, int y) {
    int color = M[x][y];

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (M[i][j] != color)
                return false;
        }
    }

    return true;
}

void resize() {
    M.resize(N);
    for (int i = 0; i < N; i++)
        M[i].resize(N);
}