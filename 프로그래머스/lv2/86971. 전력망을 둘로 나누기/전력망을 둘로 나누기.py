import sys

sys.setrecursionlimit(10**6)

def dfs(u):
    global cnt
    
    visited[u] = 1
    cnt += 1
    
    for i in range(1, len(M[u])):
        if M[u][i] == 1 and not visited[i]:
            dfs(i)

def solution(n, wires):
    answer = float('inf')
    
    global M, visited, cnt
    M = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    
    # tree 초기화
    for u, v in wires:
        M[u][v] = 1
        M[v][u] = 1
    
    cnt = 0
    for u, v in wires:
        visited = [0 for _ in range(n + 1)]
        visited[0] = 1
        M[u][v], M[v][u] = 0, 0
        dfs(u)
        cnt1, cnt = cnt, 0
        cnt2 = dfs(v)
        cnt2, cnt = cnt, 0
        answer = min(abs(cnt1 - cnt2), answer)
        M[u][v], M[v][u] = 1, 1
    
    return answer