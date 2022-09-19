mapping = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

def transform(n, num):
    if num == 1:
        return '01'
    res = ""
    while num > 0:
        res += mapping[num % n]
        num //= n
    
    return res[::-1]

def solution(n, t, m, p):
    answer = ""
    current_num = 1
    cnt = 0
    order = 0
    
    while True:
        t_num = transform(n, current_num)
        
        for tn in t_num:
            if order == (p-1):
                cnt += 1
                answer += tn
            order = (order + 1) % m
            if cnt >= t:
                return answer
        current_num += 1
    
    return 1



