import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**4)


def promising(i):
    k = 1

    while k < i:
        if col[k] == col[i] or abs(col[k] - col[i]) == (i - k):
            return False
        k += 1
    return True


def dfs(i):
    global cnt

    if promising(i):
        if i == N:
            cnt += 1
            return
        else:
            for c in range(1, N + 1):
                col[i + 1] = c
                dfs(i + 1)


N = int(input())

col = [0] * (N + 1)
cnt = 0


dfs(0)
print(cnt)
