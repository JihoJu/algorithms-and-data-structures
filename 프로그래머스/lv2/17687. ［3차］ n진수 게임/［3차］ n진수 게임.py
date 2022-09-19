DIGITS = '0123456789ABCDEF'

def transform(n, num):
    if num == 1:
        return '01'
    
    res = ""
    while num > 0:
        res += DIGITS[num % n]
        num //= n
    
    return res[::-1]

def solution(n, t, m, p):
    answer = ""
    num = 1
    cnt, order = 0, 0
    
    while True:
        t_num = transform(n, num)
        
        for tn in t_num:
            if order == (p-1):
                cnt += 1
                answer += tn
            order = (order + 1) % m
            if cnt >= t:
                return answer
        num += 1
    
    return answer