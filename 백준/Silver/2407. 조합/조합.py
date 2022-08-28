import operator as op
from functools import reduce
import sys

input = sys.stdin.readline


def combination(n, m):
    m = min(n - m, m)

    top = reduce(op.mul, range(n, n - m, -1), 1)
    bottom = reduce(op.mul, range(1, m + 1), 1)

    return top // bottom


n, m = map(int, input().strip().split())

print(combination(n, m))
