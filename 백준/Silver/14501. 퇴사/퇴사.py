import sys

input = sys.stdin.readline

N = int(input().strip())
TP = [list(map(int, input().strip().split())) for _ in range(N)]
max_profit = 0


def dfs(i, acc):
    global max_profit

    if i >= N - 1:
        if i == N - 1 and TP[i][0] == 1:
            acc += TP[i][1]
        max_profit = max(max_profit, acc)
    else:
        for j in range(i, N):
            if (TP[j][0] + j - 1) < N:
                dfs(TP[j][0] + j, acc + TP[j][1])
            else:
                max_profit = max(max_profit, acc)


dfs(0, 0)
print(max_profit)
