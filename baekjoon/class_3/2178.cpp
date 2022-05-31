// 미로 탐색
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

typedef vector<vector<int>> MAP;
int N, M, minimum = INT_MAX;
MAP m, visited;

void resize();
void solution(int i, int j, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    resize();
    string input;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            m[i][j+1] = input[j] - '0';
        }
    }

    solution(1, 1, 0);
    cout << minimum << '\n';

    return 0;
}

void solution(int i, int j, int cnt) {
    visited[i][j] = 1;
    cnt++;
    cout << m[i][j] << ' ' << i << ' ' << j << ' ' << cnt << endl;
    if (cnt < minimum) {
        if (i == N && j == M) {
            minimum = min(cnt, minimum);
            return;
        }
        else {
            if (i - 1 >= 1 && m[i - 1][j] && !visited[i - 1][j])   // 상
                solution(i - 1, j, cnt);
            if (j + 1 <= M && m[i][j + 1] && !visited[i][j + 1])   // 우
                solution(i, j + 1, cnt);
            if (i + 1 <= N && m[i + 1][j] && !visited[i + 1][j])   // 하
                solution(i + 1, j, cnt);
            if (j - 1 >= 1 && m[i][j - 1] && !visited[i][j - 1])   // 좌
                solution(i, j - 1, cnt);
        }
    }
}

void resize() {
    m.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        m[i].resize(M + 1);
        visited[i].resize(M + 1);
        fill(visited[i].begin() + 1, visited[i].end(), 0);
    }
}