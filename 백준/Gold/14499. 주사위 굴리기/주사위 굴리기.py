import sys

input = sys.stdin.readline

dice_num = [0, 0, 0, 0, 0, 0]
dice = [1, 2, 3, 4, 5, 6]  # 위, 뒤, 오, 왼, 앞, 바닥
move = [(0, 0), (0, 1), (0, -1), (-1, 0), (1, 0)]  # 1: 동 / 2: 서 / 3: 북 / 4: 남


def turn(dir):
    global dice

    a, b, c, d, e, f = dice
    if dir == 1:
        dice = [d, b, a, f, e, c]
    elif dir == 2:
        dice = [c, b, f, a, e, d]
    elif dir == 3:
        dice = [e, a, c, d, f, b]
    elif dir == 4:
        dice = [b, f, c, d, a, e]


N, M, x, y, K = map(int, input().split())
MAP = [list(map(int, input().strip().split())) for _ in range(N)]


for dir in list(map(int, input().strip().split())):
    mx, my = x + move[dir][0], y + move[dir][1]
    if 0 <= mx < N and 0 <= my < M:
        turn(dir)
        if MAP[mx][my] == 0:
            MAP[mx][my] = dice_num[dice[5] - 1]
            print(dice_num[dice[0] - 1])
        else:
            dice_num[dice[5] - 1], MAP[mx][my] = MAP[mx][my], 0
            print(dice_num[dice[0] - 1])
        x, y = mx, my
