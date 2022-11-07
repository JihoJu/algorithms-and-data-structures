import sys
import ast

input = sys.stdin.readline


def add(a, b):
    return a + b


def sub(a, b):
    return a - b


def mul(a, b):
    return a * b


def divide(a, b):
    if a < 0 and b > 0:
        return -1 * ((-1 * a) // b)
    return a // b


def dfs(depth, value):
    global max_value, min_value

    if depth == len(A):
        max_value, min_value = max(value, max_value), min(value, min_value)
    else:
        for i in range(4):
            if op_num[i]:
                op_num[i] -= 1
                dfs(depth + 1, op_func[i](value, A[depth]))
                op_num[i] += 1


N = int(input())
A = list(map(int, input().strip().split(" ")))
op_func = [add, sub, mul, divide]
op_num = list(map(int, input().strip().split(" ")))

global max_value, min_value

max_value, min_value = float("-inf"), float("inf")
dfs(1, A[0])

print(max_value)
print(min_value)