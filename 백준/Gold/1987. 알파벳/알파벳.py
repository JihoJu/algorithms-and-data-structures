import sys

sys.setrecursionlimit(15000)
input = sys.stdin.readline


def dfs(x, y, total):
    global answer

    answer = max(answer, total)  # 지나온 말의 최대 칸 수 계산

    for i in range(4):
        px = x + dx[i]
        py = y + dy[i]
        if 0 <= px < R and 0 <= py < C and not v_alpha[ord(map[px][py]) - ord("A")]:
            v_alpha[ord(map[px][py]) - ord("A")] = 1  # 현재 위치 알파벳 체크
            dfs(px, py, total + 1)
            v_alpha[ord(map[px][py]) - ord("A")] = 0  # 이전 위치로 되돌아올 때 현재 위치 초기화


dx = [0, 0, -1, 1]  # 좌우상하
dy = [-1, 1, 0, 0]

R, C = map(int, input().strip().split())

map = [list(input().strip()) for _ in range(R)]
v_alpha = [0 for _ in range(26)]  # 지나온 알파벳 체크

answer = 0
v_alpha[ord(map[0][0]) - ord("A")] = 1


dfs(0, 0, 1)
print(answer)
