import sys

input = sys.stdin.readline


def turn_left(d):
    d -= 1
    if d < 0:
        d = 3
    return d


N, M = map(int, input().strip().split())
r, c, d = map(int, input().strip().split())
MAP = [list(map(int, input().strip().split())) for _ in range(N)]


forward = [(-1, 0), (0, 1), (1, 0), (0, -1)]

MAP[r][c] = 2
is_done, clear_cnt = 0, 1
while not is_done:
    is_clear = 0

    for _ in range(4):
        d = turn_left(d)
        mx, my = r + forward[d][0], c + forward[d][1]
        if 0 <= mx < N and 0 <= my < M and MAP[mx][my] == 0:
            MAP[mx][my] = 2
            r, c = mx, my
            clear_cnt += 1
            is_clear = 1
            break

    if not is_clear:
        mx, my = r - forward[d][0], c - forward[d][1]
        if 0 <= mx < N and 0 <= my < M and (MAP[mx][my] == 0 or MAP[mx][my] == 2):
            r, c = mx, my
        else:
            is_done = 1

print(clear_cnt)
