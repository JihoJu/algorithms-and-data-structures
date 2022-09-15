import sys

input = sys.stdin.readline

N = int(input())

triangle = [list(map(int, input().split())) for _ in range(N)]
cost = [[0 for _ in range(i + 1)] for i in range(N - 1)]
cost.extend([triangle[N - 1]])

if N >= 3:
    for i in range(N - 2, 0, -1):
        for j in range(i + 1):
            cost[i][j] = max(
                triangle[i][j] + cost[i + 1][j], triangle[i][j] + cost[i + 1][j + 1]
            )
    answer = max(cost[1][0], cost[1][1]) + triangle[0][0]
else:
    answer = max(cost[1][0], cost[1][1]) + triangle[0][0] if N == 2 else triangle[0][0]

print(answer)