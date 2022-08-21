#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> M(101, vector<char>(101));
vector<vector<char>> visited(101, vector<char>(101));

int px[4] = {-1, 1, 0, 0}; // 상하좌우
int py[4] = {0, 0, -1, 1};

void dfs(int x, int y, char c) {

    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int mx = x + px[i];
        int my = y + py[i];

        if (mx >= 1 && mx <= N && my >= 1 && my <= N && M[mx][my] == c && !visited[mx][my]) {
            dfs(mx, my, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> M[i][j];
    }
    int cnt1 = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, M[i][j]);
                cnt1++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            if (M[i][j] == 'R') M[i][j] = 'G';
    }

    for (int i = 1; i <= N; i++) {
        fill(visited[i].begin() + 1, visited[i].begin() + N + 1, 0);
    }

    int cnt2 = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, M[i][j]);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}