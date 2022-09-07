import sys

sys.setrecursionlimit(10**6)

def dfs(n, com):
    visited[com] = 1
    for i in range(n):
        if i == com:
            continue
        if network[com][i] == 1 and visited[i] == 0:
            dfs(n, i)

def solution(n, computers):
    answer = 0
    
    global network, visited
    n = len(computers)  # 컴퓨터 개수
    visited = [0 for _ in range(n)]
    network = computers[:]
    
    for i in range(n):
        if visited[i] == 1:
            continue
        dfs(n, i)
        answer += 1
        
    return answer