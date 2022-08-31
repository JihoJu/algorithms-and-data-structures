import sys

input = sys.stdin.readline

N, M = map(int, input().strip().split())
J = int(input())  # 떨어지는 사과 개수
apple = [int(input()) for _ in range(J)]

pos = [i for i in range(1, M + 1)]
move_cnt = 0  # 바구니 이동 거리

for screen in apple:  # screen: 사과가 떨어지는 위치
    # 현재 바구니 위치에 사과가 떨어지는 경우
    if screen in pos:
        continue
    else:  # 현재 바구니 위치에 사과가 떨어지지 않는 경우
        if screen > pos[0]:
            move_cnt += screen - (M - 1) - pos[0]
            pos = [i for i in range(screen - (M - 1), screen + 1)]
        else:
            move_cnt += pos[0] - screen
            pos = [i for i in range(screen, screen + M)]

print(move_cnt)
