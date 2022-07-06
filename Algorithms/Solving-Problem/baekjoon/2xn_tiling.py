""" 11726번 DP 문제 """


def solution(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2

    return solution(n - 1) + solution(n - 2)


def dp_solution(n):
    cache = [0 for index in range(n + 1)]
    cache[1] = 1
    cache[2] = 2

    for index in range(3, n + 1):
        cache[index] = cache[index - 1] + cache[index - 2]

    return cache[n] % 10007
