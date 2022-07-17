# IOIOI
import sys

input = sys.stdin.readline

N = int(input())
M = int(input())
S = input().strip()


def get_partial_match(search):
    m = len(search)
    ret = [0 for i in range(m)]

    begin = 1
    match = 0

    while (begin + match) < m:

        if search[begin + match] == search[match]:
            match += 1
            ret[begin + match - 1] = match

        else:
            if match == 0:
                begin += 1
            else:
                begin += match - pi[match - 1]
                match = pi[match - 1]

    return ret


item = ["I" for _ in range(N + 1)]
p = "O".join(item)

pi = get_partial_match(p)

psize = 2 * N + 1
begin = 0
match = 0
cnt = 0

while begin <= M - psize:
    if (match < psize) and S[begin + match] == p[match]:
        match += 1

        if match == psize:
            cnt += 1
    else:
        if match == 0:
            begin += 1
        else:
            begin += match - pi[match - 1]
            match = pi[match - 1]

print(cnt)
