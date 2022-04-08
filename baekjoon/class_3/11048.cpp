// 이동하기
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > MAP;
MAP m, d;
int N, M;

void resize(int n, int m, MAP &p);
void sol(int n, int m, MAP p, MAP &dp);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    resize(N, M, m);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) m[i][j] = -2;
            else cin >> m[i][j];
        }
    }

    d = m;

    sol(N, M, m, d);

    cout << d[N][M] << '\n';

    return 0;
}

void sol(int n, int m, MAP p, MAP &dp) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) dp[i][j] = p[i][j];
            else {
                int max = p[i][j] + dp[i - 1][j - 1];
                if (max < p[i][j] + dp[i - 1][j]) max = p[i][j] + dp[i - 1][j];
                if (max < p[i][j] + dp[i][j - 1]) max = p[i][j] + dp[i][j - 1];
                dp[i][j] = max;
            }
        }
    }
}

void resize(int n, int m, MAP &p) {
    p.resize(n + 1);
    for (int i = 0; i <= n; i++)
        p[i].resize(m + 1);
}