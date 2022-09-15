def solution(n, times):
    answer = 1000000001 ** 2
    
    times.sort()
    left = times[0]
    right = n * times[-1]
    
    while left <= right:
        mid = (left + right) // 2
    
        cnt = 0 # mid 시간에 심사할 수 있는 사람 수
        for time in times:
            cnt += (mid // time)
            
        
        if cnt < n:
            left = mid + 1
        else:
            right = mid - 1
            answer = min(answer, mid)
        
    return answer