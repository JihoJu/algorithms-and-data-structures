import re
from collections import deque

priority = [0, 0, 0]    # 우선순위 경우의 수 표현
op = ['+', '-', '*']    # 연산자
max_value = float('-inf')

def calculate(a, b, op):
    if op == '+':
        return a + b
    if op == '-':
        return a - b
    return a * b

def dfs(exp):
    global max_value
    # 주어진 수식이 모두 계산된 경우
    if len(exp) == 1:
        max_value = max(abs(exp[0]), max_value) # 최대값 구하기
        return
    
    for i in range(3):
        # 이미 우선순위가 정해진 경우
        if priority[i]:
            continue
        priority[i] = 1
        copy_exp = exp.copy()
        cal_exp = deque()   # 계산 결과
        while len(copy_exp) != 0:
            e = copy_exp.popleft()
            if e == op[i]:
                cal_exp.append(calculate(int(cal_exp.pop()), int(copy_exp.popleft()), op[i]))
            else:
                cal_exp.append(e)
        dfs(cal_exp)
        priority[i] = 0
        

def solution(expression):
    exp = deque(re.findall(r'\d+|[^\d]', expression))
    
    dfs(exp)
    
    return max_value