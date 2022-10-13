import sys
from collections import deque


def dfs(depth):
    global M, result

    if len(comp) == M:
        dist = 0
        for pos in home_pos:
            dist += min(abs(pos[0] - r) + abs(pos[1] - c) for r, c in comp)
        result = min(result, dist)
        return

    elif depth == len(chicken_pos):
        return

    comp.append(chicken_pos[depth])
    dfs(depth + 1)

    comp.pop()
    dfs(depth + 1)


input = sys.stdin.readline

N, M = map(int, input().strip().split())
MAP = [list(map(int, input().strip().split())) for _ in range(N)]

home_pos = [(i, j) for i in range(N) for j in range(N) if MAP[i][j] == 1]
chicken_pos = [(i, j) for i in range(N) for j in range(N) if MAP[i][j] == 2]
comp = deque()

result = float("inf")
dfs(0)

print(result)
