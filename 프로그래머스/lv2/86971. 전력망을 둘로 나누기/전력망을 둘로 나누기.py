import sys

sys.setrecursionlimit(10**6)

def dfs(u):
    global cnt
    
    visited[u] = 1
    cnt += 1
    for i, v in enumerate(M[u]):
        if i != 0 and v == 1 and not visited[i]:
            dfs(i)
    

def solution(n, wires):
    answer = float('inf')
    
    global M, visited, cnt
    M = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    
    # tree 초기화
    for u, v in wires:
        M[u][v] = 1
        M[v][u] = 1
    
    for u, v in wires:
        visited = [0 for _ in range(n + 1)]
        visited[0] = 1
        M[u][v] = 0
        M[v][u] = 0
        cnt = 0
        dfs(u)
        cnt1 = cnt
        cnt = 0
        dfs(v)
        cnt2 = cnt
        answer = min(abs(cnt1 - cnt2), answer)
        M[u][v] = 1
        M[v][u] = 1
    
    return answer