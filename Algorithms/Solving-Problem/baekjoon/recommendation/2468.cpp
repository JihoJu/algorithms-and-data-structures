// 안전 영역
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N, n;
int answer = INT_MIN;
int pos_x[4] = {-1, 1, 0, 0};   // 상하좌우
int pos_y[4] = {0, 0, -1, 1};   // 상하좌우
vector<vector<int>> M(101, vector<int>(101));   // 어떤 지역 높이 정보
vector<vector<int>> visited(101, vector<int>(101, 0));  // 지역을 방문했는 지의 정보를 담는 2차원 배열
vector<pair<int, int>> area;    // 어떤 지역에서 물에 잠기지 않은 좌표를 담는 배열

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int m_x = x + pos_x[i];
        int m_y = y + pos_y[i];
        if (m_x >= 1 && m_x <= N && m_y >= 1 && m_y <= N) {
            if (!visited[m_x][m_y] && M[m_x][m_y] > n) {
                visited[m_x][m_y] = 1;
                dfs(m_x, m_y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int max_num = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> M[i][j];
            max_num = M[i][j] > max_num ? M[i][j] : max_num;
        }
    }

    for (n = 0; n < max_num; n++){
        // 물에 잠기지 않은 좌표 area 에 담는다.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (M[i][j] > n)
                    area.push_back(make_pair(i, j));
            }
        }

        int area_cnt = 0;
        for (int i = 0; i < area.size(); i++) {
            if (!visited[area[i].first][area[i].second]) {
                dfs(area[i].first, area[i].second);
                area_cnt++;
            }
        }

        answer = max(answer, area_cnt);

        for (int i = 1; i <= N; i++)
            fill(visited[i].begin(), visited[i].begin() + N + 1, 0);
        area.clear();
    }

    cout << answer << '\n';

    return 0;
}