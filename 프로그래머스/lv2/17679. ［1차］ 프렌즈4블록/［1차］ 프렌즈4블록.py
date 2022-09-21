from copy import deepcopy

def solution(m, n, board):
    board = [list(board[i]) for i in range(m)]
    rm_board = [deepcopy(board[i]) for i in range(m)]
    
    while True:
        is_end = 1
        for i in range(m - 1):
            for j in range(n - 1):
                if board[i][j] == 1: continue
                if board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]:
                    is_end = 0
                    rm_board[i][j], rm_board[i][j+1], rm_board[i+1][j], rm_board[i+1][j+1] = 1, 1, 1, 1
        if is_end:
            break
        for c in range(n):
            pos, cnt0 = -1, 0
            arr = []
            for r in range(m-1, -1, -1):
                if pos == -1 and rm_board[r][c] == 1:
                    pos = r

                if pos == -1:
                    continue

                if rm_board[r][c] == 1:
                    cnt0 += 1
                else:
                    arr.append(rm_board[r][c])
                    
            for r in range(m-1, -1, -1):
                board[r][c] = rm_board[r][c]
            if pos == -1 or len(arr) == 0:
                continue    
            arr.extend([1]*cnt0)
            for r in range(pos, -1, -1):
                board[r][c]=rm_board[r][c]=arr.pop(0)
            
    answer = sum(board[i].count(1) for i in range(m))
    
    return answer