def get_time(time):
    hour, minute, second = time.split(':')
    hour = int(hour) * 3600
    minute = int(minute) * 60
    second, ms = second.split('.')
    second = int(second)
    ms = int(ms)
    
    return (hour + minute + second) * 1000 + ms
    
def get_start_time(endTime, t):
    t = int(float(t[:-1]) * 1000)
    
    return endTime - t + 1

def solution(lines):
    answer = 0
    start_time = []
    end_time = []
    
    for t in lines:
        _, S, T = t.split(' ')
        end_time.append(get_time(S))
        start_time.append(get_start_time(end_time[-1], T))
    
    for i in range(len(lines)):
        cnt = 0
        cur_time = end_time[i]
        
        for j in range(i, len(lines)):
            if cur_time > (start_time[j] - 1000):
                cnt += 1
        answer = max(cnt, answer)
    
    return answer