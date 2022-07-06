//효율적인 해킹
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt, max_num = INT_MIN;
vector<int> g[10001];
vector<int> visited, result;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0 ; i < g[node].size(); i++) {
        if (!visited[g[node][i]]) {
            cnt++;
            dfs(g[node][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        g[v].push_back(u);
    }

    result.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        visited = vector<int> (N + 1, 0);   // 벡터 초기화 방법
        cnt = 0;
        dfs(i);
        result[i] = cnt;
        max_num = max(max_num, cnt);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == max_num)
            cout << i << ' ';
    }

    return 0;
}