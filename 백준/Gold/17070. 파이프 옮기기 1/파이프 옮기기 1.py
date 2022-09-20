import sys

input = sys.stdin.readline

N = int(input().strip())
M = [list(map(int, input().strip().split())) for _ in range(N)]
dp = [[[0, 0, 0] for _ in range(N)] for _ in range(N)]

dp[0][1][0] += 1

for i in range(N):
    for j in range(N):
        if (i == j == 0) or (i == 0 and j == 1) or M[i][j] == 1:
            continue
        dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2]
        dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2]
        if 0 <= i - 1 < N and 0 <= j - 1 < N and M[i - 1][j] == 0 and M[i][j - 1] == 0:
            dp[i][j][2] = sum(dp[i - 1][j - 1])

print(sum(dp[N - 1][N - 1]))