def add_time(time, t):
    res = time + t
    res %= 1000
    res %= 100
    
    if res == 60:
        return time + t + 40
    else:
        return time + t
    
def sub_time(time, t):
    if time % 1000 == 0 or time % 100 == 0:
        hour = time / 100 - 1
        return int(hour * 100 + 59)
    else:
        return time - t
    
    
def solution(n, t, m, timetable):
    timetable = sorted([int(t.replace(":", "")) for t in timetable])
    
    start_time, idx = 900, 0
    order = []
    for i in range(n):
        cnt = 0
        for j in range(idx, len(timetable)):
            if timetable[j] > start_time or cnt >= m:
                break
            cnt += 1
        idx += cnt
        # 마지막
        if i == n - 1:
            if cnt < m:
                answer = str(start_time)
            else:
                btime = timetable[idx - 1]
                answer = str(sub_time(btime, 1))
        
        start_time = add_time(start_time, t)
    
    answer = "0"*(4 - len(answer)) + answer
    return answer[:2] + ':' + answer[2:]