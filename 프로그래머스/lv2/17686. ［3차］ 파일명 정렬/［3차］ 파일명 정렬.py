import re
from functools import cmp_to_key

def cmp(a: list, b: list):
    # s1, s2 = re.sub(r"[-. ]", "", a[0]), re.sub(r"[-. ]", "", b[0])
    s1, s2 = a[0].lower(), b[0].lower()
    
    if s1.lower() == s2.lower():
        if int(a[1]) == int(b[1]):
            return 0
        else:
            if int(a[1]) < int(b[1]):
                return -1
            else:
                return 1
    else:        
        if s1.lower() < s2.lower():
            return -1
        else:
            return 1
    
def solution(files):
    num_regx = re.compile(r'\d{1,5}')
    filenames = []
    for file in files:
        num = num_regx.search(file)[0]
        name = num_regx.split(file, maxsplit=1)
        name.insert(1, num)
        filenames.append(name)
    
    sorted_file = sorted(filenames, key=cmp_to_key(cmp))
    answer = ["".join(file) for file in sorted_file]
        
    return answer