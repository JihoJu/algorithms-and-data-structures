from optparse import BadOptionError
import sys

input = sys.stdin.readline


def promising(depth):
    if depth < 0:
        return True

    x, y = empty[depth]
    value = board[x][y]
    # row check
    for i in range(9):
        if i != x and board[i][y] == value:
            return False
    # col check
    for i in range(9):
        if i != y and board[x][i] == value:
            return False

    # 3 x 3 matirx check
    r, c = x // 3 * 3, y // 3 * 3
    for i in range(r, r + 3):
        for j in range(c, c + 3):
            if i == x and j == y:
                continue
            if board[i][j] == value:
                return False
    return True


def dfs(depth):
    if promising(depth - 1):
        if depth == len(empty):
            for i in range(9):
                trans_row = list(map(str, board[i]))
                print("".join(trans_row))
            return 0
        else:
            x, y = empty[depth]
            origin = board[x][y]
            for i in range(1, 10):
                board[x][y] = i
                if dfs(depth + 1) == 0:
                    return 0
                board[x][y] = origin


board = [list(map(int, input().strip())) for _ in range(9)]
empty = [
    (i, j) for i in range(len(board)) for j in range(len(board[0])) if board[i][j] == 0
]
dfs(0)
