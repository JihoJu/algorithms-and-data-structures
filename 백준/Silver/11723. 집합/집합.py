import sys

input = sys.stdin.readline

N = int(input().strip())

S = set()

for _ in range(N):
    line = input().strip()
    if line == "all":
        S.update(
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
        )
    elif line == "empty":
        S = set()
    else:
        op, n = line.split()
        n = int(n)
        if op == "add":
            S.add(n)
        elif op == "remove":
            if n in S:
                S.remove(n)
        elif op == "check":
            if n in S:
                print(1)
            else:
                print(0)
        elif op == "toggle":
            if n in S:
                S.remove(n)
            else:
                S.add(n)
