def solution(N, stages):
    f_stages = [0 for _ in range(N + 1)]  # 스테이지마다 실패 유저 수 표시 (스테이지 - 1 = index)
    f_rates = list()  # (실패율, stage)
    
    for stage in stages:
        f_stages[stage - 1] += 1
    
    total = len(stages) # 총 유저 수
    for i, n in enumerate(f_stages):
        if total == 0:
            f_rates.append((0.0, i + 1))
        else:
            f_rates.append((float(n) / total, i + 1)) 
        total -= f_stages[i]
        if i == (N - 1):
            break
    
    f_rates = sorted(f_rates, key=lambda f_rate: f_rate[0], reverse=True)
    answer = [stage[1] for stage in f_rates]
        
    return answer