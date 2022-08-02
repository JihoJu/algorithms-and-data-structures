// 트리의 지름
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N;  // 노드 개수
vector<pair<int, int>> G[10001];
vector<int> visited(10001, 0);
int MAX_PATH = INT_MIN, longest_node;

/*
    트리의 어떤 정점에서 경로가 가장 긴 정점은 원의 지름을 이루는 두 개의 정점 중 하나가 될 것이다.
    1. 어떤 정점에서 경로가 가장 긴 노드 번호를 찾자.
    2. 1번에서 찾은 노드에서 다시 경로가 가장 긴 노드를 찾으면 그 경로가 지름이 된다.
*/

void dfs(int u, int path) {
    if (visited[u]) return; // 이미 방문한 노드를 재방문 방지

    visited[u] = 1;
    if (MAX_PATH < path) {
        MAX_PATH = path;
        longest_node = u;
    }

    for (int i = 0; i < G[u].size(); i++)
        dfs(G[u][i].first, path + G[u][i].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int p, c, w;   // p: 부모 노드, c: 자식 노드, w: 가중치
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> c >> w;
        
        G[p].push_back(make_pair(c, w));
        G[c].push_back(make_pair(p, w));
    }

    // 1번 노드에서 경로가 가장 긴 노드 탐색
    dfs(1, 0);

    // 위에서 탐색한 노드 기준 경로가 가장 긴 노드 탐색 및 경로의 최대값 계산
    MAX_PATH = INT_MIN;
    fill(visited.begin(), visited.begin() + (N + 1), 0);
    dfs(longest_node, 0);
    
    cout << MAX_PATH << '\n';

    return 0;
}