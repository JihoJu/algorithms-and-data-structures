# 불!
import sys
from collections import deque

""" sys.setrecursionlimit()
    파이썬 기본 재귀 깊이 제한은 1000으로 매우 얕은 편! 
    -> 재귀로 풀 경우 이 제한에 걸리는데 코딩테스트 환경에선 에러 메시지를 볼 수 없어 
        런타임 에러로 무엇이 잘못되었는지 알 수 없다.
    => 꼭 필요!!
"""
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


def bfs():
    # 처음 J의 위치가 가장 자리에 있는 경우
    if pos[0][0] == 0 or pos[0][0] == R - 1 or pos[0][1] == 0 or pos[0][1] == C - 1:
        return 1
    # 불 이동을 이동 횟수로 표현
    while fire:
        x, y = fire.popleft()
        for i in range(4):
            mx = x + dx[i]
            my = y + dy[i]
            if 0 <= mx < R and 0 <= my < C and not F_visited[mx][my] and map[mx][my] != '#':
                F_visited[mx][my] = F_visited[x][y] + 1
                fire.append((mx, my))

    while pos:
        x, y = pos.popleft()
        for i in range(4):
            mx = x + dx[i]
            my = y + dy[i]
            if 0 <= mx < R and 0 <= my < C:
                if not J_visited[mx][my] and map[mx][my] != '#':
                    # (mx, my)에 불이 없는 경우도 생각!!!
                    if F_visited[mx][my] > J_visited[x][y] + 1 or not F_visited[mx][my]:
                        J_visited[mx][my] = J_visited[x][y] + 1
                        if mx == 0 or mx == R - 1 or my == 0 or my == C - 1:
                            return J_visited[mx][my] + 1
                        pos.append((mx, my))

    return "IMPOSSIBLE"


R, C = map(int, input().split())
map = [list(input().strip()) for _ in range(R)]
J_visited, F_visited = [[0] * C for r in range(R)], [[0] * C for r in range(R)]

pos, fire = deque(), deque()  # pos: 이동 위치
for i in range(R):
    for j in range(C):
        if map[i][j] == "J":
            pos.append((i, j))
        if map[i][j] == "F":
            fire.append((i, j))

# 상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

print(bfs())
