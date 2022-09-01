import sys
from heapq import heappush, heappop

input = sys.stdin.readline

N = int(input())

heap = []  # max heap

for _ in range(N):
    x = int(input())
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heappop(heap)[1])
    else:
        heappush(heap, (-x, x))
