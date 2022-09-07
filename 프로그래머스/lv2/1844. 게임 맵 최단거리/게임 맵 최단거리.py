from collections import deque

dx = [0, 0, -1, 1]  # 좌우상하
dy = [-1, 1, 0, 0]

def solution(maps):
    answer = -1
    
    n = len(maps)   # 행
    m = len(maps[0])    # 열

    # bfs
    visited = [[0 for _ in range(m)] for _ in range(n)]
    dq = deque()    
    dq.append((0, 0, 1))
    visited[0][0] = 1
    
    while len(dq) != 0:
        x, y, cnt = dq.popleft()
        for i in range(4):
            mx = x + dx[i]
            my = y + dy[i]
            if (0 <= mx < n
               and 0 <= my < m
               and maps[mx][my] == 1
               and visited[mx][my] == 0):
                if mx == n-1 and my == m-1:
                    return cnt + 1
                dq.append((mx, my, cnt+1))
                visited[mx][my] = 1
                
    return -1