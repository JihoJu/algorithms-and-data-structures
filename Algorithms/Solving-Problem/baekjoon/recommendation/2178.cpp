// 미로 탐색
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int move_x[4] = {-1, 1, 0, 0};  // 상하좌우
int move_y[4] = {0, 0, -1, 1};  // 상하좌우
vector<vector<int>> miro(101, vector<int>(101));
vector<vector<int>> visited(101, vector<int>(101));   // 이전에 방문했던 곳인지를 확인
vector<vector<int>> dist(101, vector<int>(101));   // 각 좌표마다 이동 횟수
queue<pair<int, int>> q;  // 좌표값

void bfs() {
    q.push(make_pair(1, 1));
    dist[1][1] = 1;
    visited[1][1] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int m_x = x + move_x[i];
            int m_y = y + move_y[i];

            if ( (m_x >= 1 && m_x <= N) && (m_y >= 1 && m_y <= M) // 움직인 좌표가 미로 범위 내에 있는 지 체크
                && miro[m_x][m_y] == 1 && visited[m_x][m_y] == 0) { // 움직인 좌표가 1 & 이전에 방문하지 않았는 지 체크
                q.push(make_pair(m_x, m_y));    // 이동 좌표 큐에 삽입
                visited[m_x][m_y] = 1;  // 움직인 좌표 방문 표시
                dist[m_x][m_y] = dist[x][y] + 1;    // 움직인 좌표에 이동 횟수 표시
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    /* 미로 초기화 */
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            miro[i + 1][j + 1] = input[j] - '0';
        fill(visited[i + 1].begin(), visited[i + 1].end(), 0);
        fill(dist[i + 1].begin(), dist[i + 1].end(), 0);
    }

    bfs();
    
    cout << dist[N][M] << '\n';

    return 0;
} 