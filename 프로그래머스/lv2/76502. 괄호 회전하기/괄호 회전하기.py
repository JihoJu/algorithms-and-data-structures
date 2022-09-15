left = ['(', '[', '{']
right = [')', ']', '}']

def is_right(s):
    stack = []
    for c in s:
        if c in left:
            stack.append(c)
        else:
            if len(stack) == 0 or stack[-1] != left[right.index(c)]:
                return False
            stack.pop()
            
    if len(stack) != 0:
        return False
    
    return True
    
def solution(s):
    answer = 0
    
    for i in range(len(s)):
        if is_right(s):
            answer += 1
        s = s[1:] + s[0]
        
    return answer