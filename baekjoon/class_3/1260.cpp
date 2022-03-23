// DFS와 BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

bool cmp_desc(const int a, const int b) {
    return a > b;
}

bool cmp_asc(const int a, const int b) {
    return a < b;
}

vector<int> graph[1001];

void dfs_stack(int start, vector<int> graph[]) {
    vector<int> stack;
    int visited[1001] = {0};

    stack.push_back(start);
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        if (!visited[u]) {
            visited[u] = 1;
            cout << u << ' ';
        }
        else continue;

        sort(graph[u].begin(), graph[u].end(), cmp_desc);   // 이렇게 sort 를 하면 main 함수의 graph[u] 가 아예 졍렬
        for (int v = 0; v < graph[u].size(); v++) {
            if (!visited[graph[u][v]])
                stack.push_back(graph[u][v]);
        }   
    }
}

void dfs_recursive(int start, vector<int> graph[]) {
    int visited[1001] = {0};

    visited[start] = 1;
    cout << start << ' ';
    for (int i = 0; i < graph[start].size(); i++) {
        if (!visited[graph[start][i]])
            dfs_recursive(graph[start][i], graph);
    }
}

void bfs(int start, vector<int> graph[]) {
    deque<int> dq;
    int visited[1001] = {0};

    dq.push_back(start);
    visited[start] = 1;
    cout << start << ' ';
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        sort(graph[u].begin(), graph[u].end(), cmp_asc);
        for (int i = 0; i < graph[u].size(); i++) {
            if (!visited[graph[u][i]]){
                dq.push_back(graph[u][i]);
                visited[graph[u][i]] = 1;
                cout << graph[u][i] << ' ';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, V;

    cin >> N >> M >> V;

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs_stack(V, graph);
    cout << '\n';
    // dfs_recursive(V, graph);
    bfs(V, graph);

    return 0;
}