n = int(input())
cache = list()
result = 0  # 연산 횟수


def solution(n):
    if n == 1:
        return 0
    if n % 3 == 0:
        return solution(n / 3) + 1
    return


while proc != 1:
    result = min()
    if proc % 3 == 0:
        proc = proc / 3
    elif (proc - 1) % 3 == 0:
        proc = proc - 1
    elif proc % 2 == 0:
        proc = proc / 2
    else:
        proc = proc - 1
    result = result + 1

print(result)
