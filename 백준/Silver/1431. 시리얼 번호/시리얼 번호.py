from curses.ascii import isdigit
import sys
from functools import cmp_to_key


def get_digit_sum(s):
    return sum(int(c) for c in s if isdigit(c))


def cmp(g1, g2):
    if len(g1) == len(g2):
        if get_digit_sum(g1) == get_digit_sum(g2):
            for c1, c2 in zip(g1, g2):
                if c1 != c2:
                    return ord(c1) - ord(c2)
        else:
            return get_digit_sum(g1) - get_digit_sum(g2)
    else:
        return len(g1) - len(g2)


input = sys.stdin.readline

N = int(input())
guitars = [input().strip() for _ in range(N)]

for e in sorted(guitars, key=cmp_to_key(cmp)):
    print(e)
