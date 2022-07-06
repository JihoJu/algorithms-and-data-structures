""" 9461번 DP """

"""
    def solution(n):
        cache = [0 for index in range(101)]
    
        cache[1], cache[2], cache[3] = 1, 1, 1
        cache[4], cache[5] = 2, 2
    
        for index in range(6, 101):
            cache[index] = cache[index - 1] + cache[index - 5]
    
        return cache[n]
"""

cache = [0 for index in range(101)]
cache[1], cache[2], cache[3] = 1, 1, 1
cache[4], cache[5] = 2, 2

for index in range(6, 101):
    cache[index] = cache[index - 1] + cache[index - 5]

T = int(input())
for index in range(T):
    print(cache[int(input())])
