// 바이러스
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, P, cnt = 0;
vector<vector<int> > network;
vector<int> visited;

void sol(int node) {
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && network[node][i]) {
            visited[i] = 1;
            sol(i);
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P;
    network.resize(N + 1);
    for (int i = 1; i <= N; i++)
        network[i].resize(N + 1);

    int u, v;
    for (int i = 0; i < P; i++) {
        cin >> u >> v;
        network[u][v] = 1;
        network[v][u] = 1;
    }
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), 0);
    visited[1] = 1;
    sol(1);

    cout << cnt << '\n';

    return 0;
}