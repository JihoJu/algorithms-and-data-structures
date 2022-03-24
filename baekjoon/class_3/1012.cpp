// 유기농 배추
#include <iostream>
#include <vector>

using namespace std;

void clear_map(vector<vector<int> > &m) {
    vector<vector<int> > empty;
    swap(m, empty);
}

void resize(vector<vector<int> > &map, int n, int m) {
    map.resize(n);
    for (int i = 0; i < n; i++) {
        map[i].resize(m);
    }
}

void make_wall(vector<vector<int> > &map, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1)
                map[i][j] = 2;
            if (j == 0 || j == m - 1)
                map[i][j] = 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, K, x, y;
    vector<vector<int> > map;
    vector<vector<int> > visited;
    vector<pair<int, int> > stack;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        
        resize(map, N + 2, M + 2);
        resize(visited, N + 2, M + 2);
        make_wall(map, N + 2, M + 2);
        make_wall(visited, N + 2, M + 2);

        // 입력: 시작 지점은 1, 1
        for (int k = 0; k < K; k++) {
            cin >> y >> x;
            map[x + 1][y + 1] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    cnt++; // 지렁기 개수
                    stack.push_back(make_pair(i, j));
                    while (!stack.empty()) {
                        pair<int, int> p = stack.back();
                        stack.pop_back();
                        if (!visited[p.first][p.second]) visited[p.first][p.second] = 1;
                        else continue;

                        if (!visited[p.first - 1][p.second] && map[p.first - 1][p.second] == 1) 
                            stack.push_back(make_pair(p.first - 1, p.second));
                        if (!visited[p.first][p.second - 1] && map[p.first][p.second - 1] == 1) 
                            stack.push_back(make_pair(p.first, p.second - 1));
                        if (!visited[p.first + 1][p.second] && map[p.first + 1][p.second] == 1) 
                            stack.push_back(make_pair(p.first + 1, p.second));
                        if (!visited[p.first][p.second + 1] && map[p.first][p.second + 1] == 1) 
                            stack.push_back(make_pair(p.first, p.second + 1));
                    }
                }
            }
        }
        cout << cnt << '\n';
        clear_map(map);
        clear_map(visited);
    }

    return 0;
}