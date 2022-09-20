conv = {'C#': '1', 'D#': '2', 'F#': '3', 'G#': '4', 'A#': '5', 'E#': '6', 'B#':'7'}

def get_runtime(start, end):
    h1, m1 = start.split(':')
    h2, m2 = end.split(':')
    
    if h1 == h2:
        return int(m2) - int(m1)
    else:
        return 60 - int(m1) + int(m2) + 60 * (int(h2) - int(h1) - 1)
    
def get_runtime_melody(runtime, melody):
    length = len(melody)    # 멜로디 길이

    if runtime <= length:
        return melody[:runtime]
    else:
        rep = runtime // length   # 반복 횟수
        rd = runtime % length   # 나머지
        
        total = melody * rep
        total += melody[:rd]
        
        return total

def trans(m):
    if len(m) == 1 or '#' not in m:
        return m
    
    res, i = "", 0
    while i < len(m) - 1:
        if m[i + 1] == '#':
            res += conv[m[i]+m[i+1]]
            i += 2
        else:
            res += m[i]
            i += 1
            
    if m[-1] != '#':
        res += m[-1]
        
    return res
    
def solution(m, musicinfos):
    res = []
    
    m = trans(m)
    for info in musicinfos:
        s, e, title, melody = info.split(',')
        runtime = get_runtime(s, e)
        melody = trans(melody)
        total_melody = get_runtime_melody(runtime, melody)
        if m in total_melody:
            res.append((runtime, title))
    
    if len(res) == 0:
        return "(None)"
    
    return sorted(res, key=lambda x: x[0], reverse=True)[0][1]