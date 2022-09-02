def solution(s):
    stack = 0
    
    for p in s:
        if p == '(':
            stack += 1
        else:   # ')'
            if stack <= 0:
                return False
            else:
                stack -= 1
                
    if stack >= 1:
        return False
        
    return True