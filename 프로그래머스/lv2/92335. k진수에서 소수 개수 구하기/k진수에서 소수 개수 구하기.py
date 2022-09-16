from math import sqrt

def transform(n, k):
    res = ""
    while n > 0:
        m = n % k
        res += str(m)
        n //= k
    
    return res[::-1]

def is_prime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    
    return True

def get_nums(S: str):
    nums = []
    
    num = ""
    for i in range(len(S)):
        if S[i] == '0':
            if len(num) != 0:
                nums.append(int(num))
            num = ""
        else:
            num += S[i]
            
    if len(num) != 0:
        nums.append(int(num))
    
    return nums

def solution(n, k):
    answer = 0
    
    tran = transform(n, k)  # 10진수 -> n 진수 변환
    in_nums = get_nums(tran)    # n진수에 들어있는 10진수
    
    for num in in_nums:
        if is_prime(num):
            answer += 1
    
    return answer