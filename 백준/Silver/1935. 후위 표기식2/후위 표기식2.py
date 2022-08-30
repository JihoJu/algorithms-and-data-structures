import sys
import time


input = sys.stdin.readline


def operate(op, a, b):
    if op == "+":
        return float(a + b)
    elif op == "-":
        return float(a - b)
    elif op == "*":
        return float(a * b)
    elif op == "/":
        return float(a) / b


N = int(input())
exp = input().strip()
val = [int(input()) for _ in range(N)]

alpha_val = [0] * 26

i = 0
for e in exp:
    if e.isalpha() and not alpha_val[ord(e) - ord("A")]:
        alpha_val[ord(e) - ord("A")] = val[i]
        if i + 1 >= N:
            break
        i += 1

stack = []

for e in exp:
    if e.isalpha():
        stack.append(alpha_val[ord(e) - ord("A")])
    else:
        operand2 = stack.pop()
        operand1 = stack.pop()
        stack.append(operate(e, operand1, operand2))

print(f"{stack.pop():.2f}")
