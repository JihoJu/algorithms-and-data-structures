from collections import deque

def get_border_value(arr, s_row, e_row, s_col, e_col):
    res = deque()
    
    for i in range(s_col, e_col):
        res.append(arr[s_row][i])
    for i in range(s_row, e_row):
        res.append(arr[i][e_col])
    for i in range(e_col, s_col, -1):
        res.append(arr[e_row][i])
    for i in range(e_row, s_row, -1):
        res.append(arr[i][s_col])
    
    res.rotate(1)
    return (min(res), res)

def rotate_border_value(arr, s_row, e_row, s_col, e_col, value):
    for i in range(s_col, e_col):
        arr[s_row][i] = value.popleft()
    for i in range(s_row, e_row):
        arr[i][e_col] = value.popleft()
    for i in range(e_col, s_col, -1):
        arr[e_row][i] = value.popleft()
    for i in range(e_row, s_row, -1):
        arr[i][s_col] = value.popleft()
    
    return arr

def solution(rows, columns, queries):
    answer = []
    
    array = [[0 for col in range(columns + 1)] for row in range(rows + 1)]
    val = 1
    for i in range(1, rows + 1):
        for j in range(1, columns + 1):
            array[i][j] = val
            val += 1
    
    for q in queries:
        s_row, s_col, e_row, e_col = q
        min_value, border_value = get_border_value(array, s_row, e_row, s_col, e_col)
        array = rotate_border_value(array, s_row, e_row, s_col, e_col, border_value)
        answer.append(min_value)
    return answer