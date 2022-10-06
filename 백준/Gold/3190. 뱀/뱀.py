import sys

input = sys.stdin.readline

dx = [0, 1, 0, -1]  # 동 0 남 1 서 2 북 3
dy = [1, 0, -1, 0]  # 동 남 서 북

N = int(input().strip())
MAP = [[0] * N for _ in range(N)]

K = int(input().strip())
for _ in range(K):
    x, y = map(int, input().strip().split())
    MAP[x - 1][y - 1] = 1  # 사과 1 / 자신 몸: 2


L = int(input().strip())
turn_info = [input().strip().split() for _ in range(L)]

time, d = 0, 0  # d:0 동
head_x, head_y = 0, 0
tracking = []
while True:
    time += 1

    mx, my = head_x + dx[d], head_y + dy[d]
    if 0 <= mx < N and 0 <= my < N and MAP[mx][my] != 2:
        MAP[head_x][head_y] = 2
        tracking.append([head_x, head_y])
        # 사과가 있는 경우
        if MAP[mx][my] == 1:
            MAP[mx][my] = 0
        else:
            if len(tracking) != 0:
                tx, ty = tracking.pop(0)
                MAP[tx][ty] = 0
        head_x, head_y = mx, my
    else:
        break

    if len(turn_info) != 0 and time == int(turn_info[0][0]):
        _, turn_pos = turn_info.pop(0)
        if turn_pos == "L":
            d -= 1
            if d == -1:
                d = 3
        else:
            d = (d + 1) % 4
print(time)
