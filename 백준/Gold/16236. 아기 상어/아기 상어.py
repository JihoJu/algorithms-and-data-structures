import sys
from collections import deque
import functools


input = sys.stdin.readline


def compare(a, b):
    if a[0] == b[0]:
        return a[1] - b[1]
    return a[0] - b[0]


def dfs():
    global shark_x, shark_y, N

    min_move = float("inf")  # 상어 초기 이동 거리 무한대 가정
    eq_distance = []  # 가장 가까운 먹을 수 있는 물고기 중 거리가 같은 물고기 위치
    visited = [[0 for _ in range(N)] for _ in range(N)]
    visited[shark_x][shark_y] = 1
    dq = deque()
    dq.append((shark_x, shark_y, 0))

    while len(dq) != 0:
        px, py, move_cnt = dq.popleft()
        for i in range(4):
            mx = px + dx[i]
            my = py + dy[i]

            if 0 <= mx < N and 0 <= my < N and not visited[mx][my]:
                if MAP[mx][my] != 0 and MAP[mx][my] < shark_size[0]:
                    # 현재 먹을 수 있는 물고기까지 움직인 거리 > 이전에 먹은 물고기까지의 거리
                    if move_cnt + 1 > min_move:
                        continue
                    min_move = min(move_cnt + 1, min_move)
                    eq_distance.append((mx, my))
                    visited[mx][my] = 1
                elif MAP[mx][my] == 0 or MAP[mx][my] == shark_size[0]:
                    dq.append((mx, my, move_cnt + 1))
                    visited[mx][my] = 1

    # 먹을 먹이가 아무것도 없는 경우
    if min_move == float("inf"):
        return -1

    if len(eq_distance) != 1:  # 거리가 같은 물고기가 1마리보다 많은 경우
        eq_distance = sorted(eq_distance, key=functools.cmp_to_key(compare))

    MAP[shark_x][shark_y] = 0  # 기존 상어 위치 0 으로
    shark_x, shark_y = eq_distance[0]
    MAP[shark_x][shark_y] = 9  # 이동한 상어 위치 9
    shark_size[1] += 1  # 물고기 먹은 횟수
    if shark_size[0] == shark_size[1]:  # 상어 크기와 먹은 물고기 수가 같을 경우
        shark_size[0] += 1  # 상어 사이즈 + 1
        shark_size[1] = 0  # 먹은 물고기 수 초기화

    return min_move


dx = [0, 0, -1, 1]  # 좌우상하
dy = [-1, 1, 0, 0]

N = int(input())
MAP = [list(map(int, input().strip().split())) for _ in range(N)]

fish_pos = deque()  # 모든 물고기 위치 (사이즈, x, y)
total_cnt = 0
shark_size = [2, 0]  # [0]: shark size, [1]: 잡아먹은 물고기

for i in range(N):
    for j in range(N):
        if MAP[i][j] == 9:
            shark_x, shark_y = i, j

while True:
    move_cnt = dfs()
    if move_cnt == -1:  # 먹을 수 있는 먹이가 아무것도 없는 경우
        break
    total_cnt += move_cnt

print(total_cnt)
