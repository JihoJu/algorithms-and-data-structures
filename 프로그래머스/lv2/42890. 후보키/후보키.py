from itertools import combinations 

def solution(relation):
    answer = 0
    N, M = len(relation) , len(relation[0])    # row, column 개수
    
    res, arr = [], [i for i in range(M)]
    for i in range(1, len(relation[0]) + 1):
        res = res + list(combinations(arr, i))  
    
    while len(res) > 0:
        keys = res.pop(0)
        
        values = ["" for _ in range(N)]
        for key in keys:
            for i in range(N):
                values[i] += relation[i][key]
        
        if len(set(values)) == N:
            answer += 1
            res = [e for e in res if not set(keys).issubset(set(e))]
    
    return answer