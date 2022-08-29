import sys
from collections import deque


input = sys.stdin.readline


def dfs():
    global N, shark_x, shark_y
    min_move = float("inf")

    visited = [[0 for _ in range(N)] for _ in range(N)]  # 방문 정보
    eq_dis_fish = []  # 같은 위치의 잡아먹을 수 있는 물고기 위치 -> dfs 로 최소거리를 구한 후 같은 거리에 있는 물고기 insert

    dq = deque()
    dq.append((shark_x, shark_y, 0))
    visited[shark_x][shark_y] = 1

    while len(dq) != 0:
        px, py, move = dq.popleft()
        for i in range(4):
            mx = px + dx[i]
            my = py + dy[i]

            if 0 <= mx < N and 0 <= my < N and not visited[mx][my]:
                # 상어가 물고기를 잡아 먹을 수 있는 case
                if M[mx][my] != 0 and M[mx][my] < shark_info[0]:
                    # dfs 로 정해진 최소 거리보다 작거나 같은 경우 => == 등호도 상관 x
                    if (move + 1) <= min_move:
                        min_move = min(min_move, move + 1)
                        eq_dis_fish.append((mx, my))
                        visited[mx][my] = 1
                # 상어가 지나갈 수 있는 case
                elif M[mx][my] == 0 or M[mx][my] == shark_info[0]:
                    dq.append((mx, my, move + 1))
                    visited[mx][my] = 1

    # 잡아먹을 수 있는 물고기가 없는 경우
    if min_move == float("inf"):
        return -1

    # 가장 위에 있는 물고기, 가장 왼쪽에 있는 물고기
    shark_x, shark_y = sorted(eq_dis_fish, key=lambda x: (x[0], x[1]))[0]
    M[shark_x][shark_y] = 0
    # 상어 정보 업데이트
    shark_info[1] += 1
    if shark_info[0] == shark_info[1]:
        shark_info[0] += 1
        shark_info[1] = 0

    return min_move


dx = [0, 0, -1, 1]  # 좌우상하
dy = [-1, 1, 0, 0]  # 좌우상하

N = int(input())
M = [list(map(int, input().strip().split())) for _ in range(N)]

# 상어 위치 찾기
for i in range(N):
    for j in range(N):
        if M[i][j] == 9:
            shark_x, shark_y = i, j
            M[i][j] = 0
            break

shark_info = [2, 0]  # [size, eat_cnt]
total_cnt = 0  # 총 이동거리

while True:
    move_cnt = dfs()
    if move_cnt == -1:
        break
    total_cnt += move_cnt

print(total_cnt)
