# 연결 요소 개수
from glob import glob
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(u):
    visited[u] = 1
    for v in graph[u]:
        if visited[v] == 0:
            dfs(v)


def get_start_node():
    global N

    for i in range(1, N + 1):
        if visited[i] == 0:
            return i

    return -1


N, M = map(int, input().strip().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().strip().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [0] * (N + 1)
cnt = 0  # 연결 요소 개수
while True:
    start = get_start_node()
    if start == -1:
        break
    dfs(start)
    cnt += 1

print(cnt)
