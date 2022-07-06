// 차이를 최대로
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>
using namespace std;

// 상하좌우
int move_row[4] = {-1, 1, 0, 0};
int move_col[4] = {0, 0, -1, 1};

typedef pair<int, int> coordinate;
int N;
vector<vector<int>> M, visited;
vector<int> total;

void solution();
void resize();

bool cmp(const int a, const int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    resize();
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            M[i][j] = input[j] - '0'; 
        }
    }

    solution();
    sort(total.begin(), total.end(), cmp);
    cout << total.size() << '\n';
    for (int t: total)
        cout << t << '\n';
    return 0;
}

void solution() {
    deque<pair<int, int>> dq;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && M[i][j]) {
                dq.push_back(make_pair(i, j));
                visited[i][j] = 1;
                cnt++;
                while(!dq.empty()) {
                    coordinate cd = dq.front();
                    dq.pop_front();
                    for (int k = 0; k < 4; k++) {
                        int m_r = cd.first + move_row[k];
                        int m_c = cd.second + move_col[k];
                        if (m_r >= 0 && m_r < N && m_c >= 0 && m_c < N && !visited[m_r][m_c] && M[m_r][m_c]) {
                                visited[m_r][m_c] = 1;
                                dq.push_back(make_pair(m_r, m_c));
                                cnt++;
                        }
                    }
                }
                total.push_back(cnt);
                cnt = 0;
            }
        }
    }
}

void resize() {
    M.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        M[i].resize(N);
        visited[i].resize(N);
        fill(visited[i].begin(), visited[i].end(), 0);
    }
}